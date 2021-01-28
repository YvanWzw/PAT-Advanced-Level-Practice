#include<iostream>
using namespace std;
bool isVisited[1001] = { 0 };
bool way[1001][1001] = { 0 };
void dfs(int city, int p)
{
	isVisited[p] = true;
	for (int i = 1; i <= city; i++) 
	{
		if (isVisited[i] == false && way[p][i] == 1) 
		{
			dfs(city, i);
		}
	}
}
int main() 
{
	int cities = 0;
	int highways = 0;
	int concern = 0;
	scanf("%d%d%d", &cities, &highways, &concern);
	int start = 0;
	int end = 0;
	for (int i = 0; i < highways; i++)
	{
		scanf("%d%d", &start, &end);
		way[start][end] = 1;
		way[end][start] = 1;
	}

	for (int i = 0; i < concern; i++)
	{
		for (int j = 0; j < 1001; j++)
			isVisited[j] = false;
		int con = 0;
		scanf("%d", &con);
		isVisited[con] = true;
		int re = 0;
		for (int j = 1; j <= cities; j++)
		{
			if (isVisited[j] == false)
			{
				dfs(cities, j);
				re++;
			}
		}
		cout << re - 1 << endl;
	}
	system("pause");
	return 0;
}