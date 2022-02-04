//1100 Mars Numbers(20 ·Ö)
//People on Mars count their numbers with base 13:
//
//Zero on Earth is called "tret" on Mars.
//The numbers 1 to 12 on Earth is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
//For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
//For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth.In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earthand Mars number systems.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains a positive integer N(< 100).Then N lines follow, each contains a number in[0, 169), given either in the form of an Earth number, or that of Mars.
//
//	Output Specification :
//For each number, print in a line the corresponding number in the other language.
//
//Sample Input :
//4
//29
//5
//elo nov
//tam
//Sample Output :
//hel mar
//may
//115
//13

#include<iostream>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
const string d1[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
const string d2[13] = { "","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou" };
map<string, int> m1, m2;
string etom(int earth)
{
	int t1 = earth % 13;
	int t2 = earth / 13;
	if (t2 == 0)
		return d1[t1];
	return t1 == 0 ? d2[t2] : d2[t2] + " " + d1[t1];
}
int mtoe(string mar)
{
	vector<string> temp;
	string res;
	stringstream input(mar);
	while (input >> res)
		temp.push_back(res);
	if(temp.size()==2)
		return m2[temp[0]] * 13 + m1[temp[1]];
	return m1.find(mar) != m1.end() ? m1[mar] : m2[mar]*13;
}
int main()
{
	for (int i = 0; i < 13; i++)
	{
		m1[d1[i]] = i;
		if (i != 0)
			m2[d2[i]] = i;
	}

	int N;
	cin >> N;
	cin.ignore();
	string data[101];
	string res[101];
	for (int i = 0; i < N; i++)
		getline(cin, data[i]);

	for (int i = 0; i < N; i++)
	{
		if (data[i][0] <= '9' && data[i][0] >= '0')
			res[i] = etom(atoi(data[i].c_str()));
		else
			res[i] = to_string(mtoe(data[i]));
	}

	for (int i = 0; i < N; i++)
	{
		cout << res[i];
		if (i != N - 1)
			cout << endl;
	}

	return 0;
}