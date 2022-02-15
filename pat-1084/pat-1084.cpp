//1084 Broken Keyboard(20 ·Ö)
//On a broken keyboard, some of the keys are worn out.So when you type some sentences, the characters corresponding to those keys will not appear on screen.
//
//Now given a string that you are supposed to type, and the string that you actually type out, please list those keys which are for sure worn out.
//
//Input Specification :
//Each input file contains one test case.For each case, the 1st line contains the original string, and the 2nd line contains the typed - out string.Each string contains no more than 80 characters which are either English letters[A - Z](case insensitive), digital numbers[0 - 9], or _(representing the space).It is guaranteed that both strings are non - empty.
//
//Output Specification :
//For each test case, print in one line the keys that are worn out, in the order of being detected.The English letters must be capitalized.Each worn out key must be printed once only.It is guaranteed that there is at least one worn out key.
//
//Sample Input :
//7_This_is_a_test
//_hs_s_a_es
//Sample Output :
//7TI

#include<iostream>
#include<string>
#include<map>
using namespace std;
int main()
{
	string temp1, temp2, ans;
	cin >> temp1 >> temp2;
	map<char, bool> killtheletter;
	int i = 0, j = 0;
	do
	{
		if (temp1[i] == temp2[j])
		{
			++i;
			++j;
		}
		else
		{
			if (killtheletter.find(temp1[i]) == killtheletter.end())
			{
				killtheletter[temp1[i]] = true;
				if (!(temp1[i] <= 57 && temp1[i] >= 48))
					temp1[i] <= 96 ? killtheletter[temp1[i] + 32] = true : killtheletter[temp1[i] - 32] = true;
				ans += temp1[i] <= 96 ? temp1[i] : (temp1[i] - 32);
			}
			++i;
		}
	} while (i < temp1.length());

	cout << ans;

	return 0;
}