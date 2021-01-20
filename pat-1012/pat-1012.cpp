#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class gr
{
public:
	string id;
	int c0 = 0;
	int c1 = 0;
	int m0 = 0;
	int m1 = 0;
	int e0 = 0;
	int e1 = 0;
	int a0 = 0;
	int a1 = 0;
};
bool funcc(gr a, gr b)
{
	return a.c0 > b.c0;
}
bool funmm(gr a, gr b)
{
	return a.m0 > b.m0;
}
bool funee(gr a, gr b)
{
	return a.e0 > b.e0;
}
bool funaa(gr a, gr b)
{
	return a.a0 > b.a0;
}
int main()
{
	int n, m;
	cin >> n >> m;
	gr *stu = new gr[n];
	for (int i = 0; i < n; i++)
		cin >> stu[i].id >> stu[i].c0 >> stu[i].m0 >> stu[i].e0;
	string *check = new string[m];
	for (int i = 0; i < m; i++)
		cin >> check[i];
	for (int i = 0; i < n; i++)
		stu[i].a0 = (stu[i].c0 + stu[i].m0 + stu[i].e0) / 3;
	int cc = 0;
	int mm = 0;
	int ee = 0;
	int aa = 0;
	sort(stu, stu + n, funcc);
	int ppp = 1;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			stu[0].c1 = ppp;
		else if (stu[i].c0 < stu[i - 1].c0)
			stu[i].c1 = ppp;
		else
			stu[i].c1 = stu[i - 1].c1;
		ppp++;
	}
	/*for (int i = 0; i < n; i++)
		cout << stu[i].c0 << " " << stu[i].c1 << " " << stu[i].m0 << " " << stu[i].m1 << " " << stu[i].e0 << " " << stu[i].e1 << " " << stu[i].a0 << " " << stu[i].a1 << endl;
	*/
	sort(stu, stu + n, funmm);
	/*cout << endl;
	for (int i = 0; i < n; i++)
		cout << stu[i].c0 << " " << stu[i].c1 << " " << stu[i].m0 << " " << stu[i].m1 << " " << stu[i].e0 << " " << stu[i].e1 << " " << stu[i].a0 << " " << stu[i].a1 << endl;
	*/
	ppp = 1;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			stu[0].m1 = ppp;
		else if (stu[i].m0 < stu[i - 1].m0)
			stu[i].m1 = ppp;
		else
			stu[i].m1 = stu[i - 1].m1;
		ppp++;
	}
	sort(stu, stu + n, funee);
	ppp = 1;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			stu[0].e1 = ppp;
		else if (stu[i].e0 < stu[i - 1].e0)
			stu[i].e1 = ppp;
		else
			stu[i].e1 = stu[i - 1].e1;
		ppp++;
	}
	sort(stu, stu + n, funaa);
	ppp = 1;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			stu[0].a1 = ppp;
		else if (stu[i].a0 < stu[i - 1].a0)
			stu[i].a1 = ppp;
		else
			stu[i].a1 = stu[i - 1].a1;
		ppp++;
	}
	bool flag = false;
	int temp1 = 0;
	int temp2 = 0;
	char lesson[4] = { 'A','C','M','E' };
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (stu[j].id == check[i])
			{
				temp1 = stu[j].a1;
				temp2 = 0;
				if (stu[j].c1 < temp1)
				{
					temp1 = stu[j].c1;
					temp2 = 1;
				}

				if (stu[j].m1 < temp1)
				{
					temp1 = stu[j].m1;
					temp2 = 2;
				}

				if (stu[j].e1 < temp1)
				{
					temp1 = stu[j].e1;
					temp2 = 3;
				}
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			cout << temp1 << " " << lesson[temp2];
			flag = false;
			temp1 = 0;
			temp2 = 0;
		}
		else
			cout << "N/A";
		cout << endl;
	}

	delete[] stu;
	delete[] check;
	system("pause");
	return 0;
}