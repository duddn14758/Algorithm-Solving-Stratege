#include <iostream>
#include <vector>
#include <queue>
#define Pii pair<int,int>

// �볪�� �ű��
using namespace std;

struct point {
	int x;
	int y;
	bool state;
	//point(int x, int y, int state) : x(x),y(y),state(state) {}
};

char arr[51][51];
bool visited[51][51][2];	// ����,���η� �������� �����ϱ����� 0:����,1:����
int n;
point dst;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };

bool inBoundary(int x, int y) {
	if (x > n - 1 || y > n - 1 || x < 0 || y < 0) return 0;
	return 1;
}

bool canGo(int x,int y, bool state) {		// 0:��, 1:��, 2:�Ʒ�, 3:��, 4: ȸ��
	if (visited[x][y][state]) return 0;
	for (int i = -1; i <= 1; i++) {
		if (state) {	// ����
			if (!inBoundary(x + i, y) ||arr[x+i][y]=='1') return 0;
		}
		else {
			if (!inBoundary(x, y + i) || arr[x][y + i] == '1') return 0;
		}
	}
	return 1;
}

bool canRotate(int x, int y,bool state) {
	if (visited[x][y][state]) return 0;
	for (int i = 0; i <8; i++) {
		int xx = x+dx[i];
		int yy = y + dy[i];
		if (!inBoundary(xx, yy) || arr[xx][yy] == '1') return 0;
	}	
	return 1;
}

int bfs(int x,int y,bool state) {
	queue<pair<point,int>> q;
	q.push({ { x,y,state },0 });
	visited[x][y][state] = 1;
	int cnt = 0;
	while (!q.empty()) {
		point now = q.front().first;
		int ncnt = q.front().second;
		//cout << now.x << ", " << now.y << " - " << now.state << endl;
		if (now.x == dst.x&&now.y == dst.y&&now.state == dst.state) return ncnt;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];
			if (canGo(xx, yy, now.state)) {
				q.push({ {xx,yy,now.state},ncnt + 1 });
				visited[xx][yy][now.state] = 1;
			}
		}
		if (canRotate(now.x,now.y,!now.state)) {	// �ֺ� 8ĭ�� �� ���������
			q.push({ {now.x,now.y,!now.state},ncnt + 1});
			visited[now.x][now.y][!now.state] = 1;
		}
	}
	return 0;
}

int main() {
	vector<Pii> tong,dest;
	bool state,d_state;	// 0:����, 1:����
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') {
				tong.push_back({ i,j });
			}
			else if (arr[i][j] == 'E') 
				dest.push_back({ i,j });
		}
	if (tong[0].first + 1 == tong[1].first) state = 1;
	else state = 0;
	if (dest[0].first + 1 == dest[1].first) dst.state = 1;
	else dst.state = 0;
	dst.x = dest[1].first;
	dst.y = dest[1].second;

	cout << bfs(tong[1].first, tong[1].second, state);

	return 0;
}