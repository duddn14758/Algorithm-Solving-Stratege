#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

// BFS¿Í DFS
using namespace std;

vector<int> v[1005];
bool visited[1005];

void DFS(int n) {
	if (visited[n])return;
	cout << n << " ";
	visited[n] = 1;
	for (int i = 0; i < v[n].size(); i++)
		DFS(v[n][i]);
}

void BFS(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 0; i < v[now].size(); i++) {
			if (!visited[v[now][i]]) {
				q.push(v[now][i]);
				visited[v[now][i]] = 1;
			}
		}
	}
}

int main() {
	int n, m, s,st,des;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		cin >> st >> des;
		v[st].push_back(des);
		v[des].push_back(st);
	}
	for (int i = 1; i <= n; i++)
		sort(v[i].begin(), v[i].end());
	DFS(s);
	memset(visited, 0, sizeof(visited));
	cout << endl;
	BFS(s);

	return 0;
}