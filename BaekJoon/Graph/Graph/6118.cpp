#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 숨바꼭질
using namespace std;

vector<int> barn[20001];
vector<int> len[20001];
bool visited[20001];
int n, m;

int bfs() {		// 가장 먼 헛간까지의 거리를 리턴해준다.
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ 1,0 });
	visited[1] = 1;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		cnt = cur.second;
		len[cnt].push_back(cur.first);
		q.pop();
		for (int i = 0; i < barn[cur.first].size(); i++) {
			if (!visited[barn[cur.first][i]]) {
				q.push({ barn[cur.first][i],cur.second+1 });
				visited[barn[cur.first][i]] = 1;
			}
		}
	}
	return cnt;
}


int main() {
	int b1, b2, cnt = 0;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> b1 >> b2;;
		barn[b1].push_back(b2);
		barn[b2].push_back(b1);
	}
	cnt = bfs();
	int ans = len[cnt][0];
	for (int i = 1; i < len[cnt].size(); i++) {
		ans = min(ans, len[cnt][i]);
	}
	cout << ans << " " << cnt << " " << len[cnt].size();

	return 0;
}