#include<iostream>
#include<string>
using namespace std;
class Time_a
{
public:
	int hour;
	int min;
	int sec;
};
class info
{
public:
	string id;
	Time_a enter;
	Time_a exit;
};
int er(Time_a a,Time_a b)
{
	if (a.hour > b.hour)
		return 1;
	else if (a.hour < b.hour)
		return 2;
	else if (a.hour == b.hour)
	{
		if (a.min > b.min)
			return 1;
		else if (a.min < b.min)
			return 2;
		else if (a.min == b.min)
		{
			if (a.sec > b.sec)
				return 1;
			else if (a.sec < b.sec)
				return 2;
			else
				return 3;
		}
	}
}
int main()
{
	int num;
	cin >> num;
	string temp;
	info *in = new info[num];
	for (int i = 0; i < num; i++)
	{
		cin >> in[i].id;
		cin >> temp;
		in[i].enter.hour = stoi(temp.substr(0, 2));
		in[i].enter.min = stoi(temp.substr(3, 2));
		in[i].enter.sec = stoi(temp.substr(6, 2));
		cin >> temp;
		in[i].exit.hour = stoi(temp.substr(0, 2));
		in[i].exit.min = stoi(temp.substr(3, 2));
		in[i].exit.sec = stoi(temp.substr(6, 2));
	}
	int flag_s = 0;
	int flag_e = 0;
	for (int i = 0; i < num; i++)
	{
		if (er(in[i].enter, in[flag_s].enter) == 2)
			flag_s = i;
		if (er(in[i].exit, in[flag_e].exit) == 1)
			flag_e = i;
	}
	cout << in[flag_s].id << " " << in[flag_e].id;


	delete[] in;
	//system("pause");
	return 0;
}