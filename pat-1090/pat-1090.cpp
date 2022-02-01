﻿//1090 Highest Price in Supply Chain(25 分)
//A supply chain is a network of retailers（零售商）, distributors（经销商）, and suppliers（供应商）-- everyone involved in moving a product from supplier to customer.
//
//Starting from one root supplier, everyone on the chain buys products from one's supplier in a price P and sell or distribute them in a price that is r% higher than P. It is assumed that each member in the supply chain has exactly one supplier except the root supplier, and there is no supply cycle.
//
//Now given a supply chain, you are supposed to tell the highest price we can expect from some retailers.
//
//Input Specification :
//Each input file contains one test case.For each case, The first line contains three positive numbers : N(≤10
//	5
//), the total number of the members in the supply chain(and hence they are numbered from 0 to N−1); P, the price given by the root supplier;and r, the percentage rate of price increment for each distributor or retailer.Then the next line contains N numbers, each number S
//i
//​
//is the index of the supplier for the i - th member.S
//root
//​
//for the root supplier is defined to be −1.All the numbers in a line are separated by a space.
//
//Output Specification :
//For each test case, print in one line the highest price we can expect from some retailers, accurate up to 2 decimal places, and the number of retailers that sell at the highest price.There must be one space between the two numbers.It is guaranteed that the price will not exceed 10
//10
//.
//
//Sample Input :
//9 1.80 1.00
//1 5 4 4 - 1 4 5 3 6
//Sample Output :
//1.85 2

#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
vector<int>* node;
int* level;
int* parent;
//void find(int now, int tar)
//{
//	if (node[now] == -1)
//		return;
//	else
//	{
//		level[tar]++;
//		find(node[now], tar);
//	}
//}

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
		int temp;
		cin >> temp;
		parent[i] = temp;
		if (temp != -1)
		{
			node[temp].push_back(i);
		
		}
		else
			root = i;
	}

	search(root);

	int maxId = 0;
	int num = 1;
	for (int i = 1; i < n; i++)
	{
		if (level[i] > level[maxId])
		{
			maxId = i;
			num = 1;
		}
		else if (level[i] == level[maxId])
			num++;
	}
	for (int i = 0; i < level[maxId] - 1; i++)
	{
		pri = pri + pri * p * 0.01;
	}
	cout << fixed << setprecision(2) << pri << " " << num;

	delete[] level;
	delete[] node;
	return 0;
}