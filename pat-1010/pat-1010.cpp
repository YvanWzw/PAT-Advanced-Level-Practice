#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;


long long rrq(string str, long long radix) {
	long long ww = 0;
	for (int i = 0; i < str.length(); i++) {
		int ee = str[i] < 'a' ? str[i] - '0' : str[i] - 'a' + 10;
		ww = ww * radix + ee;
	}
	return ww;
}
void qqq(string n1, string n2, int radix) {
	long long num = rrq(n1, radix);
	long long left = 0, right, zz = num + 2;
	for (int i = 0; i < n2.length(); i++)
		left = max(left, (long long)n2[i]);
	left = (left >= 'a' ? left - 'a' + 10 : left - '0') + 1;
	right = max(left, num);
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long num2 = rrq(n2, mid);
		if (num2 > num || num2 < 0) right = mid - 1;
		else if (num2 < num) left = mid + 1;
		else {
			zz = min(zz, mid);
			break;
		}
	}
	if (zz == num + 2)
		cout << "Impossible";
	else
		cout << zz;
}

int main() 
{
	string n1, n2;
	int radix, tag;
	cin >> n1 >> n2 >> tag >> radix;
	tag == 1 ? qqq(n1, n2, radix) : qqq(n2, n1, radix);
	return 0;
}