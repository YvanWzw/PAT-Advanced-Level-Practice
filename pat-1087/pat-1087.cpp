//1087 All Roads Lead to Rome(30 分)
//Indeed there are many different tourist routes from our city to Rome.You are supposed to find your clients the route with the least cost while gaining the most happiness.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains 2 positive integers N(2≤N≤200), the number of cities, and K, the total number of routes between pairs of cities; followed by the name of the starting city.The next N−1 lines each gives the name of a cityand an integer that represents the happiness one can gain from that city, except the starting city.Then K lines follow, each describes a route between two cities in the format City1 City2 Cost.Here the name of a city is a string of 3 capital English letters, and the destination is always ROM which represents Rome.
//
//Output Specification :
//For each test case, we are supposed to find the route with the least cost.If such a route is not unique, the one with the maximum happiness will be recommanded.If such a route is still not unique, then we output the one with the maximum average happiness -- it is guaranteed by the judge that such a solution existsand is unique.
//
//Hence in the first line of output, you must print 4 numbers: the number of different routes with the least cost, the cost, the happiness, and the average happiness(take the integer part only) of the recommanded route.Then in the next line, you are supposed to print the route in the format City1->City2->...->ROM.
//
//	Sample Input :
//6 7 HZH
//ROM 100
//PKN 40
//GDN 55
//PRS 95
//BLN 80
//ROM GDN 1
//BLN ROM 1
//HZH PKN 1
//PRS ROM 2
//BLN HZH 2
//PKN GDN 1
//HZH PRS 1
//Sample Output :
//3 3 195 97
//HZH->PRS->ROM

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;


class happiness
{
public:
	int index;
	int data;
};

class route
{
public:
	int start;
	int end;
	int data;
};

class path
{
public:
	vector<int> p;
	int rou;
	int hpy;
};

int N, K;
string root;
map<string, int> index;
map<int, string> rindex;
map<int, vector<route>> mr;
vector<happiness> h;
//vector<route> r;
vector<path> res;
int rom = 0;
int minCost = 0x7fffffff;

void dfs(int now, vector<bool> isVis, vector<int> pa, int rou, int hpy, int data)
{
	pa.push_back(now);
	rou += data;
	hpy += h[now].data;
	isVis[now] = true;

	if (now == rom)
	{
		if (minCost > rou)
		{
			res.clear();
			minCost = rou;
		}
		else if (minCost < rou)
			return;
		path pat;
		pat.p = pa;
		pat.rou = rou;
		pat.hpy = hpy;
		res.push_back(pat);
	}
	for (auto i : mr[now])
	{
		if (i.start == now && isVis[i.end] == false)
		{
			if (rou + i.data <= minCost)
				dfs(i.end, isVis, pa, rou, hpy, i.data);
		}
	}
}

bool cmp(path x, path y)
{
	if (x.rou != y.rou)
		return x.rou < y.rou;
	else if (x.hpy != y.hpy)
		return x.hpy > y.hpy;
	else
		return x.hpy / (x.p.size() - 1) > y.hpy / (y.p.size() - 1);
}

int main()
{

	cin >> N >> K >> root;
	index[root] = 0;
	rindex[0] = root;
	vector<bool> isVis;
	isVis.push_back(true);
	happiness temp;
	temp.index = 0;
	temp.data = 0;
	h.push_back(temp);
	for (int i = 1; i < N; i++)
	{
		string temp;
		temp.resize(3);
		int happy;
		scanf("%s%d", &temp[0], &happy);
		//cin >> temp >> happy;
		happiness hp;
		index[temp] = i;
		rindex[i] = temp;
		hp.index = i;
		hp.data = happy;
		h.push_back(hp);
		if (temp == "ROM")
			rom = i;
		isVis.push_back(false);
	}

	for (int i = 0; i < K; i++)
	{
		vector<route> temp;
		mr[i] = temp;
	}

	for (int i = 0; i < K; i++)
	{
		route ro;
		string start, end;
		int temp;
		start.resize(3);
		end.resize(3);
		scanf("%s%s%d", &start[0], &end[0], &temp);
		//cin >> start >> end >> temp;
		ro.start = index[start];
		ro.end = index[end];
		ro.data = temp;
		mr[ro.start].push_back(ro);
		ro.start = index[end];
		ro.end = index[start];
		mr[ro.start].push_back(ro);
		//r.push_back(ro);
	}

	vector<int> pa;

	dfs(0, isVis, pa, 0, 0, 0);

	sort(res.begin(), res.end(), cmp);

	cout << res.size() << " " << res[0].rou << " " << res[0].hpy << " " << res[0].hpy / (res[0].p.size() - 1) << endl;
	for (int i = 0; i < res[0].p.size(); i++)
	{
		cout << rindex[res[0].p[i]];
		if (i != res[0].p.size() - 1)
			cout << "->";
	}

	return 0;
}