#include <iostream>
#include <vector>
#include <queue>
#define Pii pair<int,int>

// 로고
using namespace std;

bool visited[1005][1005];

bool row[1005][1005];	// 가로
bool col[1005][1005];	// 세로

int dx[] = { 0,0,1,-1 };	
int dy[] = { 1,-1,0,0 };	// 오,왼,아래,위
int n;

bool CanGo(int x, int y,int dir) {
	switch (dir) {
	case 0:
		if (!row[x][y]) return 0;
		return 1;
	case 1:
		if (!y||!row[x][y-1]) return 0;
		return 1;
	case 2:
		if (!col[x][y]) return 0;
		return 1;
	case 3:
		if (!x||!col[x-1][y]) return 0;
		return 1;
	}
	return 0;
}

bool bfs(int x,int y) {
	if (visited[x][y]||(!CanGo(x,y,0)&& !CanGo(x, y, 1)&& !CanGo(x, y, 2)&& !CanGo(x, y, 3))) return 0;
	//cout << row[x][y] << row[x][y-1] << col[x][y] << col[x - 1][y] << endl;
	queue<Pii> q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		Pii pt;
		pt = q.front();
		//cout << pt.first << ", " << pt.second << endl;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nxtx = pt.first+dx[i];
			int nxty = pt.second+dy[i];
			if (CanGo(pt.first,pt.second,i)&& !visited[nxtx][nxty]) {
				q.push({ nxtx,nxty });
				visited[nxtx][nxty]=1;
			}
		}			   
	}
	return 1;
}

int main() {
	cin >> n;
	int lx, ly, rx, ry, cnt=0;
	for (int i = 0; i < n; i++) {
		cin >> lx >> ly >> rx >> ry;
		lx += 500;
		rx += 500;
		ly += 500;
		ry += 500;

		for (int j = lx; j < rx; j++) {		// 세로 체크
			//cout << "chk col - " << j << " ," << ly << endl;
			//cout << "chk col - " << j << " ," << ry << endl;
			col[j][ly] = 1;
			col[j][ry] = 1;
		}
		for (int j = ly; j < ry; j++) {		// 가로 체크
			//cout << "chk row - " << lx << " ," << j << endl;
			//cout << "chk row - " << ly << " ," << j << endl;
			row[lx][j] = 1;
			row[rx][j] = 1;
		}
	}

	for (int i = 0; i <= 1000; i++) {	// 0 : -500, 500 : 0, 1000 : 500
		for (int j = 0; j <= 1002; j++) {
			if (bfs(i, j)) {
				cnt++;
				//cout << "--------" << endl;
			}
		}
	}
	if (visited[500][500]) cnt--;
	cout << cnt;

	return 0;
}