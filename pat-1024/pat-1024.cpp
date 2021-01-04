//1024 Palindromic Number(25分)
//A number that will be the same when it is written forwards or backwards is known as a Palindromic Number.For example, 1234321 is a palindromic number.All single digit numbers are palindromic numbers.
//
//Non - palindromic numbers can be paired with palindromic ones via a series of operations.First, the non - palindromic number is reversed and the result is added to the original number.If the result is not a palindromic number, this is repeated until it gives a palindromic number.For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.
//
//Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.
//
//Input Specification :
//Each input file contains one test case.Each case consists of two positive numbers Nand K, where N(≤10
//	​10
//	​​) is the initial numerand K(≤100) is the maximum number of steps.The numbers are separated by a space.
//
//	Output Specification :
//For each test case, output two numbers, one in each line.The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number.If the palindromic number is not found after K steps, just output the number obtained at the Kth stepand K instead.
//
//Sample Input 1:
//	67 3
//		Sample Output 1 :
//		484
//		2
//		Sample Input 2 :
//		69 3
//		Sample Output 2 :
//		1353
//		3
//
//思路：
//1.需要一个bool函数用于检测字符串是否回文
//2.只能用字符串 因为超过了INT_MAX（至少几次相加后很可能超过）
//3.需要一个递归函数来计算回文相加
//4.可以考虑用数组，10 ^ 10的2 ^ 100乘积位数是数组的长度
//5.要注意的是结尾为0的情况
//6.还需要一个函数用于获得回文（这里数组不好传参，可以考虑用全局）
//7.字符串可以直接用reverse 数组可以用strrev

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool judgePalindromic(string str)
{
	int length = str.length();
	int start = 0;
	int end = length - 1;
	bool flag = true;
	if (length == 1)
		return true;
	else if (length == 2)
	{
		if (str[0] != str[1])
			flag = false;
	}
	else
	{
		while (end - start >= 2)
		{
			if (str[start] != str[end])
			{
				flag = false;
				break;
			}
			start++;
			end--;
		}
	}
	return flag;
}

//int countZero(string str)
//{
//	//get the length of 0 at the end of the str
//	int count = 0;
//	for (int i = str.length() - 1; i >= 0; i--)
//	{
//		if (str[i] != '0')
//			break;
//		count++;
//	}
//	return count;
//}

string add(string str)
{
	//int zero = countZero(str);
	string rStr = str;
	reverse(str.begin(), str.end());
	string ans = "";
	bool carry = false;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		int num1 = str[i] - '0';
		int num2 = rStr[i] - '0';
		int aNum = num1 + num2;
		if (carry == true)
			aNum++;
		carry = false;
		if (aNum > 9)
		{
			carry = true;
			aNum -= 10;
		}

		ans += to_string(aNum);
		if (i == 0 && carry)
		{
			ans += "1";
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	string str;
	int K = 0;
	cin >> str >> K;
	int count = 0;
	if (judgePalindromic(str))
	{
		cout << str << endl << count;
	}
	else
	{
		for (; count < K; count++)
		{
			str = add(str);
			if (judgePalindromic(str))
			{
				count++;
				break;
			}
		}
		cout << str << endl << count;
	}

	return 0;
}