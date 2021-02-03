
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int val = 0;
	int base = 0;
	cin >> val;
	cin >> base;
	vector<int> vec;
	do {
		int t = val % base;
		vec.push_back(t);
		val /= base;
	} while (val != 0);
	bool flag = false;
	for (int i = 0; i < vec.size() / 2; i++)
		if (vec[i] != vec[vec.size() - i - 1])
			flag = true;

	if (flag == false)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = vec.size() -1; i >=0; i--)
	{
		if (i != 0)
			cout << vec[i] << " ";
		else
			cout << vec[i];
	}


	system("pause");
	return 0;
}