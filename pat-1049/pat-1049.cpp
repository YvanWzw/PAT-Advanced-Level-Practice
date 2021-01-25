//1049 Counting Ones(30分)
//The task is simple : given any positive integer N, you are supposed to count the total number of 1's in the decimal form of the integers from 1 to N. For example, given N being 12, there are five 1's in 1, 10, 11, and 12.
//
//Input Specification :
//Each input file contains one test case which gives the positive N(≤2
//	​30
//	​​).
//
//	Output Specification :
//For each test case, print the number of 1's in one line.
//
//Sample Input :
//12
//Sample Output :
//5
//
//123
//：个位大于1 所以出现了12 + 1次 13 * 1 = 13 ：1 11 21 31 41 51 61 71 81 91 101 111 121
//：十位大于1 所以出现了1 + 1次 2 * 10 = 20 10 11 12 13 14 15 16 17 18 19 110 111 112 113 114 115 116 117 118 119
//：百位（最高位）等于1  所以出现了1 * （123 - 100 + 1） = 24次 ：100 。。。 123
//共计：13 + 20 + 24 = 57次
//
// 大于1 等于1 小于1 

#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int ans = 0;
	int temp = num;
	int temq = 0;
	int temb = 0;
	int a = 1;
	while (num / a)
	{
		//temp:前串数字 temq:当下数字 temb:后串数字
		temp = num / (a * 10);
		temq = num / a;
		temq = temq % 10;
		temb = num % a;

		if (temq > 1)
			ans = ans + (temp + 1) * a;
		else if (temq == 1)
			ans = ans + temp * a + temb + 1;
		else if (temq == 0)
			ans = ans + temp * a;
		a *= 10;
	}
	cout << ans;

	return 0;
}