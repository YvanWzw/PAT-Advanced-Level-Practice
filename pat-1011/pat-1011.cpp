#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float game[3][3] = { 0 };
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> game[i][j];
	int most[3] = { 0 };
	int po = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			if (game[i][j] > game[i][po])
				po = j;
			if (j == 2)
			{
				most[i] = po;
				po = 0;
			}
		}
	float res = (game[0][most[0]] * game[1][most[1]] * game[2][most[2]] * 0.65 - 1) * 2;
	for (int i = 0; i < 3; i++)
	{
		if (most[i] == 0)
			cout << "W" << " ";
		else if (most[i] == 1)
			cout << "T" << " ";
		else if (most[i] == 2)
			cout << "L" << " ";
	}
	cout << fixed << setprecision(2) << res;
	system("pause");
	return 0;
}