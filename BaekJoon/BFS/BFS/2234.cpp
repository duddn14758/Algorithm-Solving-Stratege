#include <iostream>
#include <vector>
#include <queue>

// º∫∞˚
using namespace std;

bool castle[51][51][5];	// 0:µø, 1:º≠, 2:≥≤, 3:∫œ, 4:visited
int bound[51][51];
int width_arr[3000];
int n, m, max_plused_width = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>m - 1 || y>n - 1 || castle[x][y][4]) return 0;
	return 1;
}

int bfs(int x, int y, int cnt) {		// bfs∏¶ ≈Î«— ≥–¿Ã π›»Ø
	int width = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	castle[x][y][4] = 1;
	while (!q.empty()) {
		width++;
		pair<int, int> now;
		now = q.front();
		bound[now.first][now.second] = cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (inBoundary(now.first + dx[i], now.second + dy[i]) && !castle[now.first][now.second][i]) {
				q.push({ now.first + dx[i], now.second + dy[i] });
				castle[now.first + dx[i]][now.second + dy[i]][4] = 1;
				bound[now.first + dx[i]][now.second + dy[i]] = cnt;
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

void Print() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << bound[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void getNearCnt(int x, int y) {
	queue<pair<int, int>> q;
	int now_cnt = bound[x][y];
	q.push({ x,y });
	castle[x][y][4] = 1;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (inBoundary(now.first + dx[i], now.second + dy[i])) {
				if (bound[now.first + dx[i]][now.second + dy[i]] == now_cnt) {
					castle[now.first + dx[i]][now.second + dy[i]][4] = 1;
					q.push({ now.first + dx[i],now.second + dy[i] });
				}
				else {
					max_plused_width = max_plused_width > width_arr[now_cnt] + width_arr[bound[now.first + dx[i]][now.second + dy[i]]] ?
						max_plused_width : width_arr[now_cnt] + width_arr[bound[now.first + dx[i]][now.second + dy[i]]];
				}
			}
		}
	}
}

void Init() {
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			castle[i][j][4] = 0;
}

int main() {
	int buf, squre_cnt = 0, max_width = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> buf;
			setWall(i, j, buf);
		}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!castle[i][j][4]) {
				width_arr[++squre_cnt] = bfs(i, j, squre_cnt);
				max_width = width_arr[squre_cnt] > max_width ? width_arr[squre_cnt] : max_width;
				//Print();
			}
		}
	}
	Init();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!castle[i][j][4]) {
				getNearCnt(i, j);
			}
		}
	}
	cout << squre_cnt << endl << max_width << endl << max_plused_width << endl;

	return 0;
}