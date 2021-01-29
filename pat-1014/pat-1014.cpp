#include<iostream>
#include<queue>
using namespace std;
class quearr
{
public:
	queue<int> que;
};
int main()
{
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	int consumer[1000] = { 0 };
	for (int i = 0; i < k; i++)
		scanf("%d", &consumer[i]);
	int windows[20] = { 0 };
	int minutes[20] = { 0 };
	int time[1000] = { 0 };
	bool ser[1000] = { 0 };
	bool flag = true;
	int peo = k;
	quearr qu[20];
	while (flag)
	{
		int least = 0;
		for (int j = 0; j < n; j++)
		{
			if (windows[j] < windows[least])
			{
				least = j;
			}
		}
		if (windows[least] < m)
			flag = false;
		if (flag == false)
		{
			windows[least]++;
			qu[least].que.push(k - peo);
			peo--;
		}
		else
			flag = false;
		for (int j = 0; j < n; j++)
			if (windows[j] < m)
				flag = true;
		if (peo == 0)
			flag = false;
	}
	for (int i = 0; i < 1080; i++)
	{
		for (int j = 0; j < n; j++)
		{
			minutes[j]++;

			if (windows[j] != 0)
			{
				if (i < 540)
					ser[qu[j].que.front()] = true;
				if (consumer[qu[j].que.front()] == minutes[j])
				{
					time[qu[j].que.front()] = i + 1;
					qu[j].que.pop();
					windows[j]--;
					minutes[j] = 0;
				}
			}
		}

		if (peo != 0)
			flag = true;
		if (i < 540)
			while (flag)
			{
				int least = 0;
				for (int j = 0; j < n; j++)
				{
					if (windows[j] < windows[least])
					{
						least = j;
					}
				}
				if (windows[least] < m)
					flag = false;
				if (flag == false)
				{
					windows[least]++;
					qu[least].que.push(k - peo);
					peo--;
				}
				else
					flag = false;
				for (int j = 0; j < n; j++)
					if (windows[j] < m)
						flag = true;
				if (peo == 0)
					flag = false;
			}

	}

	for (int i = 0; i < q; i++)
	{
		int quer = 0;
		scanf("%d", &quer);
		int tt = time[quer - 1];
		int hour = (tt / 60) + 8;
		int minut = tt % 60;
		if (ser[quer - 1] == false)
			cout << "Sorry" << endl;
		else
		{
			if (hour < 10)
				cout << "0";
			cout << hour << ":";
			if (minut < 10)
				cout << "0";
			cout << minut << endl;
		}
	}

	system("pause");
	return 0;
}