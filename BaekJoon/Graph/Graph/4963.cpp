#include <iostream>
#include <vector>
#include <queue>

// ¼¶ÀÇ °³¼ö
using namespace std;
int w, h;
bool visited[51][51];
bool map[51][51];
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };

bool inBoundary(int x,int y) {
	if (x<0 || y<0 || x>h - 1 || y>w - 1||visited[x][y]||!map[x][y]) return 0;
	return 1;
}

void Init() {
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			visited[i][j] = 0;
}

int getLand() {
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] && !visited[i][j]) {
				queue<pair<int,int>> q;
				q.push({ i,j });
				visited[i][j] = 1;
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();
					for(int k=0;k<8;k++)
					if (inBoundary(cur.first+dx[k], cur.second+dy[k])) {
						q.push({ cur.first+dx[k],cur.second+dy[k] });
						visited[cur.first+dx[k]][cur.second+dy[k]] = 1;
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	cin >> w >> h;

	while (w|h) {
		Init();
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		cout << getLand() << endl;
		cin >> w >> h;
	}

	return 0;
}