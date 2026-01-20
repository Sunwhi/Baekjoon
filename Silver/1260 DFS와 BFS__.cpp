#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

void dfs(int v, const vector<int> adj[], vector<int>& result, int visited[])
{
	result.push_back(v); // 결과 vector에 추가
	visited[v] = 1; // 방문 체크

	for (int next : adj[v])
	{
		if (!visited[next])
		{
			dfs(next, adj, result, visited);
		}
	}
}
void bfs(int start, const vector<int> adj[], vector<int>& result, int visited[])
{
	queue<int> q; // 새롭게 bfs로 탐색할 노드들 저장

	q.push(start);
	result.push_back(start);
	visited[start] = 1;

	// queue에 들어있는 순서대로 방문
	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		// new_v 기준 : 방문한 적 없는 인접 노드들을 방문하고 queue에 넣는다.
		for (int next : adj[v])
		{
			if (!visited[next])
			{
				visited[next] = 1;
				result.push_back(next);
				q.push(next);
			}
		}
	}
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

	//////////////////////////////////////////
	// dfs
	dfs(v, adj, result, visited);

	for (auto i : result)
	{
		cout << i << " ";
	}

	//////////////////////////////////////////
	cout << '\n';

	fill(visited, visited + 1001, 0);

	result.clear();

	///////////////////////////////////////////
	// bfs

	bfs(v, adj, result, visited);

	for (auto i : result)
	{
		cout << i << " ";
	}

	return 0;
}