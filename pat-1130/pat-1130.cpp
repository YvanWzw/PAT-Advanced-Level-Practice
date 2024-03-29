﻿//1130 Infix Expression(25 分)
//Given a syntax tree(binary), you are supposed to output the corresponding infix expression, with parentheses reflecting the precedences of the operators.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line gives a positive integer N(≤ 20) which is the total number of nodes in the syntax tree.Then N lines follow, each gives the information of a node(the i - th line corresponds to the i - th node) in the format :
//
//data left_child right_child
//where data is a string of no more than 10 characters, left_childand right_child are the indices of this node's left and right children, respectively. The nodes are indexed from 1 to N. The NULL link is represented by −1. The figures 1 and 2 correspond to the samples 1 and 2, respectively.
//
//infix1.JPG	infix2.JPG
//Figure 1	Figure 2
//Output Specification :
//For each case, print in a line the infix expression, with parentheses reflecting the precedences of the operators.Note that there must be no extra parentheses for the final expression, as is shown by the samples.There must be no space between any symbols.
//
//Sample Input 1:
//	8
//		* 8 7
//		a - 1 - 1
//		* 4 1
//		+ 2 5
//		b - 1 - 1
//		d - 1 - 1
//		- -1 6
//		c - 1 - 1
//		Sample Output 1:
//	(a + b) * (c * (-d))
//		Sample Input 2 :
//		8
//		2.35 - 1 - 1
//		* 6 1
//		- -1 4
//		% 7 8
//		+ 2 3
//		a - 1 - 1
//		str - 1 - 1
//		871 - 1 - 1
//		Sample Output 2:
//	(a * 2.35) + (-(str % 871))

#include<iostream>
#include<map>
#include<functional>
using namespace std;
int main()
{
	int N;
	cin >> N;
	string node[21];
	int parent[21]{ 0 };
	map<int, int> leftChild;
	map<int, int> rightChild;
	for (int i = 1; i <= N; i++)
	{
		cin >> node[i];
		int temp;
		cin >> temp;
		leftChild[i] = temp;
		if (temp != -1)
			parent[temp] = i;
		cin >> temp;
		rightChild[i] = temp;
		if (temp != -1)
			parent[temp] = i;
	}
	int root = -1;
	for(int i=1;i<=N;i++)
		if (parent[i] == 0)
		{
			root = i;
			break;
		}
	function<void(int)> inorder = [&](int now)
	{
		if (now != -1)
		{
			if ((leftChild[now] != -1 || rightChild[now] != -1) && now != root)
				cout << "(";
			inorder(leftChild[now]);
			cout << node[now];
			inorder(rightChild[now]);
			if ((leftChild[now] != -1 || rightChild[now] != -1) && now != root)
				cout << ")";
		}
	};
	inorder(root);

	return 0;
}