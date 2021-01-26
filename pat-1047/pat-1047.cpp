
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	map<int, set<string>> stuList;
	for (int i = 0; i < N; i++)
	{
		char stuName[5];
		scanf("%s", stuName, 5);
		int courNum;
		scanf("%d", &courNum);
		for (int j = 0; j < courNum; j++)
		{
			int courId;
			scanf("%d", &courId);
			if (stuList.find(courId) != stuList.end())
			{
				stuList[courId].insert(stuName);
			}
			else
			{
				set<string> vec = { stuName };
				stuList[courId] = vec;
			}
		}
	}
	for (int i = 0; i < K; i++)
	{
		printf("%d %d\n", i + 1, stuList[i + 1].size());
		int j = 0;
		for (auto it : stuList[i + 1])
		{
			printf("%s", &it[0]);
			if (j != stuList[i + 1].size() - 1 || i != K - 1)
				printf("\n");
			j++;
		}
	}

	return 0;
}