#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
using namespace std;

bool isNumber(const string& s)
{
	for (char c : s)
	{
		if (!isdigit(c)) return false;
	}
	return true;
}
int main()
{
	int n, m;
	cin >> n >> m;

	map<int, string> int_key;
	map<string, int> string_key;

	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		int_key.insert({ i + 1, name });
		string_key.insert({ name,i + 1 });
	}

	int pnumber;
	string pname;
	string problem;

	for (int i = 0; i < m; i++)
	{
		cin >> problem;

		if (isNumber(problem))
		{
			auto it = int_key.find(int(stoi(pname)));
		}
	}
}