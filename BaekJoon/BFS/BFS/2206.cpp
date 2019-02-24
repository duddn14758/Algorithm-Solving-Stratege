#include <stdio.h>

// 벽 부수고 이동하기

bool maze[1001][1001];
bool visited[1001][1001];
int n, m, min = 1000000;

void DFS(int x, int y, bool bk, int cnt) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1 || ++cnt >= min || visited[x][y] || (!bk&maze[x][y]))
		return;

	if (x == n - 1 && y == m - 1) {
		min = min < cnt ? min : cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%d ", visited[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		return;
	}
	visited[x][y] = 1;


	if (maze[x][y]) bk = 0;
	DFS(x + 1, y, bk, cnt);
	DFS(x, y + 1, bk, cnt);
	DFS(x - 1, y, bk, cnt);
	DFS(x, y - 1, bk, cnt);

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
	DFS(0, 0, 1, 0);

	if (min == 1000000) min = -1;
	printf("%d", min);

	return 0;
}