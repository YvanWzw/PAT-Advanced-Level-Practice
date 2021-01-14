#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float arra[1001] = { 0 };
	float arrb[1001] = { 0 };
	int aa = 0;
	int bb = 0;
	int temp = 0;
	cin >> aa;
	for (int i = 0; i < aa; i++)
	{
		cin >> temp;
		cin >> arra[temp];
	}
	cin >> bb;
	for (int i = 0; i < bb; i++)
	{
		cin >> temp;
		cin >> arrb[temp];
	}
	float arrr[2222] = { 0 };
	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
		{
			arrr[i+j] = arrr[i+j] + arra[i] * arrb[j];
		}

	temp = 0;
	for (int i = 0; i < 2222; i++)
		if (arrr[i] != 0)
			temp++;
	cout << temp << " ";
	for (int i = 2221; i >= 0; i--)
		if (arrr[i] != 0)
		{
			cout << i << " " << setiosflags(ios::fixed) << setprecision(1) <<arrr[i];
			temp--;
			if (temp != 0)
				cout << " ";
		}


	system("pause");
	return 0;
}