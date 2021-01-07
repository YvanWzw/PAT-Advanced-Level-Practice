//1026 Table Tennis(30分)
//A table tennis club has N tables available to the public.The tables are numbered from 1 to N.For any pair of players, if there are some tables open when they arrive, they will be assigned to the available table with the smallest number.If all the tables are occupied, they will have to wait in a queue.It is assumed that every pair of players can play for at most 2 hours.
//
//Your job is to count for everyone in queue their waiting time, and for each table the number of players it has served for the day.
//
//One thing that makes this procedure a bit complicated is that the club reserves some tables for their VIP members.When a VIP table is open, the first VIP pair in the queue will have the privilege to take it.However, if there is no VIP in the queue, the next pair of players can take it.On the other hand, if when it is the turn of a VIP pair, yet no VIP table is available, they can be assigned as any ordinary players.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains an integer N(≤10000) - the total number of pairs of players.Then N lines follow, each contains 2 times and a VIP tag : HH:MM:SS - the arriving time, P - the playing time in minutes of a pair of players, and tag - which is 1 if they hold a VIP card, or 0 if not.It is guaranteed that the arriving time is between 08 : 00 : 00 and 21 : 00 : 00 while the club is open.It is assumed that no two customers arrives at the same time.Following the players' info, there are 2 positive integers: K (≤100) - the number of tables, and M (< K) - the number of VIP tables. The last line contains M table numbers.
//
//Output Specification :
//For each test case, first print the arriving time, serving timeand the waiting time for each pair of players in the format shown by the sample.Then print in a line the number of players served by each table.Notice that the output must be listed in chronological order of the serving time.The waiting time must be rounded up to an integer minute(s).If one cannot get a table before the closing time, their information must NOT be printed.
//
//Sample Input :
//9
//20 : 52 : 00 10 0
//08 : 00 : 00 20 0
//08 : 02 : 00 30 0
//20 : 51 : 00 10 0
//08 : 10 : 00 5 0
//08 : 12 : 00 10 1
//20 : 50 : 00 10 0
//08 : 01 : 30 15 1
//20 : 53 : 00 10 1
//3 1
//2
//Sample Output :
//08 : 00 : 00 08 : 00 : 00 0
//08 : 01 : 30 08 : 01 : 30 0
//08 : 02 : 00 08 : 02 : 00 0
//08 : 12 : 00 08 : 16 : 30 5
//08 : 10 : 00 08 : 20 : 00 10
//20 : 50 : 00 20 : 50 : 00 0
//20 : 51 : 00 20 : 51 : 00 0
//20 : 52 : 00 20 : 52 : 00 0
//3 3 2

//思路：
//1.到达时间是无序的，所以必须要排序
//2.需要有个CLASS
//3.需要有额外的结构来存储VIP客户
//4.注意时间是否超过9点（到达时间 + 服务时间）
//5.需要有数组存储每桌服务人数
//
//难点在于VIP客户的插队上
//最简单的方法就是以分钟为单位遍历一天，从而模拟一天的情形，但太浪费时间
//第二种方法则要额外存储VIP客户
//
//注意的是在没VIP桌子有普通桌子的情况下可以将VIP客户安排到普通桌子上
//在没VIP客户但有普通用户排队的情况下可以将普通用户安排到VIP桌子上
//在有普通用户和VIP用户排队的情况下当有普通桌子空出来时优先安排最早排队用户
//
//一天最多有10000用户 最多100张桌子 所以如果n ^ 2的话很可能超时，另外输入输出不得不用C
//
//先按到达时间排序，然后开始遍历模拟，设个bool数组来表示桌子是否空缺，为减少遍历再设个int变量来判断当前有多少空缺的桌子数和空缺的vip桌子数
//当桌子正常供应时不作其它处理，一旦当桌子发生紧缺时进入IF分支（在有下一张桌子空出的时候是否有VIP用户到达）
//这里引出了另一个难点：如何判断桌子时候有空出。可以考虑在遍历时候设一个时间，桌子那边不能用bool，需要存储结束时间，那么是否有空缺桌子的INT没有太大意义了
//只有VIP桌子空出来时才需要考虑VIP用户的插队

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string.h>
using namespace std;

class tim
{
public:
	short hour;
	short minute;
	short second;

	bool operator >(const tim& t1) const
	{
		if (hour != t1.hour)
			return hour > t1.hour;
		else
		{
			if (minute != t1.minute)
				return minute > t1.minute;
			else
			{
				return second > t1.second;
			}
		}
	}

	bool equal(const tim& t1) const
	{
		return t1.hour == hour && t1.minute == minute && t1.second == second;
	}

	int subTime(tim t)
	{
		int min = 0;
		int sec = 0;
		tim newTim;
		newTim.hour = hour;
		newTim.minute = minute;
		newTim.second = second;
		newTim.hour -= t.hour;
		newTim.minute -= t.minute;
		newTim.second -= t.second;
		sec = newTim.hour * 3600 + newTim.minute * 60 + newTim.second;
		min = sec / 60;
		if (sec%60>=30)
			min++;
		return min;
	}

	tim addMinute(unsigned short min)
	{
		tim newTim;
		newTim.hour = hour;
		newTim.minute = minute;
		newTim.second = second;
		newTim.minute += min;
		if (newTim.minute >= 60)
		{
			newTim.minute -= 60;
			newTim.hour++;
		}
		return newTim;
	}
};

class info
{
public:
	tim arriveTime;
	unsigned int gameTime;
	bool isVip;

	bool operator <(const info& inf)const
	{
		return inf.arriveTime > arriveTime;
	}
};

class result
{
public:
	tim arriveTime;
	tim serveTime;
	int waitMin;

	bool operator <(const result& res)const
	{
		return res.serveTime > serveTime;
	}
};


int main()
{
	int N = 0;
	cin >> N;
	vector<info> vec;
	vector<result> res;
	for (int i = 0; i < N; i++)
	{
		info li;
		tim arr;
		char t[9];
		scanf_s("%s", t, 9);
		char temp[3];
		strncpy_s(temp, t, 2);
		arr.hour = atoi(temp);
		strncpy_s(temp, t + 3, 2);
		arr.minute = atoi(temp);
		strncpy_s(temp, t + 6, 2);
		arr.second = atoi(temp);
		li.arriveTime = arr;
		int gameTime = 0;
		scanf_s("%d", &gameTime, 3);
		if (gameTime > 120)
			gameTime = 120;
		li.gameTime = gameTime;
		unsigned short vip = 0;
		scanf_s("%hu", &vip, 1);
		li.isVip = vip == 1 ? true : false;
		vec.push_back(li);
	}
	int tableNum = 0;
	int vipTableNum = 0;
	int* vipTable = new int[vipTableNum];
	cin >> tableNum >> vipTableNum;
	for (int i = 0; i < vipTableNum; i++)
	{
		int temp = 0;
		cin >> temp;
		vipTable[i] = temp - 1;
	}

	sort(vec.begin(), vec.end());
	tim* table = new tim[tableNum];
	int* tableSer = new int[tableNum] {0};
	cout << tableSer[0];

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].gameTime == 0)
			continue;
		if (vec[i].arriveTime.hour >= 21)//不接受21点之后的客户！
			break;
		tim currentTime = vec[i].arriveTime;
		if (currentTime.hour < 8)
		{
			currentTime.hour = 8;
			currentTime.minute = 0;
			currentTime.second = 0;
		}
		bool isVip = vec[i].isVip;
		bool isEmpty = false;
		int tableNo = -1;
		if (isVip)
		{
			for (int j = 0; j < vipTableNum; j++)
			{
				if (currentTime > table[vipTable[j]]||currentTime.equal(table[vipTable[j]]))
				{
					isEmpty = true;
					tableNo = vipTable[j];
					break;
				}
			}

		}
		if (!isEmpty)//不是vip isEmpty就一定为false 普通用户此处也为false
		{
			for (int j = 0; j < tableNum; j++)
			{
				if (currentTime > table[j] || tableSer[j] == 0)
				{
					isEmpty = true;
					tableNo = j;
					break;
				}
			}
		}


		if (isEmpty)
		{
			tableSer[tableNo]++;
			table[tableNo] = currentTime.addMinute(vec[i].gameTime);
			result re;
			re.arriveTime = vec[i].arriveTime;
			re.serveTime = currentTime;
			re.waitMin = currentTime.subTime(vec[i].arriveTime);
			res.push_back(re);
		}
		else
		{
			//排队状态了,找到最早结束的那个，如果是VIP桌子就根据结束时间遍历结束时间前有没有VIP排队，有就让VIP进，没有就让排队的第一个进；非VIP桌子根据排队的第一个进
			tim nextEnd = table[0];
			int nextTable = 0;
			bool flag = false;
			for (int j = 0; j < tableNum; j++)
			{
				if (nextEnd > table[j])
				{
					nextEnd = table[j];
					nextTable = j;
				}
				if (nextEnd.equal(table[j]))
				{
					for (int k = 0; k < vipTableNum; k++)
					{
						if (vipTable[k] == j)
						{
							nextEnd = table[j];
							nextTable = j;
							flag = true;
							break;
						}
					}
					if (flag)
						break;
				}
			}
			if (nextEnd.hour >= 21)
				break;

			if (!flag)
			{
				for (int j = 0; j < vipTableNum; j++)
				{
					if (vipTable[j] == nextTable)
					{
						flag = true;
						break;
					}
				}
			}


			bool temp = false;
			if (flag)
			{
				//这是一个VIP桌子！
				for (int j = i; j < vec.size(); j++)
				{
					//只遍历nextEnd之前到达的用户
					if (vec[j].arriveTime > nextEnd)
						break;
					if (vec[j].arriveTime.hour >= 21)//不接受21点之后的客户！
						break;
					if (vec[j].gameTime == 0)
						continue;
					if (vec[j].isVip)
					{
						temp = true;
						tableSer[nextTable]++;
						table[nextTable] = nextEnd.addMinute(vec[j].gameTime);
						result re;
						re.arriveTime = vec[j].arriveTime;
						re.serveTime = nextEnd;
						re.waitMin = nextEnd.subTime(vec[j].arriveTime);
						res.push_back(re);
						vec[j].gameTime = 0;//以gameTime为0来标记该VIP用户已经被服务了
						i--;
						break;
					}

				}
			}
			if (!temp)//即没有找到VIP用户或者不是张VIP桌子，即找排队的第一个
			{
				tableSer[nextTable]++;
				table[nextTable] = nextEnd.addMinute(vec[i].gameTime);
				result re;
				re.arriveTime = vec[i].arriveTime;
				re.serveTime = nextEnd;
				re.waitMin = nextEnd.subTime(vec[i].arriveTime);
				res.push_back(re);
			}

		}

	}

	stable_sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		cout << setw(2) << setfill('0') << res[i].arriveTime.hour;
		cout << ":";
		cout << setw(2) << setfill('0') << res[i].arriveTime.minute;
		cout << ":";
		cout << setw(2) << setfill('0') << res[i].arriveTime.second;
		cout << " ";
		cout << setw(2) << setfill('0') << res[i].serveTime.hour;
		cout << ":";
		cout << setw(2) << setfill('0') << res[i].serveTime.minute;
		cout << ":";
		cout << setw(2) << setfill('0') << res[i].serveTime.second;
		cout << " ";
		cout << res[i].waitMin << endl;
	}

	for (int i = 0; i < tableNum; i++)
	{
		cout << tableSer[i];
		if (i != tableNum - 1)
			cout << " ";
	}


	delete[] table;
	delete[] tableSer;



	return 0;
}