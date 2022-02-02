//1051 Pop Sequence(25 ·Ö)
//Given a stack which can keep M numbers at most.Push N numbers in the order of 1, 2, 3, ..., Nand pop randomly.You are supposed to tell if a given sequence of numbers is a possible pop sequence of the stack.For example, if M is 5 and N is 7, we can obtain 1, 2, 3, 4, 5, 6, 7 from the stack, but not 3, 2, 1, 7, 5, 6, 4.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains 3 numbers(all no more than 1000): M(the maximum capacity of the stack), N(the length of push sequence), and K(the number of pop sequences to be checked).Then K lines follow, each contains a pop sequence of N numbers.All the numbers in a line are separated by a space.
//
//	Output Specification :
//																											  For each pop sequence, print in one line "YES" if it is indeed a possible pop sequence of the stack, or "NO" if not.
//
//																												  Sample Input :
//																											  5 7 5
//																												  1 2 3 4 5 6 7
//																												  3 2 1 7 5 6 4
//																												  7 6 5 4 3 2 1
//																												  5 6 4 3 7 2 1
//																												  1 7 6 5 4 3 2
//																												  Sample Output :
//																											  YES
//																												  NO
//																												  NO
//																												  YES
//																												  NO


#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	vector<bool> vec;
	for (int i = 0; i < K; i++)
	{
		stack<int> st;

		int cnt = 0;
		for (int j = 0; j < N; j++)
		{
			if (st.size() >= M)
			{
				for (int k = 0; k < N - j; k++)
				{
					int temp;
					cin >> temp;
				}
				break;
			}

			bool flag = true;
			int temp;
			cin >> temp;
			while (flag && cnt <= N)
			{
				if (!st.empty())
				{
					if (temp == st.top())
					{
						flag = false;
						st.pop();
						break;

					}
					else if (temp < st.top())
					{
						flag = false;
						for (int k = 0; k < N - j-1; k++)
						{
							cin >> temp;
						}
						j = N;
						break;
					}
				}
					
				

				cnt++;
				st.push(cnt);
			}



		}
		if (st.empty())
			vec.push_back(true);
		else
			vec.push_back(false);

	}

	for (int i = 0; i < K; i++)
	{
		if (vec[i])
			cout << "YES";
		else
			cout << "NO";

		if (i != K - 1)
			cout << endl;
	}

	return 0;
}