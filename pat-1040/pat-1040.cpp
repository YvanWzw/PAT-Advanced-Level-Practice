//1040 Longest Symmetric String(25分)
//Given a string, you are supposed to output the length of the longest symmetric sub - string.For example, given Is PAT& TAP symmetric ? , the longest symmetric sub - string is s PAT & TAP s, hence you must output 11.
//
//Input Specification :
//Each input file contains one test case which gives a non - empty string of length no more than 1000.
//
//Output Specification :
//For each test case, simply print the maximum length in a line.
//
//Sample Input :
//Is PAT& TAP symmetric ?
//Sample Output :
//11


#include<iostream>
#include<string>
using namespace std;

int main()
{
	int max_count = 0;
	string str;
	getline(cin, str);
	if (str.size() == 1 || (str.size() == 2 && str[0] != str[1]))
		max_count = 1;
	else if (str.size() == 2 && str[0] == str[1])
		max_count = 2;
	else if (str.size() == 0)
		max_count = 0;
	else
	{
		if (str[0] == str[1])
			max_count = 2;
		for (int i = 2; i < str.size(); i++)
		{
			if (str[i] == str[i - 1] || str[i] == str[i - 2])
			{
				int count = 0;
				if (str[i] == str[i - 1])
				{
					for (int j =  i - 1; j >= 0; j--)
					{
						if (str[i + count] != str[j] || i + count == str.size() - 1 || j == 0)
						{
							if ((i + count == str.size() - 1 || j == 0) && str[i + count] == str[j])
								count++;

							count *= 2;
							if (count > max_count)
								max_count = count;
							break;
						}
						count++;
					}
				}
			}

		}
		for (int i = 2; i < str.size(); i++)
		{
			if (str[i] == str[i - 1] || str[i] == str[i - 2])
			{
				int count = 0;
				if (str[i] == str[i - 2])
				{
					for (int j = i - 2; j >= 0; j--)
					{
						if (str[i + count] != str[j] || i + count == str.size() - 1 || j == 0)
						{
							if ((i + count == str.size() - 1 || j == 0) && str[i + count] == str[j])
								count++;
							count *= 2;
							count++;
							if (count > max_count)
								max_count = count;
							break;
						}
						count++;
					}
				}

			}

		}
	}
	cout << max_count;

	return 0;
}