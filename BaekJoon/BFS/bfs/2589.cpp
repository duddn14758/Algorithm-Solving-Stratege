#include <iostream>
#include <vector>
#include <queue>

//보물섬
using namespace std;

// 구역을 나눈다
// 구역내 한 점에서 가장 먼 곳을 찾아 DFS
// 앞의 과정을 통해 구한 가장 먼곳을 기준으로 그곳으로부터 가장 먼 곳을 찾는다.

bool visited[51][51];
int n, m, cnt=0;
char land[51][51];

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1||visited[x][y]||!land[x][y]=='L')
		return 0;
	return 1;
}

void Init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;
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
		cout << now.first.first << " " << now.first.second << endl;
		q.pop();
		far_point = now.first;
		if (inBoundary(x + 1, y)) { 
			visited[x + 1][y] = 1;
			q.push(make_pair(make_pair(x + 1, y), now.second + 1)); 
		}
		if (inBoundary(x - 1, y)) {
			visited[x - 1][y] = 1;
			q.push(make_pair(make_pair(x - 1, y), now.second + 1));
		}
		if (inBoundary(x, y + 1)) {
			visited[x][y + 1]=1;
			q.push(make_pair(make_pair(x, y + 1), now.second + 1));
		}
		if (inBoundary(x, y - 1)) {
			visited[x][y - 1]=1;
			q.push(make_pair(make_pair(x, y - 1), now.second + 1));
		}
	}
	Init();

	q.push(make_pair(far_point, 0));
	while (!q.empty()) {	// 구한 좌표에서의 가장 먼 곳의 거리를 구함
		now = q.front();
		q.pop();
		visited[x][y] = 1;
		far_length = now.second;
		if (inBoundary(x + 1, y)) q.push(make_pair(make_pair(x + 1, y), now.second + 1));
		if (inBoundary(x - 1, y)) q.push(make_pair(make_pair(x - 1, y), now.second + 1));
		if (inBoundary(x, y + 1)) q.push(make_pair(make_pair(x, y + 1), now.second + 1));
		if (inBoundary(x, y - 1)) q.push(make_pair(make_pair(x, y - 1), now.second + 1));
	}
	return far_length;	
}

int main() {
	cin >> n >> m;
	int length, max_length = 0;
	char buf[51];
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
			if (visited[i][j]) continue;
			length = bfs(i, j);
			max_length = max_length > length ? max_length : length;
		}
	}
	cout << max_length;

	return 0;
}