#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> vec;
	vector<int> vec2;
	vector<int> vec3;
	string num;
	cin >> num;

	for (int i = 0; i < num.length(); i++)
	{
		int n1 = int(num[num.length() - i - 1]-48);
		vec2.push_back(n1);
		n1 = 2 * n1;
		vec.push_back(n1);

	}

	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > 9)
		{
			int a1 = vec[i] / 10;
			int a2 = vec[i] % 10;
			vec[i] = a2;
			if (i != vec.size() - 1)
				vec[i + 1] += a1;
			else
				vec.push_back(a1);
		}
	}

	vec3 = vec;

	sort(vec.begin(), vec.end());
	sort(vec2.begin(), vec2.end());

	if (vec.size() != vec2.size())
		cout << "No"<<endl;
	else
	{
		int flag = 0;
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] != vec2[i])
				flag = 1;
		}
		if (flag == 1)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec3[i];
	}

	system("pause");
	return 0;
}