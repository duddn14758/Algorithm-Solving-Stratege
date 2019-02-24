#include <stdio.h>
#include <queue>

using namespace std;
// 벽부수고 이동하기 using BFS

bool maze[1001][1001];
bool visited[1001][1001][2];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool canGo(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1)
		return 0;
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	char buf[1001];
	std::queue<std::pair<std::pair<int, int>, int>> q;
	int result = 1;

	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < m; j++) {
			maze[i][j] = buf[j] - '0';
		}
	}

	q.push(make_pair(make_pair(0, 0), 0));
	visited[0][0][0] = 1;
	while (!q.empty()) {
		int qsize = q.size();
		pair<pair<int, int>, int> cur;
		bool reach = false;
		for (int i = 0; i < qsize; i++) {
			cur = q.front();
			if (cur.first.first == n - 1 && cur.first.second == m - 1) {
				reach = true;
				break;
			}

			q.pop();
			for (int i = 0; i < 4; i++) {
				int x = cur.first.first + dx[i];
				int y = cur.first.second + dy[i];
				if (!canGo(x, y)) continue;
				if (visited[x][y][cur.second]) continue;
				if (maze[x][y]) {
					if (cur.second) continue;
					visited[x][y][1] = true;
					q.push(make_pair(make_pair(x, y), 1));
				}
				else {
					visited[x][y][cur.second] = true;
					q.push(make_pair(make_pair(x, y), cur.second));
				}
			}
		}
		if (reach)
			break;
		result++;
	}
	if (visited[n - 1][m - 1][0] | visited[n - 1][m - 1][1])
		printf("%d", result);
	else
		printf("-1");

	return 0;
}