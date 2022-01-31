//1074 Reversing Linked List(25 ·Ö)
//Given a constant K and a singly linked list L, you are supposed to reverse the links of every K elements on L.For example, given L being 1¡ú2¡ú3¡ú4¡ú5¡ú6, if K = 3, then you must output 3¡ú2¡ú1¡ú6¡ú5¡ú4; if K = 4, you must output 4¡ú3¡ú2¡ú1¡ú5¡ú6.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains the address of the first node, a positive N(¡Ü10
//	5
//) which is the total number of nodes, and a positive K(¡ÜN) which is the length of the sublist to be reversed.The address of a node is a 5 - digit nonnegative integer, and NULL is represented by - 1.
//
//Then N lines follow, each describes a node in the format :
//
//Address Data Next
//where Address is the position of the node, Data is an integer, and Next is the position of the next node.
//
//Output Specification :
//For each case, output the resulting ordered linked list.Each node occupies a line, and is printed in the same format as in the input.
//
//Sample Input :
//00100 6 4
//00000 4 99999
//00100 1 12309
//68237 6 - 1
//33218 3 00000
//99999 5 68237
//12309 2 33218
//Sample Output :
//00000 4 33218
//33218 3 12309
//12309 2 00100
//00100 1 99999
//99999 5 68237
//68237 6 - 1

#include<iostream>
#include<map>
using namespace std;

class datax
{
public:
	string add;
	int num;
	string next;
};

int main()
{
	string start;
	int total, interval;
	cin >> start >> total >> interval;
	map<string, datax> val;
	for (int i = 0; i < total; i++)
	{
		datax d;
		cin >> d.add >> d.num >> d.next;
		val[d.add] = d;
	}

	datax* arr = new datax[total];

	int arrN = 0;

	string now = start;
	int cnt = 0;
	for (int i = 0; i < total; i++)
	{

		arr[i] = val[now];
		now = val[now].next;

		arrN++;

		if ((i + 1) % interval == 0)
		{
			reverse(arr + i - interval +1, arr + i+1);
		}


		if (now == "-1")
			break;
	}

	for (int i = 0; i < arrN; i++)
	{
		if (i != arrN - 1)
		{
			arr[i].next = arr[i + 1].add;
		}
		else
			arr[i].next = "-1";
	}

	for (int i = 0; i < arrN; i++)
	{
		cout << arr[i].add << " " << arr[i].num << " " << arr[i].next;
		if (i != arrN - 1)
			cout << endl;
	}



	delete[] arr;
	return 0;
}