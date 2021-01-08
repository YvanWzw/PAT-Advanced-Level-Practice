//1027 Colors in Mars(20分)
//People in Mars represent the colors in their computers in a similar way as the Earth people.That is, a color is represented by a 6 - digit number, where the first 2 digits are for Red, the middle 2 digits for Green, and the last 2 digits for Blue.The only difference is that they use radix 13 (0 - 9 and A - C) instead of 16. Now given a color in three decimal numbers(each between 0 and 168), you are supposed to output their Mars RGB values.
//
//Input Specification :
//Each input file contains one test case which occupies a line containing the three decimal color values.
//
//Output Specification :
//For each test case you should output the Mars RGB value in the following format : first output #, then followed by a 6 - digit number where all the English characters must be upper - cased.If a single color is only 1 - digit long, you must print a 0 to its left.
//
//Sample Input :
//15 43 71
//Sample Output :
//#123456
//作者
//CHEN, Yue
//单位
//浙江大学
//代码长度限制
//16 KB
//时间限制
//400 ms
//内存限制
//64 MB

#include<string>
#include<iostream>
using namespace std;

string abc(string x)
{
	if (x == "10")
		return "A";
	else if (x == "11")
		return "B";
	else if (x == "12")
		return "C";
}

string digitTrans(int dig)
{
	string res = "";
	int div = dig / 13;
	int fi = dig % 13;
	if (div > 9)
		res += abc(to_string(div));
	else
		res += to_string(div);
	if(fi >9)
		res += abc(to_string(fi));
	else
		res += (to_string(fi));
	return res;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	string res = digitTrans(a);
	res += digitTrans(b);
	res += digitTrans(c);
	cout << "#" + res;

	return 0;
}