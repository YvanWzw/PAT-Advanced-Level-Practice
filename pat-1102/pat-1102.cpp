//1102 Invert a Binary Tree(25 分)
//The following is from Max Howell @twitter:
//
//Google: 90 % of our engineers use the software you wrote(Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
//Now it's your turn to prove that YOU CAN invert a binary tree!
//
//Input Specification :
//Each input file contains one test case.For each case, the first line gives a positive integer N(≤10) which is the total number of nodes in the tree--and hence the nodes are numbered from 0 to N−1.Then N lines follow, each corresponds to a node from 0 to N−1, and gives the indices of the leftand right children of the node.If the child does not exist, a - will be put at the position.Any pair of children are separated by a space.
//
//Output Specification :
//For each test case, print in the first line the level - order, and then in the second line the in - order traversal sequences of the inverted tree.There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.
//
//Sample Input :
//8
//1 -
//--
//0 -
//2 7
//- -
//--
//5 -
//4 6
//Sample Output :
//3 7 2 6 4 0 5 1
//6 5 7 4 3 2 0 1

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int parent[11];
int leftx[11];
int rightx[11];
vector<int> ans1;
vector<int> ans2;
queue<int> lol;
void inOrder(int now)
{
	if (rightx[now] != -1)
		inOrder(rightx[now]);
	ans2.push_back(now);
	if (leftx[now] != -1)
		inOrder(leftx[now]);
}
void levelOrder()
{
	int next = lol.front();
	ans1.push_back(next);
	lol.pop();
	if (rightx[next] != -1)
		lol.push(rightx[next]);
	if (leftx[next] != -1)
		lol.push(leftx[next]);
	if (!lol.empty())
		levelOrder();
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < 11; i++)
	{
		parent[i] = -1;
		leftx[i] = -1;
		rightx[i] = -1;
	}
	for (int i = 0; i < 2 * N; i++)
	{
		string temp;
		cin >> temp;
		if (temp != "-")
		{
			parent[atoi(temp.c_str())] = i / 2;
			i % 2 == 0 ? leftx[i / 2] = atoi(temp.c_str()) : rightx[i / 2] = atoi(temp.c_str());
		}
	}
	int root = -1;
	for (int i = 0; i < N; i++)
		if (parent[i] == -1)
		{
			root = i;
			break;
		}
	lol.push(root);
	levelOrder();
	inOrder(root);
	for (int& i : ans1)
	{
		cout << i;
		if (&i != &ans1.back())
			cout << " ";
		else
			cout << endl;
	}
	for (int& i : ans2)
	{
		cout << i;
		if (&i != &ans2.back())
			cout << " ";
	}


	return 0;
}