#include<iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	int i = 0;
	int ar[6] = { 0 };
	while (sum / 1000 != 0)
	{
		ar[i] = (sum % 1000)>0?(sum%1000):-(sum%1000);
		sum = sum / 1000;
		i++;
	}
	ar[i] = sum % 1000;
	for (int p = i; p >= 0; p--)
	{
		if (p == i)
			cout << ar[p];
		else
			if (ar[p] > 99)
				cout << ar[p];
			else if (ar[p] > 9)
				cout << "0" << ar[p];
			else if (ar[p] > 0)
				cout << "00" << ar[p];
			else if (ar[p] == 0)
				cout << "000";
		if(p!=0)
		cout << ",";
	}
	return 0;
}