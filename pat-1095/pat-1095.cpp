//1095 Cars on Campus(30 ·Ö)
//Zhejiang University has 8 campuses and a lot of gates.From each gate we can collect the in / out times and the plate numbers of the cars crossing the gate.Now with all the information available, you are supposed to tell, at any specific time point, the number of cars parking on campus, and at the end of the day find the cars that have parked for the longest time period.
//
//Input Specification :
//Each input file contains one test case.Each case starts with two positive integers N(¡Ü10
//	4
//), the number of records, and K(¡Ü8¡Á10
//	4
//) the number of queries.Then N lines follow, each gives a record in the format :
//
//plate_number hh : mm:ss status
//where plate_number is a string of 7 English capital letters or 1 - digit numbers; hh:mm:ss represents the time point in a day by hour : minute:second, with the earliest time being 00 : 00 : 00 and the latest 23 : 59 : 59;and status is either in or out.
//
//Note that all times will be within a single day.Each in record is paired with the chronologically next record for the same car provided it is an out record.Any in records that are not paired with an out record are ignored, as are out records not paired with an in record.It is guaranteed that at least one car is well paired in the input, and no car is both inand out at the same moment.Times are recorded using a 24 - hour clock.
//
//Then K lines of queries follow, each gives a time point in the format hh : mm:ss.Note : the queries are given in ascending order of the times.
//
//Output Specification :
//For each query, output in a line the total number of cars parking on campus.The last line of output is supposed to give the plate number of the car that has parked for the longest time period, and the corresponding time length.If such a car is not unique, then output all of their plate numbers in a line in alphabetical order, separated by a space.
//
//Sample Input :
//16 7
//JH007BD 18 : 00 : 01 in
//ZD00001 11 : 30 : 08 out
//DB8888A 13:00 : 00 out
//ZA3Q625 23 : 59 : 50 out
//ZA133CH 10 : 23 : 00 in
//ZD00001 04 : 09 : 59 in
//JH007BD 05 : 09 : 59 in
//ZA3Q625 11 : 42 : 01 out
//JH007BD 05 : 10 : 33 in
//ZA3Q625 06 : 30 : 50 in
//JH007BD 12 : 23 : 42 out
//ZA3Q625 23 : 55 : 00 in
//JH007BD 12 : 24 : 23 out
//ZA133CH 17 : 11 : 22 out
//JH007BD 18 : 07 : 01 out
//DB8888A 06 : 30 : 50 in
//05 : 10 : 00
//06 : 30 : 50
//11 : 00 : 00
//12 : 23 : 42
//14 : 00 : 00
//18 : 00 : 00
//23 : 59 : 00
//Sample Output :
//1
//4
//5
//2
//1
//0
//1
//JH007BD ZD00001 07:20 : 09

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<sstream>
#include<iomanip>
using namespace std;
class record
{
public:
	string number;
	string timex;
	bool status;//false=in;true=out
	bool operator< (const record& a)
	{
		if (atoi(timex.substr(0, 2).c_str()) != atoi(a.timex.substr(0, 2).c_str()))
			return atoi(timex.substr(0, 2).c_str()) < atoi(a.timex.substr(0, 2).c_str());
		else if (atoi(timex.substr(3, 2).c_str()) != atoi(a.timex.substr(3, 2).c_str()))
			return atoi(timex.substr(3, 2).c_str()) < atoi(a.timex.substr(3, 2).c_str());
		else
			return atoi(timex.substr(6, 2).c_str()) < atoi(a.timex.substr(6, 2).c_str());
	}
};

int trans(string a)
{
	int hh = atoi(a.substr(0, 2).c_str()) * 60 * 60;
	int mm = atoi(a.substr(3, 2).c_str()) * 60;
	int ss = atoi(a.substr(6, 2).c_str());
	return hh + mm + ss;
}

string trans2(int a)
{
	string hh = to_string(a / 3600);
	a %= 3600;
	string mm = to_string(a / 60);
	a %= 60;
	string ss = to_string(a);
	stringstream sxs;
	sxs << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << ":" << setw(2) << setfill('0') << ss;
	return sxs.str();
}

string sub(string a, string b)
{
	return trans2(trans(a) - trans(b));
}

string add(string a, string b)
{
	return trans2(trans(b) + trans(a));
}

int main()
{
	std::ios::sync_with_stdio(false);
	int N, K;
	vector<record> vec;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		record temp;
		string sta;
		cin >> temp.number >> temp.timex >> sta;
		temp.status = sta == "in" ? false : true;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end());

	vector<string> test;
	for (int i = 0; i < K; i++)
	{
		string temp;
		cin >> temp;
		test.push_back(temp);
	}

	map<string, record> deal;
	vector<record> dvec;
	for (auto i : vec)
	{
		if (i.status == false)
			deal[i.number] = i;
		else
		{
			if (deal.find(i.number) != deal.end())
			{
				if (deal[i.number].status == false)
				{
					dvec.push_back(i);
					dvec.push_back(deal[i.number]);
					deal.erase(i.number);
				}
			}

		}
	}

	sort(dvec.begin(), dvec.end());

	int count = 0;
	map<string, string> mp1;
	map<string, string> mp2;
	vector<int> ans;
	vector<string> maxT;
	string maxTime = "00:00:00";
	int cnt = 0;
	if (dvec.size() > 0)
	{
		while (trans(dvec[0].timex) > trans(test[cnt]))
		{
			ans.push_back(0);
			cnt++;
			if (cnt == K)
				break;
		}
	}
	for (auto i : dvec)
	{
		if (cnt < K)
			while (trans(i.timex) > trans(test[cnt]))
			{
				ans.push_back(count);
				cnt++;
				if (cnt == K)
					break;
			}
		if (i.status == false)
		{
			count++;
			mp1[i.number] = i.timex;
		}
		else
		{
			count--;
			mp2[i.number] = mp2.find(i.number) == mp2.end() ? sub(i.timex, mp1[i.number]) : add(mp2[i.number], sub(i.timex, mp1[i.number]));
			if (mp2[i.number] == maxTime)
				maxT.push_back(i.number);
			else if (trans(mp2[i.number]) > trans(maxTime))
			{
				maxT.clear();
				maxT.push_back(i.number);
				maxTime = mp2[i.number];
			}
		}
	}

	if (cnt < K)
	{
		for (int i = 0; i < K - cnt; i++)
			ans.push_back(count);
	}
	sort(maxT.begin(), maxT.end());
	for (auto i : ans)
		cout << i << endl;
	for (auto i : maxT)
		cout << i << " ";
	if (maxT.size() != 0)
		cout << maxTime;


	return 0;
}