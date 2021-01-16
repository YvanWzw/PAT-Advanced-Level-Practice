//1032 Sharing(25分)
//To store English words, one method is to use linked listsand store a word letter by letter.To save some space, we may let the words share the same sublist if they share the same suffix.For example, loadingand being are stored as showed in Figure 1.
//
//fig.jpg
//
//Figure 1
//
//You are supposed to find the starting position of the common suffix(e.g.the position of i in Figure 1).
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains two addresses of nodesand a positive N(≤10
//	​5
//	​​), where the two addresses are the addresses of the first nodes of the two words, and N is the total number of nodes.The address of a node is a 5 - digit positive integer, and NULL is represented by −1.
//
//	Then N lines follow, each describes a node in the format :
//
//Address Data Next
//whereAddress is the position of the node, Data is the letter contained by this node which is an English letter chosen from{ a - z, A - Z }, and Next is the position of the next node.
//
//Output Specification :
//For each case, simply output the 5 - digit starting position of the common suffix.If the two words have no common suffix, output - 1 instead.
//
//Sample Input 1:
//	11111 22222 9
//		67890 i 00002
//		00010 a 12345
//		00003 g - 1
//		12345 D 67890
//		00002 n 00003
//		22222 B 23456
//		11111 L 00001
//		23456 e 67890
//		00001 o 00010
//		Sample Output 1:
//	67890
//		Sample Input 2 :
//		00001 00002 4
//		00001 a 10001
//		10001 s - 1
//		00002 a 10002
//		10002 t - 1
//		Sample Output 2:
//	-1
//
//思路：
//末端对齐，从 - 1开始往前找，如果 - 1不止一个，那么毋庸置疑输出 - 1，如果 - 1唯一，根据 - 1的start直到找到不唯一的end即是答案，这题唯一的难点在于存储容器的选择（可能容易超时或者超内存）

#include<iostream>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;

class node
{
public:
	char str;
	string address;
};

int main()
{
	map<string, node> data;
	string start1, start2;
	int N = 0;
	cin >> start1 >> start2 >> N;
	//for (int i = 0; i < N; i++)
	//{
	//	node nod;
	//	string add_start;
	//	add_start.resize(6);
	//	scanf_s("%s", &add_start[0],6);
	//	char str;
	//	string end_start;
	//	end_start.resize(6);
	//	scanf_s("%s", &str,2);
	//	scanf_s("%s", &end_start[0],6);
	//	nod.address = end_start;
	//	nod.str = str;

	//	data[add_start] = nod;
	//}
	map<int, bool> data2;
	int ans;
	for (int i = 0; i < N; i++)
	{
		int add_start;
		scanf_s("%d", &add_start);
		char str;
		cin >> str;
		scanf_s("%d", &add_start);

		map<int, bool>::iterator it;
		it = data2.find(add_start);
		if (it == data2.end())
		{
			data2[add_start] = true;
		}
		else
		{
			ans = add_start;
			break;
		}
	}
	if (ans == -1)
		cout << "-1";
	else
		cout << setw(5) << setfill('0') << ans;

	return 0;
}