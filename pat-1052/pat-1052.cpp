//1052 Linked List Sorting(25 分)
//A linked list consists of a series of structures, which are not necessarily adjacent in memory.We assume that each structure contains an integer keyand a Next pointer to the next structure.Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains a positive N(< 10
//	5
//) and an address of the head node, where N is the total number of nodes in memoryand the address of a node is a 5 - digit positive integer.NULL is represented by −1.
//
//Then N lines follow, each describes a node in the format :
//
//Address Key Next
//where Address is the address of the node in memory, Key is an integer in[−10
//5
//, 10
//5
//], and Next is the address of the next node.It is guaranteed that all the keys are distinctand there is no cycle in the linked list starting from the head node.
//
//Output Specification :
//For each test case, the output format is the same as that of the input, where N is the total number of nodes in the listand all the nodes must be sorted order.
//
//Sample Input :
//5 00001
//11111 100 - 1
//00001 0 22222
//33333 100000 11111
//12345 - 1 33333
//22222 1000 12345
//Sample Output :
//5 12345
//12345 - 1 00001
//00001 0 11111
//11111 100 22222
//22222 1000 33333
//33333 100000 - 1

#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
class node
{
public:
	string address;
	int data;
	string next;

	bool operator <(const node& b)
	{
		return b.data > data;
	}
};
int main()
{
	int num;
	string start;
	map<string, node> m;
	cin >> num >> start;
	vector<node> vec;
	for (int i = 0; i < num; i++)
	{
		node n;
		cin >> n.address >> n.data >> n.next;
		m[n.address] = n;
	}

	while (m.find(start) != m.end())
	{
		vec.push_back(m[start]);
		start = m[start].next;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++)
	{
		if (i != vec.size() - 1)
		{
			vec[i].next = vec[i + 1].address;
		}
		else
			vec[i].next = "-1";
	}

	cout << vec.size() << " ";
	if (vec.size() != 0)
		cout << vec[0].address << endl;
	else
		cout << "-1";
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i].address << " " << vec[i].data << " " << vec[i].next;
		if (i != vec.size() - 1)
			cout << endl;
	}

	return 0;
}