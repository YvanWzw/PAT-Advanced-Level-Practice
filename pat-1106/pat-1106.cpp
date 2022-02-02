//1106 Lowest Price in Supply Chain(25 分)
//A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
//
//Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. Only the retailers will face the customers. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
//
//Now given a supply chain, you are supposed to tell the lowest price a customer can expect from some retailers.
//
//Input Specification :
//Each input file contains one test case.For each case, The first line contains three positive numbers : N(≤10
//	5
//), the total number of the members in the supply chain(and hence their ID's are numbered from 0 to N−1, and the root supplier's ID is 0); P, the price given by the root supplier;and r, the percentage rate of price increment for each distributor or retailer.Then N lines follow, each describes a distributor or retailer in the following format :
//
//K
//i
//​
//ID[1] ID[2] ... ID[K
//i
//​
//]
//
//	where in the i - th line, K
//		i
//		​
//		is the total number of distributors or retailers who receive products from supplier i, and is then followed by the ID's of these distributors or retailers. K 
//		j
//		​
//		being 0 means that the j - th member is a retailer.All the numbers in a line are separated by a space.
//
//		Output Specification :
//	For each test case, print in one line the lowest price we can expect from some retailers, accurate up to 4 decimal places, and the number of retailers that sell at the lowest price.There must be one space between the two numbers.It is guaranteed that the all the prices will not exceed 10
//		10
//		.
//
//		Sample Input :
//	10 1.80 1.00
//		3 2 3 5
//		1 9
//		1 4
//		1 7
//		0
//		2 6 1
//		1 8
//		0
//		0
//		0
//		Sample Output :
//	1.8362 2

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
vector<int>* node;
int* level;
int* parent;
void search(int root)
{
	if (parent[root] != -1)
		level[root] = level[parent[root]] + 1;
	for (int i = 0; i < node[root].size(); i++)
	{
		search(node[root][i]);
	}
}

int main()
{
	int n;
	double pri, p;
	cin >> n >> pri >> p;
	node = new vector<int>[n];
	level = new int[n];
	parent = new int[n];
	int root = 0;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp;
		node[i] = temp;
	}
	for (int i = 0; i < n; i++)
	{

		level[i] = 1;
		int num;
		cin >> num;
		for (int j = 0; j < num; j++)
		{
			int temp;
			cin >> temp;
			parent[temp] = i;
			node[i].push_back(temp);
		}
	}
	parent[root] = -1;

	search(root);

	int minId = -1;
	int num = 1;
	for (int i = 0; i < n; i++)
	{
		if (node[i].empty())
		{
			if (minId == -1)
				minId = i;
			else
			{
				if (level[i] < level[minId])
				{
					minId = i;
					num = 1;
				}
				else if(level[i]==level[minId])
				{
					num++;
				}
			}

		}
	}
	for (int i = 0; i < level[minId] - 1; i++)
	{
		pri = pri + pri * p * 0.01;
	}
	cout << fixed << setprecision(4) << pri << " " << num;

	delete[] level;
	delete[] node;
	return 0;
}