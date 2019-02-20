#include <iostream>
#include <vector>
#include <queue>

//보물섬
using namespace std;

// 구역을 나눈다
// 구역내 한 점에서 가장 먼 곳을 찾아 DFS
// 앞의 과정을 통해 구한 가장 먼곳을 기준으로 그곳으로부터 가장 먼 곳을 찾는다.

bool visited[55][55];
int n, m, cnt=0;
char land[55][55];

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1||visited[x][y]||land[x][y]=='W')
		return 0;
	return 1;
}

void Init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int bfs(int x,int y) {
	queue<pair<pair<int, int>,int>> q;
	pair<pair<int, int>,int> now;
	pair<int, int> far_point;
	int far_length=0;

	q.push({ { x,y },0 });
	visited[x][y] = 1;
	while (!q.empty()) {		// 가장 먼 곳의 좌표를 구함
		now = q.front();
		q.pop();
		far_point = now.first;
		//Print();
		if (inBoundary(now.first.first + 1, now.first.second)) { 
			visited[now.first.first + 1][now.first.second] = 1;
			q.push(make_pair(make_pair(now.first.first + 1, now.first.second), now.second + 1));
		}
		if (inBoundary(now.first.first - 1, now.first.second)) {
			visited[now.first.first - 1][now.first.second] = 1;
			q.push(make_pair(make_pair(now.first.first - 1, now.first.second), now.second + 1));
		}
		if (inBoundary(now.first.first, now.first.second + 1)) {
			visited[now.first.first][now.first.second + 1]=1;
			q.push(make_pair(make_pair(now.first.first, now.first.second + 1), now.second + 1));
		}
		if (inBoundary(now.first.first, now.first.second - 1)) {
			visited[now.first.first][now.first.second - 1]=1;
			q.push(make_pair(make_pair(now.first.first, now.first.second - 1), now.second + 1));
		}
	}
	Init();

	q.push(make_pair(far_point, 0));
	visited[far_point.first][far_point.second];
	while (!q.empty()) {	// 구한 좌표에서의 가장 먼 곳의 거리를 구함
		now = q.front();
		q.pop();
		far_length = now.second;
		if (inBoundary(now.first.first + 1, now.first.second)) {
			visited[now.first.first + 1][now.first.second] = 1;
			q.push(make_pair(make_pair(now.first.first + 1, now.first.second), now.second + 1));
		}
		if (inBoundary(now.first.first - 1, now.first.second)) {
			visited[now.first.first - 1][now.first.second] = 1;
			q.push(make_pair(make_pair(now.first.first - 1, now.first.second), now.second + 1));
		}
		if (inBoundary(now.first.first, now.first.second + 1)) {
			visited[now.first.first][now.first.second + 1] = 1;
			q.push(make_pair(make_pair(now.first.first, now.first.second + 1), now.second + 1));
		}
		if (inBoundary(now.first.first, now.first.second - 1)) {
			visited[now.first.first][now.first.second - 1] = 1;
			q.push(make_pair(make_pair(now.first.first, now.first.second - 1), now.second + 1));
		}
	}
	return far_length;	
}

int main() {
	cin >> n >> m;
	int length, max_length = 0;
	char buf[55];
	for (int i = 0; i < n; i++) {
		cin >> buf;
		for (int j = 0; j < m; j++) {
			land[i][j] = buf[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// isitLand?
			// getMaxLengthToThatPoint
			// getMaxLengthPoint
			if (land[i][j]=='W'||visited[i][j]) continue;
			length = bfs(i, j);
			max_length = max_length > length ? max_length : length;
		}
	}
	cout << max_length;

	return 0;
}