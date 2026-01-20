#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

vector<int>& dfs(int v, const vector<int> adj[], vector<int>& result, int visited[])
{
	result.push_back(v); // 결과 vector에 추가
	visited[v] = 1; // 방문 체크

	int new_v;
	for (int i = 0; i < adj[v].size(); i++)
	{
		new_v = adj[v][i];

		if (visited[new_v]) continue;	// 방문했으면 패스
		else   // 방문 안했으면 재귀
		{
			result = dfs(new_v, adj, result, visited);
		}
	}

	return result;
}
vector<int>& bfs(int origin_v, const vector<int> adj[], vector<int>& result, int visited[], queue<int>& q)
{
	//queue<int> q; // 새롭게 bfs로 탐색할 노드들 저장
	result.push_back(origin_v);
	visited[origin_v] = 1;

	int new_v;

	q.push(origin_v);

	// queue에 들어있는 순서대로 방문
	while (!q.empty())
	{
		new_v = q.front();
		q.pop();

		// new_v 기준 : 방문한 적 없는 인접 노드들을 방문하고 queue에 넣는다.
		for (int i = 0; i < adj[new_v].size(); i++)
		{
			int temp = adj[new_v][i];
			if (visited[temp]) continue;
			else
			{
				q.push(temp);
				visited[temp] = 1;
				result.push_back(temp);
			}
		}
	}

	return result;
}
int main()
{
	vector<int> adj[1001];
	vector<int> result;
	int visited[1001]{}; // 0으로 초기화

	int n, m, v;
	cin >> n >> m >> v;

	int v1, v2;
	for (int i = 0; i < m; i++)
	{
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	for (int i = 1; i < n + 1; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}

	result.reserve(n);
	result = dfs(v, adj, result, visited);

	for (auto i : result)
	{
		cout << i << " ";
	}

	cout << '\n';

	memset(visited, 0, sizeof(visited));

	result.clear();
	queue<int> q;

	result = bfs(v, adj, result, visited, q);

	for (auto i : result)
	{
		cout << i << " ";
	}

	return 0;
}