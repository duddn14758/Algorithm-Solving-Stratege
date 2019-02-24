#include <iostream>
#include <vector>
#include <queue>

// 연결 요소의 갯수
using namespace std;

vector <int> v[1005];
bool visited[1005];

void BFS(int n) {
	queue<int> q;

	for (int i = 0; i < v[n].size(); i++) {
		if (!visited[v[n][i]]) q.push(v[n][i]);
		visited[v[n][i]] = 1;
	}

	while (!q.empty()) {
		BFS(q.front());
		q.pop();
	}
}

int main() {
	int n, m, buf1, buf2, cnt = 0;
	cin >> n >> m;
	queue <pair<int, int>> q;

	for (int i = 0; i < m; i++) {
		cin >> buf1 >> buf2;
		v[buf1].push_back(buf2);
		v[buf2].push_back(buf1);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			BFS(i);
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}