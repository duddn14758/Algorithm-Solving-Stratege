#include <iostream>
#include <vector>
#include <queue>

//������
using namespace std;

// ������ ������
// ������ �� ������ ���� �� ���� ã�� DFS
// ���� ������ ���� ���� ���� �հ��� �������� �װ����κ��� ���� �� ���� ã�´�.

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
	while (!q.empty()) {		// ���� �� ���� ��ǥ�� ����
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
	while (!q.empty()) {	// ���� ��ǥ������ ���� �� ���� �Ÿ��� ����
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