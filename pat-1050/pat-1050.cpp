#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	map<char, bool> subTable;
	string str;
	getline(cin, str);
	string sub;
	getline(cin, sub);
	for (auto it : sub)
	{
		subTable[it] = true;
	}
	for (auto it : str)
	{
		if (!subTable[it])
		{
			cout << it;
		}
	}


	return 0;
}