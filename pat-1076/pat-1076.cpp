//1076 Forwards on Weibo(30 ·Ö)
//Weibo is known as the Chinese version of Twitter.One user on Weibo may have many followers, and may follow many other users as well.Hence a social network is formed with followers relations.When a user makes a post on Weibo, all his / her followers can view and forward his / her post, which can then be forwarded again by their followers.Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains 2 positive integers : N(¡Ü1000), the number of users;and L(¡Ü6), the number of levels of indirect followers that are counted.Hence it is assumed that all the users are numbered from 1 to N.Then N lines follow, each in the format :
//
//M[i] user_list[i]
//	where M[i](¡Ü100) is the total number of people that user[i] follows;and user_list[i] is a list of the M[i] users that followed by user[i].It is guaranteed that no one can follow oneself.All the numbers are separated by a space.
//
//		Then finally a positive K is given, followed by K UserID's for query.
//
//		Output Specification :
//	For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can trigger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.
//
//		Sample Input :
//	7 3
//		3 2 3 4
//		0
//		2 5 6
//		2 3 1
//		2 3 4
//		1 4
//		1 5
//		2 2 6
//		Sample Output :
//	4
//		5



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node
{
public:
	int num;
	int lev;
};

void bfs(int start, vector<int> followed[], bool isVis[], int& cnt, int level, int maxL, queue<node> que)
{
	if (level > maxL)
	{
		return;
	}
	cnt++;

	for (int next : followed[start])
	{
		if (!isVis[next])
		{
			node nod;
			nod.num = next;
			nod.lev = level + 1;
			que.push(nod);
			isVis[next] = true;
		}
	}
	if (!que.empty())
	{
		int next = que.front().num;
		int lev = que.front().lev;

		que.pop();
		bfs(next, followed, isVis, cnt, lev, maxL, que);
	}

}

int main()
{
	int N, L;
	cin >> N >> L;
	vector<int> followed[1001];
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int temp;
			cin >> temp;
			followed[temp].push_back(i);
		}
	}

	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int cnt = -1;
		bool isVis[1001] = { false };
		int temp;
		cin >> temp;
		queue<node> que;
		isVis[temp] = true;
		bfs(temp, followed, isVis, cnt, 0, L, que);
		cout << cnt;
		if (i != K - 1)
			cout << endl;
	}

	return 0;
}