#include<iostream>
using namespace std;
class Node
{
public:
	int id = 0;
	int num = 0;
	int child[100] = { 0 };
	int level = 0;
};
int main()
{
	int m, n;
	cin >> n >> m;
	int id;
	Node *node = new Node[n+1];
	for (int i = 0; i < m; i++)
	{
		cin >> id;
		node[id].id = id;
		cin >> node[id].num;
		for (int j = 0; j < node[id].num; j++)
			cin >> node[id].child[j];
	}

	for (int i = 1; i < n+1; i++)
	{
		for(int j=0;j<node[i].num;j++)
			if (node[node[i].child[j]].id == 0 && node[node[i].child[j]].num == 0)
			{
				node[node[i].child[j]].id = node[i].child[j];
			}
	}

	for (int i = 1; i < n+1; i++)
	{
		for (int j = 0; j < node[i].num; j++)
			node[node[i].child[j]].level = node[i].level + 1;
	}

	int sum = 0;
	int le = 0;
	for (int i = 1; i < n+1; i++)
	{
		if (node[i].level > le)
			le = node[i].level;
	}
	for (int j = 0; j <= le; j++)
	{
		for (int i = 1; i < n+1 ; i++)
		{
			if (node[i].level == j&&node[i].num==0)
				sum++;
		}
		if (j == le)
			cout << sum;
		else
			cout << sum << " ";
		sum = 0;
	}


	//system("pause");
	return 0;
}