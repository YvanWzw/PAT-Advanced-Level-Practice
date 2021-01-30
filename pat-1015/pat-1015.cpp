#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<string.h>
using namespace std;
string intToA(int n, int radix)
{
	string ans = "";
	do {
		int t = n % radix;
		if (t >= 0 && t <= 9)	ans += t + '0';
		else ans += t - 10 + 'a';
		n /= radix;
	} while (n != 0);
	reverse(ans.begin(), ans.end());
	return ans;
}
int pri(int val)
{
	if (val == 1)
		return 1;
	if (val == 2)
		return 2;
	for (int i = 2; i <= sqrt(val); i++) {
		if (val%i == 0) {
			return 1;
		}
	}
	return 2;
}
int main()
{
	bool flag = false;
	int val = 0;
	int base = 0;
	cin >> val;
	while (val>0)
	{
		cin >> base;
		string vval = intToA(val, base);
		reverse(vval.begin(), vval.end());
		char *npt;
		const char *vvval = vval.c_str();
		int ans = strtol(vvval, &npt, base);
		if (pri(val) == 2 && pri(ans) == 2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cin >> val;
	}
	//delete vval;
	system("pause");
	return 0;
}