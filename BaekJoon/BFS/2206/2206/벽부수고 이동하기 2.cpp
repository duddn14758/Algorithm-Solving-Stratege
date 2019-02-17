#include <stdio.h>
#include <queue>

// using BFS

bool maze[1001][1001];
bool visited[1001][1001];
int n, m, min = 1000000;

bool canGo(int x, int y, bool bk,int cnt) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1 || cnt >= min || visited[x][y] || (!bk&maze[x][y]))
		return 0;
	return 1;
}

void BFS(int x, int y, bool bk, int cnt) {
	if (x == n - 1 && y == m - 1) {
		min = min < cnt ? min : cnt;
		return;
	}
	visited[x][y] = 1;

	std::queue<std::pair<int,int>> q;
	if (maze[x][y]) bk = 0;
	if (canGo(x + 1, y, bk, cnt)) q.push({ x + 1,y });
	if (canGo(x - 1, y, bk, cnt)) q.push({ x - 1,y });
	if (canGo(x, y + 1, bk, cnt)) q.push({ x,y + 1 });
	if (canGo(x, y - 1, bk, cnt)) q.push({ x,y - 1 });
	while (!q.empty()) {
		BFS(q.front().first, q.front().second, bk, cnt+1);
		q.pop();
	}
	
	visited[x][y] = 0;
}

int main() {
	scanf("%d %d", &n, &m);
	char buf[1001];
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < m; j++) {
			maze[i][j] = buf[j] - '0';
		}
	}
	BFS(0, 0, 1, 1);

	if (min == 1000000) min = -1;
	printf("%d", min);

	return 0;
}