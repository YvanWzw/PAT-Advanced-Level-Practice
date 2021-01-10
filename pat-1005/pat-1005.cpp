#include<iostream>
#include<string>
using namespace std;
int main()
{
	int sum = 0;
	string str;
	cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++)
		sum += (str[i]-'0');

	int dd = 1;
	int q = sum;
	while (q / 10 != 0)
	{
		dd++;
		q = q / 10;
	}


	while (dd!=0)
	{
		int ww = 1;
		for (int i = 0; i < dd-1; i++)
			ww = ww * 10;
		int a = sum / ww;
		sum = sum % ww;
		dd--;
		switch (a)
		{
		case 0:
			cout << "zero";
			break;
		case 1:
			cout << "one";
			break;
		case 2:
			cout << "two";
			break;
		case 3:
			cout << "three";
			break;
		case 4:
			cout << "four";
			break;
		case 5:
			cout << "five";
			break;
		case 6:
			cout << "six";
			break;
		case 7:
			cout << "seven";
			break;
		case 8:
			cout << "eight";
			break;
		case 9:
			cout << "nine";
			break;
		}
		if (dd != 0)
			cout << " ";
	}

	return 0;
}