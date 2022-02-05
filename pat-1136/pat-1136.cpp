//1136 A Delayed Palindrome(20 分)
//Consider a positive integer N written in standard notation with k + 1 digits a
//i
//​
//as a
//k
//​
//⋯a
//1
//​
//a
//0
//​
//with 0≤a
//i
//​
//< 10 for all iand a
//	k
//	​
//>0. Then N is palindromic ifand only if a
//i
//​
//= a
//k−i
//​
//for all i.Zero is written 0 and is also palindromic by definition.
//
//Non - palindromic numbers can be paired with palindromic ones via a series of operations.First, the non - palindromic number is reversed and the result is added to the original number.If the result is not a palindromic number, this is repeated until it gives a palindromic number.Such number is called a delayed palindrome. (Quoted from https ://en.wikipedia.org/wiki/Palindromic_number )
//
//Given any positive integer, you are supposed to find its paired palindromic number.
//
//Input Specification :
//Each input file contains one test case which gives a positive integer no more than 1000 digits.
//
//Output Specification :
//For each test case, print line by line the process of finding the palindromic number.The format of each line is the following :
//
//A + B = C
//where A is the original number, B is the reversed A, and C is their sum.A starts being the input number, and this process ends until C becomes a palindromic number -- in this case we print in the last line C is a palindromic number.; or if a palindromic number cannot be found in 10 iterations, print Not found in 10 iterations.instead.
//
//Sample Input 1:
//97152
//Sample Output 1 :
//	97152 + 25179 = 122331
//	122331 + 133221 = 255552
//	255552 is a palindromic number.
//	Sample Input 2 :
//	196
//	Sample Output 2 :
//	196 + 691 = 887
//	887 + 788 = 1675
//	1675 + 5761 = 7436
//	7436 + 6347 = 13783
//	13783 + 38731 = 52514
//	52514 + 41525 = 94039
//	94039 + 93049 = 187088
//	187088 + 880781 = 1067869
//	1067869 + 9687601 = 10755470
//	10755470 + 07455701 = 18211171
//	Not found in 10 iterations.

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
using namespace std;
string deal(string root)
{
	//long long int temp1 = atol(root.c_str());
	//reverse(root.begin(), root.end());
	//long long int temp2 = atol(root.c_str());
	string temp = root;
	reverse(root.begin(), root.end());
	string ans = "";
	int jw = 0;
	for (int i = root.length() - 1; i >= 0; i--)
	{
		int t = (root[i] - '0') + (temp[i] - '0');
		t += jw;
		jw = t / 10;
		t %= 10;
		ans = to_string(t) + ans;
	}
	if(jw>0)
		ans = to_string(jw) + ans;
	return ans;
}
bool judge(string root)
{
	bool temp = false;
	int i = 0, j = root.length() - 1;
	while (i < j)
	{
		if (root[i] != root[j])
		{
			temp = true;
			return false;
		}
		i++;
		j--;
	}
	return true;
}
int main()
{
	string root;
	cin >> root;
	int i = 0;
	if (judge(root))
	{
		cout << root << " is a palindromic number.";
		return 0;
	}
	for (; i < 10; i++)
	{
		cout << root << " + ";
		reverse(root.begin(), root.end());
		cout << root;
		root = deal(root);
		cout << " = " << root << endl;
		if (judge(root))
		{
			cout << root << " is a palindromic number.";
			break;
		}
	}
	if (i == 10)
		cout << "Not found in 10 iterations.";

	return 0;
}