#include <iostream>
#include <vector>
#include <queue>
#define Pii pair<int,int>

// 상근이의 여행
using namespace std;

bool visited[1001];
vector<int> v[1001];

int bfs() {
	queue<Pii> q;
	q.push({ 1,0 });
	visited[1] = 1;
	int cnt = 0;
	while (!q.empty()) {
		Pii now = q.front();
		q.pop();
		for (int i = 0; i < v[now.first].size(); i++) {
			if (!visited[v[now.first][i]]) {
				visited[v[now.first][i]] = 1;
				q.push({ v[now.first][i],now.second + 1 });
				cnt++;
			}
		}
	}
	return cnt;
}

void Init(int n) {
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
}

int main() {
	int t, n, m,st,des;

	cin >> t;
	while (t-- > 0) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> st >> des;
			v[st].push_back(des);
			v[des].push_back(st);
		}
		cout << bfs() << endl;		
		for (int i = 1; i <= n; i++) 
			v[i].clear();		
		Init(n);
	}

	return 0;
}