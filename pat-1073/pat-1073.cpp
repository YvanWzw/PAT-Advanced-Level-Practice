//1073 Scientific Notation(20 ·Ö)
//Scientific notation is the way that scientists easily handle very large numbers or very small numbers.The notation matches the regular expression[+-][1 - 9].[0 - 9] + E[+-][0 - 9] + which means that the integer portion has exactly one digit, there is at least one digit in the fractional portion, and the numberand its exponent's signs are always provided even when they are positive.
//
//Now given a real number A in scientific notation, you are supposed to print A in the conventional notation while keeping all the significant figures.
//
//Input Specification :
//Each input contains one test case.For each case, there is one line containing the real number A in scientific notation.The number is no more than 9999 bytes in length and the exponent's absolute value is no more than 9999.
//
//Output Specification :
//For each test case, print in one line the input number A in the conventional notation, with all the significant figures kept, including trailing zeros.
//
//Sample Input 1:
//	+1.23400E-03
//		Sample Output 1 :
//		0.00123400
//		Sample Input 2 :
//		-1.2E+10
//		Sample Output 2 :
//		-12000000000

#include<iostream>
#include<string>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	long long int k = -1, m = -1;
	string ans;
	for (long long int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'E')
			k = i;
		if (s[i] == '.')
			m = i;
		if (k >= 0)
			break;
	}
	long long int b = stol(s.substr(k + 1));
	if (b != 0)
		s.erase(m, 1);
	if (b > 0)
	{
		if (abs(b) < k - m - 1)
			ans = ans + s.substr(1, abs(b)+m-1) + "." + s.substr(abs(b)+m, k-abs(b)-m-1);
		else
		{
			ans = ans + s.substr(1, k - m);
			for (int i = 0; i < abs(b) - k + m + 1; i++)
				ans.append("0");
		}
	}
	else if (b == 0)
	{
		ans = ans + s.substr(1, k - m + 1);
	}
	else
	{
		ans = ans + s.substr(1, k - m);
		for (long long int i = 0; i < abs(b) - 1; i++)
			ans = "0" + ans;
		ans = "0." + ans;
	}
	if (s.substr(0, 1) == "-")
		ans = "-" + ans;
	cout << ans;
	return 0;
}