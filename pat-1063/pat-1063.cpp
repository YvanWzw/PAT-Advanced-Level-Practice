//1063 Set Similarity(25point(s))
//Given two sets of integers, the similarity of the sets is defined to be N
//​c
//​​ / N
//​t
//​​ ×100%, where N
//​c
//​​  is the number of distinct common numbers shared by the two sets, and N
//​t
//​​  is the total number of distinct numbers in the two sets.Your job is to calculate the similarity of any given pair of sets.
//
//Input Specification :
//Each input file contains one test case.Each case first gives a positive integer N(≤50) which is the total number of sets.Then N lines follow, each gives a set with a positive M(≤10
//	​4
//	​​) and followed by M integers in the range[0, 10
//	​9
//	​​].After the input of sets, a positive integer K(≤2000) is given, followed by K lines of queries.Each query gives a pair of set numbers(the sets are numbered from 1 to N).All the numbers in a line are separated by a space.
//
//	Output Specification :
//For each query, print in one line the similarity of the sets, in the percentage form accurate up to 1 decimal place.
//
//Sample Input :
//3
//3 99 87 101
//4 87 101 5 87
//7 99 101 18 5 135 18 99
//2
//1 2
//1 3
//Sample Output :
//50.0 %
//33.3 %

#include<iostream>
#include<map>
#include<vector>
#include<iomanip>
#include<set>
using namespace std;
int main()
{
	vector<set<int>> vec;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf_s("%d", &num);
		set<int> se;
		for (int j = 0; j < num; j++)
		{
			int tem;
			scanf_s("%d", &tem);
			se.insert(tem);
		}
		vec.push_back(se);
	}

	vector<double> ans;
	cin >> N;
	for (int i = 0; i < N; i++)
	{

		int a, b;
		cin >> a >> b;
		int total = vec[a - 1].size();
		int common = 0;
		for (auto it : vec[b - 1])
		{
			if (vec[a-1].find(it)==vec[a-1].end())
				total++;
			else
				common++;
		}
		double tem = ((double)common / total) * 100;
		ans.push_back(tem);
	}

	for (auto it : ans)
	{
		printf("%.1f%%\n", it);
	}


	return 0;
}