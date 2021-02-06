#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Book
{
public:
	string id;
	string title;
	string author;
	vector<string> key_word;
	string publisher;
	string year;
};

class Query
{
public:
	string content;
	vector<string> id;
};

int main()
{
	map<string, vector<string>> title;
	map<string, vector<string>> author;
	map<string, vector<string>> key_word;
	map<string, vector<string>> publisher;
	map<string, vector<string>> year;

	int number;
	cin >> number;
	cin.ignore();
	for (int i = 0; i < number; i++)
	{
		string id;
		getline(cin, id);
		string temp;
		getline(cin, temp);
		title[temp].push_back(id);
		getline(cin, temp);
		author[temp].push_back(id);
		getline(cin, temp);
		string temp2 = "";
		for (int j = 0; j <= temp.size(); j++)
		{
			if (temp[j] != ' '&&j != temp.size() - 1)
				temp2 += temp[j];
			else
			{
				if (j == temp.size() - 1)
					temp2 += temp[j];
				key_word[temp2].push_back(id);
				temp2 = "";
			}
		}
		getline(cin, temp);
		publisher[temp].push_back(id);
		getline(cin, temp);
		year[temp].push_back(id);
	}

	vector<Query> vec;
	Query query;
	int query_number;
	cin >> query_number;
	cin.ignore();
	for (int i = 0; i < query_number; i++)
	{
		string temp;
		getline(cin, temp);
		string code;
		code = temp.substr(0, 1);
		string content;
		content = temp.substr(3);
		query.content = temp;

		if (code == "1")
		{
			if (title.find(content) != title.end())
			{
				sort(title[content].begin(), title[content].end());
				query.id = title[content];
			}
			
			else
				query.id.push_back("Not Found");
		}

		if (code == "2")
		{
			if (author.find(content) != author.end())
			{
				sort(author[content].begin(), author[content].end());
				query.id = author[content];
			}
			else
				query.id.push_back("Not Found");
		}
		if (code == "3")
		{
			if (key_word.find(content) != key_word.end())
			{
				sort(key_word[content].begin(), key_word[content].end());
				query.id = key_word[content];
			}
			else
				query.id.push_back("Not Found");
		}
		if (code == "4")
		{
			if (publisher.find(content) != publisher.end())
			{
				sort(publisher[content].begin(), publisher[content].end());
				query.id = publisher[content];
			}
			else
				query.id.push_back("Not Found");
		}

		if (code == "5")
		{
			if (year.find(content) != year.end())
			{
				sort(year[content].begin(), year[content].end());
				query.id = year[content];
			}
			else
				query.id.push_back("Not Found");
		}

		vec.push_back(query);
		query.id.clear();
	}

	for (int i = 0; i < query_number; i++)
	{
		cout << vec[i].content << endl;
		for (int j = 0; j < vec[i].id.size(); j++)
		{
			cout << vec[i].id[j];
			if (i != query_number - 1 || j != vec[i].id.size() - 1)
				cout << endl;
		}
	}


	system("pause");
	return 0;
}

