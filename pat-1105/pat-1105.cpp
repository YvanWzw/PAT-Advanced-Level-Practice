//1105 Spiral Matrix(25 分)
//This time your job is to fill a sequence of N positive integers into a spiral matrix in non - increasing order.A spiral matrix is filled in from the first element at the upper - left corner, then move in a clockwise spiral.The matrix has m rowsand n columns, where mand n satisfy the following : m×n must be equal to N; m≥n;and m−n is the minimum of all the possible values.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line gives a positive integer N.Then the next line contains N positive integers to be filled into the spiral matrix.All the numbers are no more than 10
//4
//.The numbers in a line are separated by spaces.
//
//Output Specification :
//For each test case, output the resulting matrix in m lines, each contains n numbers.There must be exactly 1 space between two adjacent numbers, and no extra space at the end of each line.
//
//Sample Input :
//12
//37 76 20 98 76 42 53 95 60 81 58 93
//Sample Output :
//98 95 93
//42 37 81
//53 20 76
//58 60 76
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int N, row, col;
	cin >> N;
	int matrix[101][101]{ 0 };
	for (int i = sqrt(N); i >= 1; i--)
	{
		if (N % i == 0)
		{
			row = N / i;
			col = i;
			break;
		}
	}
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		vec.push_back(temp);
	}

	sort(vec.begin(), vec.end(), greater<int>());

	int fx = 0;//方向 0向右 1向下 2向左 3向上
	int x = 0, y = 0;
	int a = row, b = col;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		matrix[y][x] = vec[i];
		count++;
		if (fx == 0)
		{
			if (count == b)
			{
				fx = 1;
				count = 0;
				a--;
				y++;
				continue;
			}
			x++;
		}
		else if (fx == 1)
		{
			if (count == a)
			{
				fx = 2;
				count = 0;
				b--;
				x--;
				continue;
			}
			y++;
		}
		else if (fx == 2)
		{
			if (count == b)
			{
				fx = 3;
				count = 0;
				a--;
				y--;
				continue;
			}
			x--;
		}
		else if (fx == 3)
		{
			if (count == a)
			{
				fx = 0;
				count = 0;
				b--;
				x++;
				continue;
			}
			y--;
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j];
			if (j != col - 1)
				cout << " ";
		}
		if (i != row - 1)
			cout << endl;
	}
		
			


	return 0;
}