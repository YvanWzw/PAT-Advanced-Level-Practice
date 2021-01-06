#include<iostream>
#include<iomanip>
using namespace std;
int main()
{

	int k1 = 0;
	int k2 = 0;
	float p1[1001] = { 0 };
	float p2[1001] = { 0 };
	int temp = 0;
	cin >> k1;
	for (int i = 0; i < k1; i++)
	{
		cin >> temp;
		cin >> p1[temp];
	}
	cin >> k2;
	for (int i = 0; i < k2; i++)
	{
		cin >> temp;
		cin >> p2[temp];
	}
	temp = 0;
	for (int i = 0; i < 1001; i++)
		p1[i] += p2[i];
	for (int i = 0; i < 1001; i++)
		if (p1[i] != 0)
			temp++;
	cout << temp;
	for (int i = 1000; i >=0; i--)
		if (p1[i] != 0)
		{
			cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1)<< p1[i];
		}
	return 0;
}