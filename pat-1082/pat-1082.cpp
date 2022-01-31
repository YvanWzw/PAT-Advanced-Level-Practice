//1082 Read Number in Chinese(25 ·Ö)
//Given an integer with no more than 9 digits, you are supposed to read it in the traditional Chinese way.Output Fu first if it is negative.For example, -123456789 is read as Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu.Note: zero(ling) must be handled correctly according to the Chinese tradition.For example, 100800 is yi Shi Wan ling ba Bai.
//
//Input Specification :
//Each input file contains one test case, which gives an integer with no more than 9 digits.
//
//Output Specification :
//For each test case, print in a line the Chinese way of reading the number.The characters are separated by a spaceand there must be no extra space at the end of the line.
//
//Sample Input 1:
//	-123456789
//		Sample Output 1 :
//		Fu yi Yi er Qian san Bai si Shi wu Wan liu Qian qi Bai ba Shi jiu
//		Sample Input 2 :
//		100800
//		Sample Output 2 :
//		yi Shi Wan ling ba Bai

#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
int main()
{
	string temp;
	cin >> temp;

	string shuzhi[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	string danwei[8] = { "Yi","Qian","Bai","Shi","Wan","Qian","Bai","Shi" };
	string res;

	if (temp[0] == '-')
	{
		cout << "Fu ";
		temp = temp.substr(1, temp.length() - 1);
	}

	if (temp.length() < 9)
	{
		stringstream ss;
		ss << setw(9) << setfill('0') << temp;
		temp = ss.str();
	}

	bool flag1 = false, flag2 = false;
	bool flag3 = false, flag4 = false;

	for (int i = 0; i < 8; i++)
	{
		if (temp[i] != '0')
			res = res + shuzhi[temp[i] - 48] + " " + danwei[i] + " ";


		if (temp[i] == '0' && i > 0 && i < 4 && !flag1 && !res.empty())
		{
			for (int j = i; j < 4; j++)
			{
				if (temp[j] != '0')
				{
					flag1 = true;
					res += "ling ";
					break;
				}
			}

		}

		if (i == 4 && temp[i] == '0')
		{
			if (!flag1 && !res.empty())
			{
				for (int j = 1; j <= 4; j++)
				{
					if (temp[j] != '0')
					{
						flag3 = true;
						break;
					}
				}
				for (int j = 5; j < 9; j++)
					if (temp[j] != '0')
						flag4 = true;
				if (!flag3 && flag4)
				{
					res += "ling ";
				}
			}

			for (int j = 1; j < 4; j++)
			{
				if (temp[j] != '0')
				{
					res += "Wan ";
					break;
				}

			}

		}

		if (temp[i] == '0' && i > 4 && i < 8 && !flag2 && !res.empty())
		{
			if (res[res.length() - 2] != 'g')
				for (int j = i; j <= 8; j++)
				{
					if (temp[j] != '0')
					{
						flag2 = true;
						res += "ling ";
						break;
					}
				}
		}




	}

	if (temp[8] != '0')
		res = res + shuzhi[temp[8] - 48] + " ";

	if (!res.empty())
	{
		res.erase(res.length() - 1);
		cout << res;
	}
	else
		cout << "ling";


	return 0;
}