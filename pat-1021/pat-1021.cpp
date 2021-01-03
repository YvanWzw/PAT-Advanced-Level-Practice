//1021 Deepest Root(25分)
//A graph which is connected and acyclic can be considered a tree.The height of the tree depends on the selected root.Now you are supposed to find the root that results in a highest tree.Such a root is called the deepest root.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains a positive integer N(≤10
//	​4
//	​​) which is the number of nodes, and hence the nodes are numbered from 1 to N.Then N−1 lines follow, each describes an edge by given the two adjacent nodes' numbers.
//
//	Output Specification :
//For each test case, print each of the deepest roots in a line.If such a root is not unique, print them in increasing order of their numbers.In case that the given graph is not a tree, print Error : K components where K is the number of connected components in the graph.
//
//Sample Input 1 :
//	5
//	1 2
//	1 3
//	1 4
//	2 5
//	Sample Output 1:
//3
//4
//5
//Sample Input 2 :
//	5
//	1 3
//	1 4
//	2 5
//	3 4
//	Sample Output 2:
//Error: 2 components


//思路：
//1.是否是连通图
//2.是否有循环
//以上两点可以通过hasVisit数组来处理：如果遍历后有数组值为0则为非连通图，如果遍历时（bfs）遍历到被访问过的节点则有循环
//3.若非树，则有几部分连通组成
//由1开始遍历一遍检查是否有未被访问过的部分，若有，则以未被访问过的部分进行遍历（需要有第二个临时数组），直至第一个hasVisit数组全被访问为止，计算循环次数count
//4.若为树，则求最深根
//使用bfs（即层次遍历），使用一个临时向量存储各节点层次，使用一个临时变量存储最大层次，使用一个向量存储答案根


#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
using namespace std;

int N = 0;
map<unsigned short, vector<unsigned short>> graph;
int returnCode = 0;
unsigned short maxLevel = 0;
unsigned short maxPart = 1;

int bfs(unsigned short current, bool* hasVisit, queue<unsigned short> nextVisit, queue<unsigned short> level, unsigned short part)
{
	unsigned short currentLevel = level.front();
	level.pop();
	if (currentLevel > maxLevel)
	{
		maxLevel = currentLevel;
		returnCode = 1;//maxLevel has been changed
	}
	else if(currentLevel == maxLevel)
		returnCode = 2;
	if (part > maxPart)
		maxPart = part;
	hasVisit[current] = true;
	if (!graph[current].empty())
	{
		vector<unsigned short> vec = graph[current];
		for (int i = 0; i < vec.size(); i++)
		{
			if (!hasVisit[vec[i]])
			{
				nextVisit.push(vec[i]);
				level.push(currentLevel + 1);
			}
			else
			{//if two sites connect not each other and visit a site which has been visited, it's cyclic
				bool flag = false;
				unsigned short doubtSite = vec[i];
				for (int j = 0; j < graph[doubtSite].size(); j++)
				{
					if (graph[doubtSite][j] == current)
						flag = true;
				}
				if (!flag)
					returnCode = -1;//ERROR:CYCLIC
			}

		}
	}

	if (!nextVisit.empty())
	{
		unsigned short next = nextVisit.front();
		nextVisit.pop();
		bfs(next, hasVisit, nextVisit, level, part);

	}
	else
	{
		bool flag = false;
		for (unsigned short i = 1; i <= N; i++)
		{
			if (!hasVisit[i])
			{
				flag = true;
				returnCode = -2;//ERROR:UNCONNECTED
				level.push(0);
				bfs(i, hasVisit, nextVisit, level, part + 1);
			}
		}
		//search finish
		if (!flag)
		{
			return returnCode;
		}
	}
	return returnCode;
}

int main()
{
	//input start
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		unsigned short temp = 0;
		unsigned short temp2 = 0;
		scanf_s("%hu", &temp);
		scanf_s("%hu", &temp2);
		graph[temp].push_back(temp2);
		graph[temp2].push_back(temp);
	}
	//input end

	//process and output start
	vector<unsigned short> ans;
	for (unsigned short i = 1; i <= N; i++)
	{
		returnCode = 0;
		bool* hasVisit = new bool[N + 1];
		queue<unsigned short> nextVisit;
		queue<unsigned short> level;
		level.push(0);
		int code = bfs(i, hasVisit, nextVisit, level, 1);
		if (code < 0)//if incur error, only need search once
		{
			cout << "Error: " << maxPart << " components";
			break;
		}
		else if (code == 2)//maxlevel has not been changed
		{
			ans.push_back(i);
		}
		else if (code == 1)//maxlevel has been changed
		{
			ans.clear();
			ans.push_back(i);
		}
		delete[] hasVisit;
	}
	//process and output end

	//output start
	if (!ans.empty())
	{
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i];
			if (i != ans.size() - 1)
				cout << endl;
		}
	}
	//output end



	return 0;

}