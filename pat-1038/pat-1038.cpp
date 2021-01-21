//1038 Recover the Smallest Number(30分)
//Given a collection of number segments, you are supposed to recover the smallest number from them.For example, given{ 32, 321, 3214, 0229, 87 }, we can recover many numbers such like 32 - 321 - 3214 - 0229 - 87 or 0229 - 32 - 87 - 321 - 3214 with respect to different orders of combinations of these segments, and the smallest number is 0229 - 321 - 3214 - 32 - 87.
//
//Input Specification :
//Each input file contains one test case.Each case gives a positive integer N(≤10
//	​4
//	​​) followed by N number segments.Each segment contains a non - negative integer of no more than 8 digits.All the numbers in a line are separated by a space.
//
//	Output Specification :
//For each test case, print the smallest number in one line.Notice that the first digit must not be zero.
//
//Sample Input :
//5 32 321 3214 0229 87
//Sample Output :
//22932132143287

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(const string& a, const string& b)
{
	return a + b < b + a;
}

int main()
{
	int N = 0;
	cin >> N;
	vector<string> vec;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}
	sort(vec.begin(), vec.end(), cmp);
	string ans = "";
	for (int i = 0; i < N; i++)
	{
		ans += vec[i];
	}
	int i = 0;
	for (; i < ans.size(); i++)
	{
		if (ans[i] != '0')
			break;
	}
	for (int j = i; j < ans.size(); j++)
	{
		cout << ans[j];
	}
	if (i == ans.size())
		cout << 0;


	return 0;
}