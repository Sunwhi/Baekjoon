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
	// 새로 추가
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	//map<int, string> int_key;
	vector<string> int_v;
	map<string, int> string_map;

	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		//int_key.insert({ i + 1, name });
		int_v.push_back(name);
		string_map.insert({ name,i + 1 });
	}

	int pnumber;
	string pname;
	string problem;

	for (int i = 0; i < m; i++)
	{
		cin >> problem;

		// problem이 숫자면
		if (isdigit(problem[0]))
		{
			//auto it = int_key.find(int(stoi(problem))); // string을 int로 변경해서 검색
			//cout << it->second;
			cout << int_v[stoi(problem) - 1];
		}
		else // problem이 문자열이면
		{
			auto it = string_map.find((problem)); // string을 그대로 key로 검색
			cout << it->second;
		}
		cout << '\n';
	}
}