//1121 Damn Single(25 分)
//"Damn Single (单身狗)" is the Chinese nickname for someone who is being single.You are supposed to find those who are alone in a big party, so they can be taken care of.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line gives a positive integer N(≤ 50, 000), the total number of couples.Then N lines of the couples follow, each gives a couple of ID's which are 5-digit numbers (i.e. from 00000 to 99999). After the list of couples, there is a positive integer M (≤ 10,000) followed by M ID's of the party guests.The numbers are separated by spaces.It is guaranteed that nobody is having bigamous marriage(重婚) or dangling with more than one companion.
//
//Output Specification :
//First print in a line the total number of lonely guests.Then in the next line, print their ID's in increasing order. The numbers must be separated by exactly 1 space, and there must be no extra space at the end of the line.
//
//Sample Input :
//3
//11111 22222
//33333 44444
//55555 66666
//7
//55555 44444 10000 88888 22222 11111 23333
//Sample Output :
//5
//10000 23333 44444 55555 88888

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	map<string, bool> nds;
	map<string, string> wd;
	for (int i = 0; i <  N; i++)
	{
		string temp1,temp2;
		cin >> temp1 >> temp2;
		wd[temp1] = temp2;
		wd[temp2] = temp1;
	}

	int K;
	cin >> K;
	vector<string> res;
	for (int i = 0; i < K; i++)
	{
		string temp;
		cin >> temp;
		if (nds.find(wd[temp]) != nds.end())
		{
			if (nds[wd[temp]] == true)
			{
				nds.erase(wd[temp]);
			}
		}
		else
		{
			nds[temp] = true;
		}
	}
	for (auto i : nds)
	{
		res.push_back(i.first);
	}

	sort(res.begin(), res.end());
	cout << res.size();
	res.size() == 0 ? cout << "" : cout << endl;
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1)
			cout << " ";
	}

	return 0;
}