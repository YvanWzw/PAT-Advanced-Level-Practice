//1067 Sort with Swap(0, i) (25 分)
//Given any permutation of the numbers {
//	0, 1, 2, ..., N−1
//}, it is easy to sort them in increasing order.But what if Swap(0, *) is the ONLY operation that is allowed to use ? For example, to sort{ 4, 0, 2, 1, 3 } we may apply the swap operations in the following way :
//
//	Swap(0, 1) = > {4, 1, 2, 0, 3}
//	Swap(0, 3) = > {4, 1, 2, 3, 0}
//	Swap(0, 4) = > {0, 1, 2, 3, 4}
//	Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.
//
//		Input Specification :
//	Each input file contains one test case, which gives a positive N(≤10
//		5
//	) followed by a permutation sequence of {
//		0, 1, ..., N−1
//	}. All the numbers in a line are separated by a space.
//
//		Output Specification :
//		For each case, simply print in a line the minimum number of swaps need to sort the given permutation.
//
//			Sample Input :
//		10
//			3 5 7 2 6 4 9 0 8 1
//			Sample Output :
//		9


//方法1，牛客AC，PAT TLE

#include<iostream>
#include<vector>
#include<map>
using namespace std;
//int cnt = 0;
//map<int, int> m;
//void deal(vector<int>& vec, int zero)
//{
//	if (zero == 0)
//	{
//		for (int i = 0; i < vec.size(); i++)
//		{
//			if (i != vec[i])
//			{
//				cnt++;
//				m[vec[zero]] = vec[i];
//				m[vec[i]] = vec[zero];
//				swap(vec[zero], vec[i]);
//				deal(vec, i);
//				break;
//			}
//		}
//	}
//	else
//	{
//		cnt++;
//		int temp = m[zero];
//		swap(vec[zero], vec[temp]);
//		m[zero] = zero;
//		m[0] = temp;
//		deal(vec, temp);
//	}
//}
//int main()
//{
//	int num, zero = 0;
//	cin >> num;
//	vector<int> vec;
//	for (int i = 0; i < num; i++)
//	{
//		int temp;
//		scanf("%d", &temp);
//		if (temp == 0)
//			zero = i;
//		m[temp] = i;
//		vec.push_back(temp);
//	}
//	deal(vec, zero);
//	cout << cnt;
//	return 0;
//}


//方法2


int n;
int main() {
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != i) {//如果元素没有放对位置
            while (a[i] != i) {//直到找到该位置对应元素
                swap(a[i], a[a[i]]);
                num += 1;
            }
            if (i != 0) num += 2;//第0位有0参与，其他位均多两次交换
        }
    }
    cout << num << endl;
}
