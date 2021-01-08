//1030 Travel Plan(30分)
//A traveler's map gives the distances between cities along the highways, together with the cost of each highway. Now you are supposed to write a program to help a traveler to decide the shortest path between his/her starting city and the destination. If such a shortest path is not unique, you are supposed to output the one with the minimum cost, which is guaranteed to be unique.
//
//Input Specification :
//Each input file contains one test case.Each case starts with a line containing 4 positive integers N, M, S, and D, where N(≤500) is the number of cities(and hence the cities are numbered from 0 to N−1); M is the number of highways; Sand D are the startingand the destination cities, respectively.Then M lines follow, each provides the information of a highway, in the format :
//
//City1 City2 Distance Cost
//where the numbers are all integers no more than 500, and are separated by a space.
//
//Output Specification :
//For each test case, print in one line the cities along the shortest path from the starting point to the destination, followed by the total distanceand the total cost of the path.The numbers must be separated by a spaceand there must be no extra space at the end of output.
//
//Sample Input :
//4 5 0 3
//0 1 1 20
//1 3 2 30
//0 3 4 10
//0 2 2 20
//2 3 1 20
//Sample Output :
//0 2 3 3 40

#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

class highway
{
public:
	int destination;
	int distance;
	int cost;
};


int M, N, S, D;
map<int, vector<highway>> highw;
int minDis = 0x7fffffff;
int minCost = 0x7fffffff;
vector<int> ans;

void dfs(int current, int dis, int cost, vector<int> road, bool* isVisit)
{
	road.push_back(current);
	isVisit[current] = true;
	if (dis > minDis)
		return;
	if (current == D)
	{
		if (dis < minDis)
		{
			minDis = dis;
			minCost = cost;
			ans = road;
			return;
		}
		else if (dis == minDis)
		{
			if (cost < minCost)
			{
				minCost = cost;
				ans = road;
				return;
			}
		}
	}
	vector<highway> vec = highw[current];
	for (int i = 0; i < vec.size(); i++)
	{
		if (!isVisit[vec[i].destination])
		{
			bool isVis[501] = { false };
			copy(isVisit, isVisit + 501, isVis);
			dfs(vec[i].destination, dis + vec[i].distance, cost + vec[i].cost, road, isVis);
		}
	}
}

int main()
{
	cin >> M >> N >> S >> D;
	for (int i = 0; i < N; i++)
	{
		highway hw;
		int city1, city2;
		cin >> city1 >> city2 >> hw.distance >> hw.cost;
		hw.destination = city1;
		highw[city2].push_back(hw);
		hw.destination = city2;
		highw[city1].push_back(hw);
	}


	bool isVisit[501] = { false };
	vector<int> road;
	dfs(S, 0, 0, road, isVisit);

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << minDis << " " << minCost;



	return 0;
}