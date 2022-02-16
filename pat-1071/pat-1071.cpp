//原PAT网站的提交将被合并至拼题A网站用户的对应题目集中。
//
//1071 Speech Patterns(25 分)
//People often have a preference among synonyms of the same word.For example, some may prefer "the police", while others may prefer "the cops".Analyzing such patterns can help to narrow down a speaker's identity, which is useful when validating, for example, whether it's still the same person behind an online avatar.
//
//Now given a paragraph of text sampled from someone's speech, can you find the person's most commonly used word ?
//
//Input Specification :
//Each input file contains one test case.For each case, there is one line of text no more than 1048576 characters in length, terminated by a carriage return \n.The input contains at least one alphanumerical character, i.e., one character from the set[0 - 9 A - Z a - z].
//
//Output Specification :
//For each test case, print in one line the most commonly occurring word in the input text, followed by a spaceand the number of times it has occurred in the input.If there are more than one such words, print the lexicographically smallest one.The word should be printed in all lower case.Here a "word" is defined as a continuous sequence of alphanumerical characters separated by non - alphanumerical characters or the line beginning / end.
//
//Note that words are case insensitive.
//
//Sample Input :
//Can1: "Can a can can a can?  It can!"
//Sample Output :
//can 5

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() 
{
	string temp, lin;
	getline(cin, lin);
	map<string, int> ans;
	for (int i = 0; i < lin.length(); i++)
	{
		if (isalnum(lin[i]))
		{
			lin[i] = tolower(lin[i]);
			temp += lin[i];
		}
		if (!isalnum(lin[i]) || i == lin.length() - 1) 
		{
			if (temp.length() != 0) 
				ans[temp]++;
			temp = "";
		}
	}

	int maxn = 0;
	for (auto i : ans)
	{
		if (i.second > maxn)
		{
			maxn = i.second;
			temp = i.first;
		}
	}
	cout << temp << " " << maxn << endl;
	return 0;
}