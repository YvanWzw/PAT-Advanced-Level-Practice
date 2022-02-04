//1097 Deduplication on a Linked List(25 分)
//Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys.That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept.At the mean time, all the removed nodes must be kept in a separate list.For example, given L being 21→ - 15→ - 15→ - 7→15, you must output 21→ - 15→ - 7, and the removed list - 15→15.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains the address of the first node, and a positive N(≤10
//	5
//) which is the total number of nodes.The address of a node is a 5 - digit nonnegative integer, and NULL is represented by −1.
//
//Then N lines follow, each describes a node in the format :
//
//Address Key Next
//where Address is the position of the node, Key is an integer of which absolute value is no more than 10
//4
//, and Next is the position of the next node.
//
//Output Specification :
//For each case, output the resulting linked list first, then the removed list.Each node occupies a line, and is printed in the same format as in the input.
//
//Sample Input :
//00100 5
//99999 - 7 87654
//23854 - 15 00000
//87654 15 - 1
//00000 - 15 99999
//00100 21 23854
//Sample Output :
//00100 21 23854
//23854 - 15 99999
//99999 - 7 - 1
//00000 - 15 87654
//87654 15 - 1


#include<iostream>
#include<map>
#include<vector>
#include<cmath>
using namespace std;
class node
{
public:
	string start;
	int data;
	string next;
};
int main()
{
	map<string, node> md;
	map<int, bool> isV;
	int L;
	string K;
	cin >> K >> L;
	vector<node> cs;
	vector<node> ds;
	for (int i = 0; i < L; i++)
	{
		node temp;
		cin >> temp.start >> temp.data >> temp.next;
		md[temp.start] = temp;
	}
	string now = K;
	while (now != "-1")
	{
		map<int, bool>::iterator it;
		it = isV.find(abs(md[now].data));
		if (it == isV.end())
		{
			cs.push_back(md[now]);
			isV[abs(md[now].data)] = true;
		}	
		else
			ds.push_back(md[now]);

		now = md[now].next;
	}

	for(int i=0;i<cs.size();i++)
	{ 
		cout << cs[i].start << " " << cs[i].data << " ";
		if (i != cs.size() - 1)
			cout << cs[i + 1].start << endl;
		else
			cout << "-1" << endl;
	}

	for (int i = 0; i < ds.size(); i++)
	{
		cout << ds[i].start << " " << ds[i].data << " ";
		if (i != ds.size() - 1)
			cout << ds[i + 1].start << endl;
		else
			cout << "-1";
	}

	return 0;
}