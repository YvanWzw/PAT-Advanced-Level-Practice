//1080 Graduate Admission(30 分)
//It is said that in 2011, there are about 100 graduate schools ready to proceed over 40, 000 applications in Zhejiang Province.It would help a lot if you could write a program to automate the admission procedure.
//
//Each applicant will have to provide two grades : the national entrance exam grade G
//E
//​
//, and the interview grade G
//I
//​
//.The final grade of an applicant is(G
//	E
//	​
//	+ G
//	I
//	​
//) / 2. The admission rules are :
//
//The applicants are ranked according to their final grades, and will be admitted one by one from the top of the rank list.
//
//If there is a tied final grade, the applicants will be ranked according to their national entrance exam grade G
//E
//​
//.If still tied, their ranks must be the same.
//
//Each applicant may have K choicesand the admission will be done according to his / her choices : if according to the rank list, it is one's turn to be admitted; and if the quota of one's most preferred shcool is not exceeded, then one will be admitted to this school, or one's other choices will be considered one by one in order. If one gets rejected by all of preferred schools, then this unfortunate applicant will be rejected.
//
//If there is a tied rank, and if the corresponding applicants are applying to the same school, then that school must admit all the applicants with the same rank, even if its quota will be exceeded.
//
//Input Specification :
//Each input file contains one test case.
//
//Each case starts with a line containing three positive integers : N(≤40, 000), the total number of applicants; M(≤100), the total number of graduate schools;and K(≤5), the number of choices an applicant may have.
//
//In the next line, separated by a space, there are M positive integers.The i - th integer is the quota of the i - th graduate school respectively.
//
//Then N lines follow, each contains 2 + K integers separated by a space.The first 2 integers are the applicant's G 
//E
//​
//and G
//I
//​
//, respectively.The next K integers represent the preferred schools.For the sake of simplicity, we assume that the schools are numbered from 0 to M−1, and the applicants are numbered from 0 to N−1.
//
//Output Specification :
//For each test case you should output the admission results for all the graduate schools.The results of each school must occupy a line, which contains the applicants' numbers that school admits. The numbers must be in increasing order and be separated by a space. There must be no extra space at the end of each line. If no applicant is admitted by a school, you must output an empty line correspondingly.
//
//Sample Input :
//11 6 3
//2 1 2 2 2 3
//100 100 0 1 2
//60 60 2 3 5
//100 90 0 3 4
//90 100 1 2 0
//90 90 5 1 3
//80 90 1 0 2
//80 80 0 1 2
//80 80 0 1 2
//80 70 1 3 2
//70 80 1 2 3
//100 100 0 2 4
//Sample Output :
//0 10
//3
//5 6 7
//2 8
//
//1 4

#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class student
{
public:
	int id;
	int ge;
	int gi;
	vector<int> sch;
	double score;

	bool operator<(const student& a)
	{
		if (a.score < score)
			return true;
		else if (a.score == score)
			return a.ge < ge ? true : false;
		else
			return false;
	}
};

int main()
{
	//input
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> school;
	vector<vector<int>>schoolStu;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		school.push_back(temp);
	}

	vector<student> vec;
	for (int i = 0; i < N; i++)
	{
		student stu;
		stu.id = i;
		cin >> stu.ge >> stu.gi;
		int temp;
		for (int j = 0; j < K; j++)
		{
			cin >> temp;
			stu.sch.push_back(temp);
		}
		stu.score = ((double)stu.ge + stu.gi) / 2;
		vec.push_back(stu);
	}

	//deal
	if (M > 0)
	{
		sort(vec.begin(), vec.end());

		for (int i = 0; i < M; i++)
		{
			vector<int> ss;
			schoolStu.push_back(ss);
		}

		for (int i = 0; i < N; i++)
		{
			if (i == 52)
				cout << "a";
			for (int j = 0; j < K; j++)
			{
				int tarSch = vec[i].sch[j];
				if (schoolStu[tarSch].size() < school[tarSch])
				{
					schoolStu[tarSch].push_back(i);
					break;
				}
				else
				{
					if (schoolStu[tarSch].size() >= school[tarSch] && school[tarSch] > 0)
					{
						int tarSchSize = schoolStu[tarSch].size();
						int tarSchLastStuRank = schoolStu[tarSch][tarSchSize - 1];
						if (vec[i].score == vec[tarSchLastStuRank].score && vec[i].ge == vec[tarSchLastStuRank].ge)
						{
							schoolStu[tarSch].push_back(i);
							break;
						}
					}
				}
			}
		}

		//output
		vector<vector<int>> result;
		for (int i = 0; i < M; i++)
		{
			vector<int> temp;
			result.push_back(temp);
			if (!schoolStu[i].empty())
			{
				for (int j = 0; j < schoolStu[i].size(); j++)
				{
					result[i].push_back(vec[schoolStu[i][j]].id);
				}
				sort(result[i].begin(), result[i].end());
			}
		}

		for (int i = 0; i < M; i++)
		{

			if (!result[i].empty())
			{
				for (int j = 0; j < result[i].size(); j++)
				{
					cout << result[i][j];
					if (j != result[i].size() - 1)
						cout << " ";
				}
			}
			if (i != M - 1)
				cout << endl;
		}

	}
	
	return 0;
}