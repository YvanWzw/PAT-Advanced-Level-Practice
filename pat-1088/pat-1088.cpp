//1088 Rational Arithmetic(20 分)
//For two rational numbers, your task is to implement the basic arithmetics, that is, to calculate their sum, difference, productand quotient.
//
//Input Specification :
//Each input file contains one test case, which gives in one line the two rational numbers in the format a1 / b1 a2 / b2.The numerators and the denominators are all in the range of long int.If there is a negative sign, it must appear only in front of the numerator.The denominators are guaranteed to be non - zero numbers.
//
//Output Specification :
//For each test case, print in 4 lines the sum, difference, productand quotient of the two rational numbers, respectively.The format of each line is number1 operator number2 = result.Notice that all the rational numbers must be in their simplest form k a / b, where k is the integer part, and a / b is the simplest fraction part.If the number is negative, it must be included in a pair of parentheses.If the denominator in the division is zero, output Inf as the result.It is guaranteed that all the output integers are in the range of long int.
//
//Sample Input 1:
//	2 / 3 - 4 / 2
//		Sample Output 1 :
//		2 / 3 + (-2) = (-1 1 / 3)
//		2 / 3 - (-2) = 2 2 / 3
//		2 / 3 * (-2) = (-1 1 / 3)
//		2 / 3 / (-2) = (-1 / 3)
//		Sample Input 2 :
//		5 / 3 0 / 6
//		Sample Output 2 :
//		1 2 / 3 + 0 = 1 2 / 3
//		1 2 / 3 - 0 = 1 2 / 3
//		1 2 / 3 * 0 = 0
//		1 2 / 3 / 0 = Inf

//思路：
//1.对输入数据进行拆分，分为正负、斜杠前后、真假分数，并分别输入到不同的变量中
//2.所以我们需要一个数据结构，①bool ifPosi②long long integerPart③long long numerator④long long denominator
//3.进行加减运算时，先将两个数化为同分母形式，再根据正负号进行操作与结果符号判断
//4.进行乘除运算时，可能需要进行运算化简，否则容易超出long的范围，最后结果再进行符号判断

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
	if (temp.numerator == 0)
	{
		temp.numerator = 1;
		temp.denominator = 1;
	}
}

void simplify(node& temp)
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

node pretreatment(string temp)
{
	node data;

	if (!temp.empty())
	{
		if (temp[0] == '-')
		{
			data.ifPosi = false;
			temp.erase(0, 1);
		}

		int flag = 0;
		for (; flag < temp.size(); flag++)
			if (temp[flag] == '/')
				break;

		data.numerator = atoll(temp.substr(0, flag).c_str());
		data.denominator = atoll(temp.substr(flag + 1, temp.size()).c_str());

		if (data.denominator < 0)
		{
			data.denominator = abs(data.denominator);
			data.ifPosi = !data.ifPosi;
		}

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


	res.ifPosi = res.numerator >= 0 ? true : false;

	res.numerator = abs(res.numerator);


	return res;
}

node mul(node n1, node n2)
{
	node res;
	res.numerator = n1.numerator * n2.numerator;
	res.denominator = n1.denominator * n2.denominator;
	res.ifPosi = n1.ifPosi == n2.ifPosi ? true : false;
	return res;
}

node div(node n1, node n2)
{
	node res;
	res.numerator = n1.numerator * n2.denominator;
	res.denominator = n2.numerator * n1.denominator;
	res.ifPosi = n1.ifPosi == n2.ifPosi ? true : false;
	return res;
}

node addJudge(node n1, node n2)
{
	node res;
	res = n1.ifPosi == n2.ifPosi ? add(n1, n2) : sub(n1, n2);
	if (res.numerator > 0 && n1.ifPosi == false)
		res.ifPosi = false;
	return res;
}

node subJudge(node n1, node n2)
{
	node res;
	if (n1.ifPosi == n2.ifPosi)
	{
		res = sub(n1, n2);
		if (n1.ifPosi == false)
		{
			res.ifPosi = !res.ifPosi;
		}
	}
	else
	{
		res = add(n1, n2);
		res.ifPosi = n1.ifPosi;
	}
	return res;
}

void output(node temp)
{
	if (temp.numerator >= temp.denominator)
		trans(temp);
	if (temp.numerator != 0)
		simplify(temp);
	if (temp.integerPart == 0 && temp.numerator == 0)
		cout << 0;
	else
	{
		if (temp.ifPosi == false)
			cout << "(-";
		if (temp.integerPart != 0)
			cout << temp.integerPart;
		if (temp.integerPart != 0 && temp.denominator != temp.numerator)
			cout << " ";
		if (temp.denominator != temp.numerator)
			cout << temp.numerator << "/" << temp.denominator;
		if (temp.ifPosi == false)
			cout << ")";
	}

}


int main()
{
	string temp;
	cin >> temp;
	node num1 = pretreatment(temp);
	cin >> temp;
	node num2 = pretreatment(temp);

	node res[4];

	//add
	res[0] = addJudge(num1, num2);
	//sub
	res[1] = subJudge(num1, num2);
	//mul
	res[2] = mul(num1, num2);

	for (int i = 0; i < 3; i++)
	{
		output(num1);
		cout << " ";
		switch (i)
		{
		case 0:
			cout << "+";
			break;
		case 1:
			cout << "-";
			break;
		case 2:
			cout << "*";
			break;
		default:
			break;
		}
		cout << " ";
		output(num2);
		cout << " = ";
		output(res[i]);
		cout << endl;
	}

	output(num1);
	cout << " / ";
	output(num2);
	cout << " = ";

	if (num2.numerator == 0)
		cout << "Inf";
	else
	{
		res[3] = div(num1, num2);
		output(res[3]);
	}


	return 0;
}