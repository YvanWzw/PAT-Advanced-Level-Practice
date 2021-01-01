//1018 Public Bike Management(30分)
//There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world.One may rent a bike at any station and return it to any other stations in the city.
//
//The Public Bike Management Center(PBMC) keeps monitoring the real - time capacity of all the stations.A station is said to be in perfect condition if it is exactly half - full.If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect.And more, all the stations on the way will be adjusted as well.
//
//When a problem station is reported, PBMC will always choose the shortest path to reach that station.If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.
//
//
//
//The above figure illustrates an example.The stations are represented by verticesand the roads correspond to the edges.The number on an edge is the time taken to reach one end station from another.The number written inside a vertex S is the current number of bikes stored at S.Given that the maximum capacity of each station is 10. To solve the problem at S
//​3
//​​, we have 2 different shortest paths :
//
//PBMC->S
//​1
//​​->S
//​3
//​​.In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S
//​1
//​​ and then take 5 bikes to S
//​3
//​​, so that both stations will be in perfect conditions.
//
//PBMC->S
//​2
//​​->S
//​3
//​​.This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains 4 numbers: C
//	​max
//	​​(≤100), always an even number, is the maximum capacity of each station; N(≤500), the total number of stations; S
//	​p
//	​​, the index of the problem station(the stations are numbered from 1 to N, and PBMC is represented by the vertex 0);and M, the number of roads.The second line contains N non - negative numbers C
//	​i
//	​​(i = 1, ⋯, N) where each C
//	​i
//	​​  is the current number of bikes at S
//	​i
//	​​  respectively.Then M lines follow, each contains 3 numbers: S
//	​i
//	​​, S
//	​j
//	​​, and T
//	​ij
//	​​  which describe the time T
//	​ij
//	​​  taken to move betwen stations S
//	​i
//	​​and S
//	​j
//	​​.All the numbers in a line are separated by a space.
//
//	Output Specification :
//																					   For each test case, print your results in one line.First output the number of bikes that PBMC must send.Then after one space, output the path in the format : 0− > S
//																						   ​1
//																						   ​​ − > ⋯− > S
//																						   ​p
//																						   ​​.Finally after another space, output the number of bikes that we must take back to PBMC after the condition of S
//																						   ​p
//																						   ​​  is adjusted to perfect.
//
//																						   Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC.The judge's data guarantee that such a path is unique.
//
//																						   Sample Input :
//																					   10 3 3 5
//																						   6 7 0
//																						   0 1 1
//																						   0 2 1
//																						   0 3 3
//																						   1 3 1
//																						   2 3 1
//																						   Sample Output :
//																					   3 0->2->3 0


//
//题目概要：
//1每个站点的自行车数恰好为最大容量Cmax的二分之一时为PERFECT状态
//2当每个站点的自行车为空或满时PBMC会对该站点进行调整
//2.1PBMC会寻找前往该站点的最近路径
//2.2当不止一条最近路径时会寻找需要携带自行车最少的路径
//
//INPUT :
//
//Cmax：int <= 100 even
//N：int <= 500 the total number of the stations
//Sp：int <= 500 the index of the problem station(from 1 to N and the PBMC is 0)
//M：int  the number of roads
//
//Ci：int(i from 1 to N) the current number of bikes at Si
//
//M lines follow : M is N * (N + 1) / 2 which is the number of edges of the undirected graph
//Si Sj Tij
//
//数据结构：
//short Cmax = 0;
//short N = 0;
//short Sp = 0;
//short M = 0;
//
//short Ci[N] = { 0 };
//
//class Sxy
//{
//public:
//	short Si = 0;
//	short Sj = 0;
//	short Tij = 0;
//}
//
//Sxy* sxy = new Sxy[M];
//(delete[]sxy;)
//
//short perfect = Cmax / 2;
//
//思路：
//1.寻找最短路径且最短路径可能不唯一
//可以考虑浪费一定空间来交换时间：利用数组A[i][j] = t表示代价 0表示不连通（邻接表表示）
//首先已知问题节点Sp以及其自行车数Ci[Sp]，其中Ci[Sp]必为0或Cmax，二者在后面分别对应两种不同情况
//第一个要解决的问题就是寻找到不唯一的最短路径（Dijkstra ? bfs / dfs ? floyd ? ）
//唯一确定的起点与终点、路径不唯一、需要记录每次的路径：使用bfs
//使用bfs时需要一个临时变量minCost来记录当前最小代价，当路径大于minCost时则结束寻找
//将所有满足 = minCost的路径存储到一个vector中
//2.处理vector并寻找携带自行车最少的路径
//当Ci[Sp]为Cmax时：
//寻找路径中<Cmax / 2且其差值最多的路径
//	当Ci[Sp]为0时：
//	寻找路径中>Cmax / 2且其差值最多的路径
//	3.协调二者：
//	初始化两个临时变量larger和lower，每次遍历到一个新节点时，比较节点自行车数与Cmax / 2，若前者大于后者则将差值加入larger中，反正则加入lower中（实际上只需要一个临时变量dif即可）
//	当路径代价相同时比较dif，大者为最终输出的答案
//
//



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Sxy
{
public:
	unsigned short Si = 0;
	unsigned short Sj = 0;
	unsigned short Tij = 0;
};

unsigned short Cmax = 0;
unsigned short N = 0;
unsigned short Sp = 0;
unsigned short M = 0;
unsigned short* Ci;
unsigned short perfect;
unsigned short nt[501][501] = { 0 };
Sxy* sxy;
queue<unsigned short> answer;
int minCost = -1;
int minRoad = 0x7fffffff;

bool bfs(unsigned short now, queue<unsigned short> roadTemp, bool* hasBfs, int dif, int roadLength, bool type)
{
	//process current site
	hasBfs[now] = true;
	roadTemp.push(now);

	if (now == Sp)
	{
		if (roadLength < minRoad)
		{
			answer = roadTemp;
			minRoad = roadLength;
			minCost = dif;
		}
		else if (roadLength == minRoad && dif > minCost)
		{
			answer = roadTemp;
			minCost = dif;
		}
		return true;
	}

	if (now != 0)
	{
		if (type && Ci[now] > perfect)
		{
			int temp = Ci[now] - perfect;
			dif += temp;
		}
		else if (!type && Ci[now] < perfect)
		{
			int temp = perfect - Ci[now];
			dif += temp;
		}
	}

	for (unsigned short i = 1; i < 501; i++)
	{
		if (nt[now][i] != 0 && !hasBfs[i])
		{
			bool hasBfs2[501];
			copy(hasBfs, hasBfs+500, std::begin(hasBfs2));
			bfs(i, roadTemp, hasBfs2, dif, roadLength + nt[now][i], type);
		}
	}

	return true;
}

int main()
{
	//input start
	cin >> Cmax >> N >> Sp >> M;

	Ci = new unsigned short[N + 1];
	sxy = new Sxy[M];

	for (unsigned short i = 1; i < N + 1; i++)
	{
		cin >> Ci[i];
	}

	for (unsigned short i = 0; i < M; i++)
	{
		cin >> sxy[i].Si >> sxy[i].Sj >> sxy[i].Tij;
	}

	perfect = Cmax / 2;
	//imput end


	//data process start (邻接表改造)

	for (unsigned short i = 0; i < M; i++)
	{
		nt[sxy[i].Si][sxy[i].Sj] = sxy[i].Tij;
		nt[sxy[i].Sj][sxy[i].Si] = sxy[i].Tij;
	}
	//data process end


	//bfs start
	if (Ci[Sp] == 0)
	{
		bool hasBfs[501] = { false };
		queue<unsigned short> road;
		bfs(0, road, hasBfs, 0, 0, Ci[Sp] == 0 ? true : false);
	}
	//bfs end


	//data process and output start (自行车计算)
	int bike = 0;
	if (Ci[Sp] == 0)
	{
		bike = perfect - minCost;
		if (bike < 0)
			bike = 0;
		cout << bike << " ";
		unsigned short temp = answer.size();
		for (unsigned short i = 0; i < temp; i++)
		{
			cout << answer.front();
			answer.pop();
			if (i != temp - 1)
				cout << "->";
			else
				cout << " ";
		}
		cout << 0;
	}
	else if (Ci[Sp] == Cmax)
	{
		bike = minCost - perfect;
		if (bike < 0)
			bike = 0;
		cout << 0 << " ";
		unsigned short temp = answer.size();
		for (unsigned short i = 0; i < temp; i++)
		{
			cout << answer.front();
			answer.pop();
			if (i != temp - 1)
				cout << "->";
			else
				cout << " ";
		}
		cout << bike;
	}
	//data process and output end

	delete[]Ci;
	delete[]sxy;

}