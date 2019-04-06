#include <iostream>
#include <vector>
#include <queue>
#define Pii pair<int,int>

// 빙산
using namespace std;

bool visited[301][301];
int ice[301][301];
int n, m;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1) return 0;
	return 1;
}

void draw(int x, int y) {
	queue<Pii> q;
	q.push({ x,y });
	visited[x][y] = 1;
	while (!q.empty()) {
		Pii now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = now.first + dx[i];
			int yy = now.second + dy[i];
			if (inBoundary(xx, yy) && !visited[xx][yy]&&ice[xx][yy]) {
				visited[xx][yy] = 1;
				q.push({ xx,yy });
			}
		}
	}
}

void Init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
}

int isSeperate() {	// 분리안되면 1, 분리되면 2, 없어지면 0
	int cnt = 0;
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			if (ice[i][j] && !visited[i][j]) {
				draw(i, j);
				cnt++;
			}
		}
	Init();
	return cnt;
}

void yearLasting() {
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++) {
			if (ice[i][j]) {
				int cnt = 0;
				for (int k = 0; k < 4; k++)
					if (inBoundary(i+dx[k],j+dy[k])&&!ice[i + dx[k]][j + dy[k]]&&!visited[i+dx[k]][j+dy[k]]) cnt++;
				ice[i][j] -= cnt;
				if (ice[i][j] < 0) ice[i][j] = 0;
				visited[i][j] = 1;
			}
		}
	Init();
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ice[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ice[i][j];
	int cnt = 0;

	while (isSeperate() == 1) {
		yearLasting();
		//Print();
		cnt++;
	}

	if (isSeperate()>0) cout << cnt;
	else cout << 0;

	return 0;
}