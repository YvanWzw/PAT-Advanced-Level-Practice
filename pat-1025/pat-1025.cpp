//1025 PAT Ranking(25分)
//Programming Ability Test(PAT) is organized by the College of Computer Science and Technology of Zhejiang University.Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test.Now it is your job to write a program to correctly merge all the ranklistsand generate the final rank.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains a positive number N(≤100), the number of test locations.Then N ranklists follow, each starts with a line containing a positive integer K(≤300), the number of testees, and then K lines containing the registration number(a 13 - digit number) and the total score of each testee.All the numbers in a line are separated by a space.
//
//Output Specification :
//For each test case, first print in one line the total number of testees.Then print the final ranklist in the following format :
//
//registration_number final_rank location_number local_rank
//The locations are numbered from 1 to N.The output must be sorted in nondecreasing order of the final ranks.The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
//
//Sample Input :
//2
//5
//1234567890001 95
//1234567890005 100
//1234567890003 95
//1234567890002 77
//1234567890004 85
//4
//1234567890013 65
//1234567890011 25
//1234567890014 100
//1234567890012 85
//Sample Output :
//9
//1234567890005 1 1 1
//1234567890014 1 2 1
//1234567890001 3 1 2
//1234567890003 3 1 2
//1234567890004 5 1 4
//1234567890012 5 2 2
//1234567890002 7 1 5
//1234567890013 8 2 3
//1234567890011 9 2 4

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class node
{
public:
	string no;
	short score;
	short location;
	short location_rank;
	short rank;

		bool operator < (const node& temp) const
		{
			if (score != temp.score)
				return score > temp.score;
			else
				return no < temp.no;
		}
};

int main()
{
	vector<node> student;
	int N = 0;
	int total = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int K = 0;
		cin >> K;
		total += K;
		vector<node> location;
		for (int j = 0; j < K; j++)
		{
			node stu;
			cin >> stu.no >> stu.score;
			stu.location = i + 1;
			location.push_back(stu);
		}
		sort(location.begin(), location.end());
		location[0].location_rank = 1;
		for (int j = 0; j < K; j++)
		{
			if (j != 0)
			{
				if (location[j].score == location[j - 1].score)
				{
					location[j].location_rank = location[j - 1].location_rank;
				}
				
				else
					location[j].location_rank = j + 1;
			}
			student.push_back(location[j]);
		}
	}
	sort(student.begin(), student.end());

	cout << total << endl;
	student[0].rank = 1;
	for (int i = 0; i < total; i++)
	{
		cout << student[i].no << " ";
		if (i != 0)
		{
			if (student[i].score == student[i - 1].score)
				student[i].rank = student[i - 1].rank;
			else
				student[i].rank = i + 1;

		}
		cout << student[i].rank << " " << student[i].location << " " << student[i].location_rank;
		if (i != total - 1)
			cout << endl;
	}


	return 0;
}