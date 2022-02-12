//1140 Look - and -say Sequence(20 ·Ö)
//Look - and -say sequence is a sequence of integers as the following :
//
//D, D1, D111, D113, D11231, D112213111, ...
//where D is in[0, 9] except 1. The(n + 1)st number is a kind of description of the nth number.For example, the 2nd number means that there is one D in the 1st number, and hence it is D1; the 2nd number consists of one D(corresponding to D1) and one 1 (corresponding to 11), therefore the 3rd number is D111; or since the 4th number is D113, it consists of one D, two 1's, and one 3, so the next number must be D11231. This definition works for D = 1 as well. Now you are supposed to calculate the Nth number in a look-and-say sequence of a given digit D.
//
//Input Specification :
//Each input file contains one test case, which gives D(in[0, 9]) and a positive integer N(¡Ü 40), separated by a space.
//
//Output Specification :
//Print in a line the Nth number in a look - and -say sequence of D.
//
//Sample Input :
//1 8
//Sample Output :
//1123123111



#include<iostream>
#include<string>
using namespace std;
int main()
{
	string temp;
	int N;
	cin >> temp >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int count = 0;
		string D = temp;
		temp = "";
		char flag = D[0];
		for (auto& v : D)
		{
			if (v == flag)
				count++;
			else
			{
				temp += flag + to_string(count);
				count = 1;
				flag = v;
			}
			if (&v == &D.back())
				temp += flag + to_string(count);
		}
	}
	cout << temp;
	return 0;
}