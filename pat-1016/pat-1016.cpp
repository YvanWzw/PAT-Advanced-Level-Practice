//1016 Phone Bills （25 point(s)）
//A long - distance telephone company charges its customers by the following rules :
//
//Making a long - distance call costs a certain amount per minute, depending on the time of day when the call is made.When a customer starts connecting a long - distance call, the time will be recorded, and so will be the time when the customer hangs up the phone.Every calendar month, a bill is sent to the customer for each minute called(at a rate determined by the time of day).Your job is to prepare the bills for each month, given a set of phone call records.
//
//Input Specification :
//Each input file contains one test case.Each case has two parts : the rate structure, and the phone call records.
//
//The rate structure consists of a line with 24 non - negative integers denoting the toll(cents / minute) from 00 : 00 - 01 : 00, the toll from 01 : 00 - 02 : 00, and so on for each hour in the day.
//
//The next line contains a positive number N(≤1000), followed by N lines of records.Each phone call record consists of the name of the customer(string of up to 20 characters without space), the time and date(mm : dd : hh : mm), and the word on - line or off - line.
//
//For each test case, all dates will be within a single month.Each on - line record is paired with the chronologically next record for the same customer provided it is an off - line record.Any on - line records that are not paired with an off - line record are ignored, as are off - line records not paired with an on - line record.It is guaranteed that at least one call is well paired in the input.You may assume that no two records for the same customer have the same time.Times are recorded using a 24 - hour clock.
//
//Output Specification :
//For each test case, you must print a phone bill for each customer.
//
//Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.
//
//Sample Input :
//10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
//10
//CYLL 01 : 01 : 06 : 01 on - line
//CYLL 01 : 28 : 16 : 05 off - line
//CYJJ 01 : 01 : 07 : 00 off - line
//CYLL 01 : 01 : 08 : 03 off - line
//CYJJ 01 : 01 : 05 : 59 on - line
//aaa 01 : 01 : 01 : 03 on - line
//aaa 01 : 02 : 00 : 01 on - line
//CYLL 01 : 28 : 15 : 41 on - line
//aaa 01 : 05 : 02 : 24 on - line
//aaa 01 : 04 : 23 : 59 off - line
//
//
//Sample Output :
//CYJJ 01
//01 : 05 : 59 01 : 07 : 00 61 $12.10
//Total amount : $12.10
//CYLL 01
//01 : 06 : 01 01 : 08 : 03 122 $24.40
//28 : 15 : 41 28 : 16 : 05 24 $3.85
//Total amount : $28.25
//aaa 01
//02 : 00 : 01 04 : 23 : 59 4318 $638.80
//Total amount : $638.80

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include <utility>
#include<map>
using namespace std;

class node
{
public:
	string name;
	int month;
	int day;
	int hour;
	int minute;
	bool status;
};

class secNode
{
public:
	int mm;
	int d1;
	int d2;
	int h1;
	int h2;
	int m1;
	int m2;
};

int fee[24];
int centperday = 0;

int calculatePrice(secNode sn,int &totalmin)
{
	int cent = 0;
	int dd1 = sn.d1;
	int dd2 = sn.d2;
	while (dd2 - dd1 > 1||((dd2-dd1)==1&&sn.h1<=sn.h2))
	{
		cent += centperday;
		totalmin = totalmin + 60 * 24;
		dd1++;
	}
	int hh1 = sn.h1;
	int hh2 = sn.h2;
	int mm1 = sn.m1;
	int mm2 = sn.m2;
	if (hh1 != hh2)
	{
		cent = cent + (60 - mm1)*fee[hh1] + mm2 * fee[hh2];
		totalmin = totalmin + (60 - mm1) + mm2;
		hh1++;
		if (hh1 == 24)
		{
			hh1 -= 24;
			dd1++;
		}
	}
	else
	{
		cent = cent + (mm2 - mm1)*fee[hh1];
		totalmin = totalmin + (mm2 - mm1);
	}
	while (hh1 != hh2)
	{
		cent = cent + 60 * fee[hh1];
		totalmin = totalmin + 60;
		hh1++;
		if (hh1 >= 24)
			hh1 -= 24;
	}
	return cent;
}


bool cmp(node n1, node n2)
{
	if (n1.day != n2.day)
		return n1.day < n2.day;
	else
	{
		if (n1.hour != n2.hour)
			return n1.hour < n2.hour;
		else
			return n1.minute < n2.minute;
	}
}


int main()
{
	int totalcent = 0;
	for (int i = 0; i < 24; i++)
	{
		cin >> fee[i];
		totalcent = totalcent + fee[i];
	}

	centperday = totalcent * 60;

	int item;
	cin >> item;

	vector<node> vec;
	map<string, vector<secNode>> nmap;

	for (int i = 0; i < item; i++)
	{
		node nd;
		string temp;
		cin >> temp;
		nd.name = temp;
		cin >> temp;
		nd.month = stoi(temp.substr(0, 2));
		nd.day = stoi(temp.substr(3, 2));
		nd.hour = stoi(temp.substr(6, 2));
		nd.minute = stoi(temp.substr(9, 2));
		cin >> temp;
		if (temp == "on-line")
			nd.status = true;
		else
			nd.status = false;
		vec.push_back(nd);
	}

	sort(vec.begin(), vec.end(), cmp);


	for (int i = 0; i < vec.size(); i++)
	{
		node temp;
		temp = vec[i];
		if (!temp.status)
			continue;
		if (i != vec.size() - 1)
		{
			for (int j = i + 1; j < vec.size(); j++)
			{
				if (vec[j].name == vec[i].name&&vec[j].status == true)
					break;
				else if (vec[j].name == vec[i].name&&vec[j].status != true)
				{
					secNode sec;
					sec.mm = vec[i].month;
					sec.d1 = vec[i].day;
					sec.d2 = vec[j].day;
					sec.h1 = vec[i].hour;
					sec.h2 = vec[j].hour;
					sec.m1 = vec[i].minute;
					sec.m2 = vec[j].minute;
					nmap[vec[j].name].push_back(sec);
					break;
				}
			}
		}
	}

	map<string, vector<secNode>>::iterator miter = nmap.begin();
	int rnz = 0;
	for (; miter != nmap.end(); miter++)
	{
		rnz++;
		cout << (*miter).first << " " <<setfill('0')<<setw(2)<< (*miter).second[0].mm << endl;
		double to = 0;
		for (int i = 0; i < (*miter).second.size(); i++)
		{
			int totalmin = 0;
			cout << setfill('0') << setw(2) << (*miter).second[i].d1 << ":" << setfill('0') << setw(2) << (*miter).second[i].h1 << ":" << setfill('0') << setw(2) << (*miter).second[i].m1 << " " << setfill('0') << setw(2) << (*miter).second[i].d2 << ":" << setfill('0') << setw(2) << (*miter).second[i].h2 << ":" << setfill('0') << setw(2) << (*miter).second[i].m2 << " ";
			double zcent = double(calculatePrice((*miter).second[i],totalmin)) / 100;
			to += zcent;
			cout << totalmin << " $" << fixed << setprecision(2) << zcent << endl;
		}
		cout << "Total amount: $" << fixed << setprecision(2) << to;
		if (rnz != nmap.size())
			cout << endl;
	}


	system("pause");
	return 0;
}