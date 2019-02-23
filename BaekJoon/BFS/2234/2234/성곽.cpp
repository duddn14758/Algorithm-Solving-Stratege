#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool castle[51][51][5];	// 0:동, 1:서, 2:남, 3:북, 4:visited
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool inBoundary(int x,int y) {
	if (x<0 || y<0 || x>m - 1 || y>n - 1 || castle[x][y][4]) return 0;
	return 1;
}

int bfs(int x,int y) {		// bfs를 통한 넓이 반환
	int width = 0;
	queue<pair<int ,int>> q;
	q.push({ x,y});
	castle[x][y][4] = 1;
	while (!q.empty()) {
		width++;
		pair<int ,int> now;
		now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (inBoundary(now.first+dx[i], now.second+dy[i])&&!castle[now.first][now.second][i]) {
				q.push({ now.first+dx[i], now.second+dy[i] });
				castle[now.first + dx[i]][now.second + dy[i]][4] = 1;
			}
		}
	}
	return width;
}


void setWall(int i, int j, int n) {
	if (n >= 8) castle[i][j][2] = 1;
	else castle[i][j][2] = 0;
	n %= 8;
	if (n >= 4)castle[i][j][0] = 1;
	else castle[i][j][0] = 0;
	n %= 4;
	if (n >= 2) castle[i][j][3] = 1;
	else castle[i][j][3] = 0;
	n %= 2;
	if (n == 1)castle[i][j][1] = 1;
	else castle[i][j][1] = 0;
}

int main() {
	int buf, squre_cnt=0,max_width=0;
	cin >> n >> m;
	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++) {
			cin >> buf;
			setWall(i, j, buf);
		}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!castle[i][j][4]) {
				buf = bfs(i, j);
				max_width = buf > max_width ? buf : max_width;
				squre_cnt++;
			}
		}
	}
	cout << squre_cnt << endl << max_width << endl;

	return 0;
}