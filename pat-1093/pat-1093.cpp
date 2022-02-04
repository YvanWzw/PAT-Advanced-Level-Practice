//1093 Count PAT's (25 ·Ö)
//The string APPAPT contains two PAT's as substrings. The first one is formed by the 2nd, the 4th, and the 6th characters, and the second one is formed by the 3rd, the 4th, and the 6th characters.
//
//Now given any string, you are supposed to tell the number of PAT's contained in the string.
//
//Input Specification :
//Each input file contains one test case.For each case, there is only one line giving a string of no more than 10
//5
//characters containing only P, A, or T.
//
//Output Specification :
//For each test case, print in one line the number of PAT's contained in the string. Since the result may be a huge number, you only have to output the result moded by 1000000007.
//
//Sample Input :
//APPAPT
//Sample Output :
//2

#include<iostream>
using namespace std;
int main()
{
	string pat;
	cin >> pat;
	int count = 0;
	int before[100011]{ 0 };
	int behand[100011]{ 0 };
	const int mod = 1000000007;
	for (int i = 0; i < pat.length(); i++)
	{
		before[i] = i == 0 ? 0 : before[i - 1];
		behand[pat.length() - i - 1] = i == 0 ? 0 : behand[pat.length() - i];
		if (pat[i] == 'P')
			before[i]++;
		if (pat[pat.length() - i - 1] == 'T')
			behand[pat.length() - i - 1]++;
	}
	for (int i = 0; i < pat.length(); i++)
		if (pat[i] == 'A')
			count = (count + before[i] % mod * behand[i] % mod) % mod;
	cout << count;
	return 0;
}
