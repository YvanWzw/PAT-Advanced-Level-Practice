//1044 Shopping in Mars(25分)
//Shopping in Mars is quite a different experience.The Mars people pay by chained diamonds.Each diamond has a value(in Mars dollars M$).When making the payment, the chain can be cut at any position for only onceand some of the diamonds are taken off the chain one by one.Once a diamond is off the chain, it cannot be taken back.For example, if we have a chain of 8 diamonds with values M$3, 2, 1, 5, 4, 6, 8, 7, and we must pay M$15.We may have 3 options:
//
//Cut the chain between 4 and 6, and take off the diamonds from the position 1 to 5 (with values 3 + 2 + 1 + 5 + 4 = 15).
//Cut before 5 or after 6, and take off the diamonds from the position 4 to 6 (with values 5 + 4 + 6 = 15).
//Cut before 8, and take off the diamonds from the position 7 to 8 (with values 8 + 7 = 15).
//Now given the chain of diamond values and the amount that a customer has to pay, you are supposed to list all the paying options for the customer.
//
//If it is impossible to pay the exact amount, you must suggest solutions with minimum lost.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains 2 numbers: N(≤10
//	​5
//	​​), the total number of diamonds on the chain, and M(≤10
//		​8
//		​​), the amount that the customer has to pay.Then the next line contains N positive numbers D
//	​1
//	​​ ⋯D
//	​N
//	​​(D
//		​i
//		​​ ≤10
//		​3
//		​​  for all i = 1, ⋯, N) which are the values of the diamonds.All the numbers in a line are separated by a space.
//
//	Output Specification :
//																					   For each test case, print i - j in a line for each pair of i ≤ j such that Di + ... + Dj = M.Note that if there are more than one solution, all the solutions must be printed in increasing order of i.
//
//																						   If there is no solution, output i - j for pairs of i ≤ j such that Di + ... + Dj > M with(Di + ... + Dj −M) minimized.Again all the solutions must be printed in increasing order of i.
//
//																						   It is guaranteed that the total value of diamonds is sufficient to pay the given amount.
//
//																						   Sample Input 1:
//																					   16 15
//																						   3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13
//																						   Sample Output 1 :
//																						   1 - 5
//																						   4 - 6
//																						   7 - 8
//																						   11 - 11
//																						   Sample Input 2 :
//																						   5 13
//																						   2 4 5 7 9
//																						   Sample Output 2 :
//																						   2 - 4
//																						   4 - 5

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[100001] = { 0 };
void find(int left, int right, int num)
{

}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	int left = 1, right = 1;
	int sum = arr[1];
	vector<pair<int, int>> ans;
	int minAns = 0x7fffffff;
	while (left != N + 1)
	{

		if (sum < M && right != N)
		{
			right++;
			sum += arr[right];
		}
		else if (sum < M && right == N)
		{
			break;
		}


		if (sum == M)
		{
			if (sum < minAns)
			{
				ans.clear();
				minAns = sum;
			}
			ans.push_back(pair<int, int>(left, right));
			if (right == N)
				break;
			right++;
			left++;
			sum += arr[right];
			sum -= arr[left-1];
		}


		if (sum > M)
		{
			if (sum < minAns)
			{
				ans.clear();
				minAns = sum;
				ans.push_back(pair<int, int>(left, right));
			}
			else if (sum == minAns)
			{
				ans.push_back(pair<int, int>(left, right));
			}
			left++;
			sum -= arr[left - 1];
		}
	}
	for (auto it : ans)
	{
		cout << it.first << "-" << it.second;
		if (it.first != ans[ans.size() - 1].first && it.second != ans[ans.size() - 1].second)
			cout << endl;
	}


	return 0;
}