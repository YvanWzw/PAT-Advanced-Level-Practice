
#include<iostream>
using namespace std;
int main()
{
	int leng = 0;
	cin >> leng;
	int *arr = new int[leng];
	for (int i = 0; i < leng; i++)
		cin >> arr[i];

	int p = leng;
	int tim = 0;
	int current = 0;
	for (int i = 0; i < leng; i++)
	{
		if (arr[i] > current)
			tim = tim + (arr[i] - current) * 6;
		if (arr[i] < current)
			tim = tim + (current - arr[i]) * 4;
		current = arr[i];
		tim += 5;

	}
	cout << tim;
	delete[] arr;

	return 0;
}