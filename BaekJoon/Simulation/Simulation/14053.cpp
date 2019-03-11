#include <iostream>

// 로봇 청소기
using namespace std;

struct machine {
	int x;
	int y;
	int dir;
};
bool sector[51][51];
bool clean[51][51];
int n, m;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
machine mc;

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1)
		return 0;
	return 1;
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << clean[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int run() {
	int cnt = 0;
	while (1) {
		if (!clean[mc.x][mc.y]) {
			clean[mc.x][mc.y] = 1;	// 청소
			cnt++;
			//Print();
		}
		bool back = 1;
		for (int i = 0; i < 4; i++) {	// 4방향 검사
			mc.dir = (mc.dir + 3) % 4;
			int xx = mc.x + dx[mc.dir];
			int yy = mc.y + dy[mc.dir];
			if (inBoundary(xx, yy) && !sector[xx][yy] && !clean[xx][yy]) { // 이동
				mc.x = xx;
				mc.y = yy;
				back = 0;
				break;
			}
		}
		if (back) {		// 4방항 검사 후 갈곳이없을 경우
			int bx = mc.x+dx[(mc.dir + 2) % 4];
			int by = mc.y+dy[(mc.dir + 2) % 4];
			if (!inBoundary(bx, by)||sector[bx][by]) return cnt;	// 뒤가 벽이거나 밖일경우 카운트리턴
			else {		// 벽이아니라면
				mc.x = bx;		// 방향은그대로 뒤로 이동
				mc.y = by;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> mc.x >> mc.y >> mc.dir;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> sector[i][j];
	cout << run();

	return 0;
}