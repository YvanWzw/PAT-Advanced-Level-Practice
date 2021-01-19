//1034 Head of a Gang(30分)
//One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains two positive numbers Nand K(both less than or equal to 1000), the number of phone callsand the weight threthold, respectively.Then N lines follow, each in the following format :
//
//Name1 Name2 Time
//where Name1and Name2 are the names of people at the two ends of the call, and Time is the length of the call.A name is a string of three capital letters chosen from A - Z.A time length is a positive integer which is no more than 1000 minutes.
//
//Output Specification :
//For each test case, first print in a line the total number of gangs.Then for each gang, print in a line the name of the headand the total number of the members.It is guaranteed that the head is unique for each gang.The output must be sorted according to the alphabetical order of the names of the heads.
//
//Sample Input 1:
//	8 59
//		AAA BBB 10
//		BBB AAA 20
//		AAA CCC 40
//		DDD EEE 5
//		EEE DDD 70
//		FFF GGG 30
//		GGG HHH 20
//		HHH FFF 10
//		Sample Output 1:
//	2
//		AAA 3
//		GGG 3
//		Sample Input 2 :
//		8 70
//		AAA BBB 10
//		BBB AAA 20
//		AAA CCC 40
//		DDD EEE 5
//		EEE DDD 70
//		FFF GGG 30
//		GGG HHH 20
//		HHH FFF 10
//		Sample Output 2:
//	0

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

class node
{
public:
	string end;
	int weight;

	bool operator > (const node& temp) const
	{
		return end > temp.end;
	}

	bool operator < (const node& temp) const
	{
		return end < temp.end;
	}
};

class res
{
public:
	int totalVisited = 0;
	int totalWeight = 0;
};

map<string, vector<node>> phone;
map<string, bool> hasVisited;
map<string, int> weight;

res dfs(string current, res ans)
{
	hasVisited[current] = true;
	ans.totalVisited++;
	if (phone.find(current) != phone.end())
	{
		vector<node> vec = phone[current];
		for (int i = 0; i < vec.size(); i++)
		{
			if (weight.find(current) != weight.end())

				weight[current] += vec[i].weight;
			else
				weight[current] = vec[i].weight;

			if (weight.find(vec[i].end) != weight.end())

				weight[vec[i].end] += vec[i].weight;
			else
				weight[vec[i].end] = vec[i].weight;

			ans.totalWeight += vec[i].weight;

			if (!hasVisited[vec[i].end])
			{
				ans = dfs(vec[i].end, ans);
			}
		}
	}
	return ans;

}

int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		node nod;
		string start;
		cin >> start;
		cin >> nod.end >> nod.weight;
		if (phone.find(start) == phone.end())
		{
			vector<node> vec;
			vec.push_back(nod);
			phone[start] = vec;
		}
		else
		{
			phone[start].push_back(nod);
		}
	}


	map<string, vector<node>>::iterator it = phone.begin();

	vector<node> resans;

	for (; it != phone.end(); it++)
	{
		if (hasVisited.find((*it).first) == hasVisited.end())
		{
			res ans;
			ans = dfs((*it).first, ans);
			if (ans.totalVisited > 2 && ans.totalWeight > K)
			{
				node nod;
				string maxWeiName;
				int maxWei = 0;
				for (map<string, bool>::iterator itVis = hasVisited.begin(); itVis != hasVisited.end(); itVis++)
				{
					if (weight.find((*itVis).first) != weight.end())
					{
						if (weight[(*itVis).first] > maxWei)
						{
							maxWei = weight[(*itVis).first];
							maxWeiName = (*itVis).first;
						}
					}
				}
				nod.end = maxWeiName;
				nod.weight = ans.totalVisited;
				resans.push_back(nod);
			}
			weight.clear();
		}
	}

	sort(resans.begin(), resans.end());

	cout << resans.size();
	if(resans.size()!=0)
		cout<<endl;                                                 
	for (int i = 0; i < resans.size(); i++)
	{
		cout << resans[i].end << " " << resans[i].weight;
		if (i != resans.size() - 1)
			cout << endl;
	}



	return 0;
}