#include<iostream>
using namespace std;
int main()
{
	int k;
	cin >> k;
	int *arr = new int[k];
	for (int i = 0; i < k; i++)
		cin >> arr[i];
	int begin_i = 0;
	int end_i = 0;
	int sum = 0;
	int sum_temp = 0;

	for (int i = 0; i < k; i++)
	{
		if (arr[i] >= 0)
		{
			sum_temp = arr[i];
			if (sum_temp > sum)
			{
				begin_i = i;
				end_i = i;
				sum = sum_temp;
			}
			for (int j = i + 1; j < k; j++)
			{
				sum_temp += arr[j];

				if (sum_temp > sum)
				{
					begin_i = i;
					end_i = j;
					sum = sum_temp;
				}
			}
		}

	}
	if (begin_i == 0 && end_i == 0)
		end_i = k-1;

	int qww = 0;
	for (int i = 0; i < k; i++)
	{
		if (arr[i] == 0)
			qww++;
	}
	if (qww == k)
	{
		begin_i = 0;
		end_i = 0;
		sum = 0;
	}
	int wwq = 0;
	for (int i = 0; i < k; i++)
	{
		if (arr[i] > 0)
			wwq++;
	}
	int www = 0;
	for (int i = 0; i < k; i++)
	{
		if (arr[i] == 0)
		{
			www = i;
			break;
		}
		
	}
	if (qww != 0 && sum == 0)
	{
		begin_i = www;
		end_i = www;
	}

	cout << sum << " " << arr[begin_i] << " " << arr[end_i];

	delete[] arr;

	return 0;
}