//1103 Integer Factorization(30 分)
//The K−P factorization of a positive integer N is to write N as the sum of the P - th power of K positive integers.You are supposed to write a program to find the K−P factorization of N for any positive integers N, Kand P.
//
//Input Specification :
//Each input file contains one test case which gives in a line the three positive integers N(≤400), K(≤N) and P(1 < P≤7).The numbers in a line are separated by a space.
//
//	Output Specification :
//For each case, if the solution exists, output in the format :
//
//N = n[1] ^ P + ... n[K] ^ P
//where n[i](i = 1, ..., K) is the i - th factor.All the factors must be printed in non - increasing order.
//
//Note : the solution may not be unique.For example, the 5 - 2 factorization of 169 has 9 solutions, such as 12
//2
//+ 4
//2
//+ 2
//2
//+ 2
//2
//+ 1
//2
//, or 11
//2
//+ 6
//2
//+ 2
//2
//+ 2
//2
//+ 2
//2
//, or more.You must output the one with the maximum sum of the factors.If there is a tie, the largest factor sequence must be chosen -- sequence{ a
//1
//​
// ,a
//2
//​
// ,⋯,a
//K
//​
//} is said to be larger than{ b
//1
//​
// ,b
//2
//​
// ,⋯,b
//K
//​
//} if there exists 1≤L≤K such that a
//i
//​
//= b
//i
//​
//for i<Land a
//	L
//	​
//>b
//L
//​
//.
//
//If there is no solution, simple output Impossible.
//
//Sample Input 1:
//169 5 2
//Sample Output 1 :
//	169 = 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 6 ^ 2 + 5 ^ 2
//	Sample Input 2 :
//	169 167 3
//	Sample Output 2 :
//	Impossible

//改编自柳神的代码

#include<iostream>
#include<vector>
#include <cmath>
#include<functional>
using namespace std;
int main() {
	int n, k, p, maxFacSum = -1;
	vector<int> v, ans, tempAns;
	cin >> n >> k >> p;
	auto init = [&]()
	{
		int temp = 0, index = 1;
		while (temp <= n)
		{
			v.push_back(temp);
			temp = pow(index, p);
			index++;
		}
	};
	init();
	tempAns.resize(k);
	function<void(int, int, int, int)> dfs = [&](int index, int tempSum, int tempK, int facSum)
	{
		if (tempK == k)
		{
			if (tempSum == n && facSum > maxFacSum)
			{
				ans = tempAns;
				maxFacSum = facSum;
			}
			return;
		}
		while (index >= 1)
		{
			if (tempSum + v[index] <= n)
			{
				tempAns[tempK] = index;
				dfs(index, tempSum + v[index], tempK + 1, facSum + index);
			}
			if (index == 1)
				return;
			index--;
		}
	};
	dfs(v.size() - 1, 0, 0, 0);
	if (maxFacSum == -1)
	{
		cout << "Impossible";
		return 0;
	}
	cout << n << " = ";
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << "^" << p;
		if (i != ans.size() - 1)
			cout << " + ";
	}
	return 0;
}