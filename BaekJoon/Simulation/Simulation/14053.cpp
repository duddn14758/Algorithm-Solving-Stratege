#include <iostream>

// ·Îº¿ Ã»¼Ò±â
using namespace std;

bool sector[51][51];
bool clean[51][51];
int n, m;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct pos {
	int x;
	int y;
	int dir;
};

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1)
		return 0;
	return 1;
}

int dfs(int x,int y,int dir) {
	clean[x][y] = 1;
	
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (inBoundary(xx, yy)) {
			dfs(xx, yy, i);
		}
	}
	return 1;
}

int main() {
	cin >> n >> m;
	pos start;

	cin >> start.x >> start.y >> start.dir;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> sector[i][j];


	return 0;
}