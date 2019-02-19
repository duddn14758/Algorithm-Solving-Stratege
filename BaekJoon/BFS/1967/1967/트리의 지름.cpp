#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v[10005];
int rd = 0, end_point;
bool visited[10005];

void BFS(int cnt, int node) {
	queue<pair<int,int>> q;
	for (int i = 0; i < v[node].size(); i++) {
		if (visited[v[node][i].first]) continue;
		visited[v[node][i].first] = 1;
		if (rd < cnt + v[node][i].second) {
			rd = cnt + v[node][i].second;
			end_point = v[node][i].first;
		}
		q.push({ v[node][i].first, cnt+v[node][i].second});
	}

	while (!q.empty()) {
		BFS(q.front().second,q.front().first);
		q.pop();
	}
}

void Init(int n) {
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
}

int main() {
	int n, buf1,buf2,buf3;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> buf1 >> buf2 >> buf3;
		v[buf1].push_back({ buf2,buf3 });
		v[buf2].push_back({ buf1,buf3 });		
	}

	/*for (int i = 1; i <= n; i++) {
		BFS(0, i);
		Init(n);
	}*/
	BFS(0, 1);
	Init(n);
	BFS(0, end_point);

	cout << rd;

	return 0;
}