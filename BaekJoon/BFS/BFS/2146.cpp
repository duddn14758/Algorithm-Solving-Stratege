#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 다리 만들기
using namespace std;
int n, shortcut = 200;
bool map[101][101];
bool visited[101][101];

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

struct Pt {
	int x;
	int y;
	int dist;
};

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1) return 0;
	return 1;
}

void sameLand(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++)
		if (inBoundary(x + dx[i], y + dy[i]) && map[x + dx[i]][y + dy[i]] && !visited[x + dx[i]][y + dy[i]])
			sameLand(x + dx[i], y + dy[i]);
}


void Init(int x, int y) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
}

int bfs(int x, int y) {
	queue<Pt> q;
	q.push({ x,y,0 });
	while (!q.empty()) {
		Pt p = q.front();
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = p.x + dx[i];
			int yy = p.y + dy[i];
			if (!inBoundary(xx, yy)) continue;
			if (map[xx][yy] && !visited[xx][yy])
				return p.dist;
			if (!map[xx][yy] && !visited[xx][yy]) {
				q.push({ p.x + dx[i],p.y + dy[i],p.dist + 1 });
				visited[xx][yy] = 1;
			}			
		}
	}
	return 200;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			if (map[i][j]) {
				bool t = false;
				for (int k = 0; k < 4; k++) {
					if (inBoundary(i+dx[k],j+dy[k])&&!map[i + dx[k]][j + dy[k]]) t = true;
				}
				if (!t) continue;

				Init(i, j);
				sameLand(i, j);
				shortcut = min(shortcut, bfs(i, j));
				
			}
		
	cout << shortcut;

	return 0;
}