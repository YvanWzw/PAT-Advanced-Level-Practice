//1081 Rational Sum(20 ·Ö)
//Given N rational numbers in the form numerator / denominator, you are supposed to calculate their sum.
//
//Input Specification :
//Each input file contains one test case.Each case starts with a positive integer N(¡Ü100), followed in the next line N rational numbers a1 / b1 a2 / b2 ... where all the numerators and denominators are in the range of long int.If there is a negative number, then the sign must appear in front of the numerator.
//
//Output Specification :
//For each test case, output the sum in the simplest form integer numerator / denominator where integer is the integer part of the sum, numerator < denominator, and the numeratorand the denominator have no common factor.You must output only the fractional part if the integer part is 0.
//
//Sample Input 1:
//	5
//		2 / 5 4 / 15 1 / 30 - 2 / 60 8 / 3
//		Sample Output 1 :
//		3 1 / 3
//		Sample Input 2 :
//		2
//		4 / 3 2 / 3
//		Sample Output 2 :
//		2
//		Sample Input 3 :
//		3
//		1 / 3 - 1 / 6 1 / 8
//		Sample Output 3 :
//		7 / 24

#include<iostream>
using namespace std;

class node
{
public:
	bool ifPosi{ true };//true=posi false=nega
	long long integerPart{ 0 };
	long long numerator{ 0 };
	long long denominator{ 1 };
};

void trans(node& temp)
{
	long long a = temp.numerator / temp.denominator;
	long long b = temp.numerator % temp.denominator;
	temp.integerPart += a;
	temp.numerator = b;
}

void simplify(node& temp)
{
	if (temp.numerator != 0)
	{
		long long a = temp.numerator;
		long long b = temp.denominator;
		while (b % a != 0)
		{
			int flag = b;
			b = a;
			a = flag % a;
		}
		temp.numerator /= a;
		temp.denominator /= a;
	}
	temp.denominator = abs(temp.denominator);
}

node pretreatment(string temp)
{
	node data;

	if (!temp.empty())
	{
		//if (temp[0] == '-')
		//{
		//	data.ifPosi = false;
		//	temp.erase(0, 1);
		//}

		int flag = 0;
		for (; flag < temp.size(); flag++)
			if (temp[flag] == '/')
				break;

		data.numerator = atoll(temp.substr(0, flag).c_str());
		data.denominator = atoll(temp.substr(flag + 1, temp.size()).c_str());
	}
	return data;
}

node add(node n1, node n2)
{
	node res;
	res.denominator = n1.denominator * n2.denominator;
	res.numerator = n1.denominator * n2.numerator + n1.numerator * n2.denominator;
	res.ifPosi = n1.ifPosi;
	return res;
}

node sub(node n1, node n2)
{
	node res;
	if (n1.denominator != n2.denominator)
	{
		res.denominator = n1.denominator * n2.denominator;
		res.numerator = n1.numerator * n2.denominator - n1.denominator * n2.numerator;
	}
	else
	{
		res.denominator = n1.denominator;
		res.numerator = n1.numerator - n2.numerator;
	}

	if (n1.ifPosi == false)
		res.ifPosi = res.numerator >= 0 ? false : true;
	else
		res.ifPosi = res.numerator >= 0 ? true : false;

	res.numerator = abs(res.numerator);


	return res;
}


node addJudge(node n1, node n2)
{
	node res;
	res = n1.ifPosi == n2.ifPosi ? add(n1, n2) : sub(n1, n2);
	return res;
}


void output(node temp)
{
	if (temp.integerPart == 0 && temp.numerator == 0)
		cout << 0;
	else
	{
		//if (temp.ifPosi == false)
		//	cout << "-";
		if (temp.integerPart != 0)
			cout << temp.integerPart;
		if (temp.integerPart != 0 && temp.numerator != 0)
			cout << " ";
		if (temp.numerator != 0)
			cout << temp.numerator << "/" << temp.denominator;
	}

}


int main()
{
	int N;
	cin >> N;
	string temp;
	node num[100];
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		num[i] = pretreatment(temp);
	}
	node item = num[0];
	for (int i = 1; i < N; i++)
	{
		item = addJudge(item, num[i]);
		simplify(item);
	}
	trans(item);

	output(item);

	return 0;
}