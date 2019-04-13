#include <iostream>
#include <vector>
#include <queue>

// 구슬 탈출2
using namespace std;

struct pt {
	int x, y;
	pt() : x(0), y(0) {}
	pt(int x,int y) : x(x), y(y) {}
};

char map[11][11];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

// 걍 4번 기울이면 다됨
// 기울이고나서의 행적

bool inBoundary(int x, int y) {
	if (x > n - 1 || y > m - 1 || x < 0 || y < 0) return 0;
	return 1;
}

void swap(pt a, pt b) {
	char tmp = map[a.x][a.y];
	map[a.x][a.y] = map[b.x][b.y];
	map[b.x][b.y] = tmp;
}

pt move(pt p, int dir) {	
	//cout << p.x << "," << p.y << endl;
	if (map[p.x][p.y] == 'O') return p;
	int xx = p.x + dx[dir];
	int yy = p.y + dy[dir];
	if (!inBoundary(xx,yy)||map[xx][yy]=='#'|| map[xx][yy] == 'B'|| map[xx][yy] == 'R') return p;	
	p.x += dx[dir];
	p.y += dy[dir];
	return move(p, dir);
}

int bfs(pt r,pt b) {
	queue<pair<pair<pt, pt>,int>> q;
	q.push({ { r,b },0 });

	while (!q.empty()) {
		pt red = q.front().first.first;
		pt blue = q.front().first.second;
		int cnt = q.front().second;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (map[i][j] == 'R') swap(red, pt(i, j));
				else if (map[i][j] == 'B') swap(blue, pt(i, j));

		cnt++;
		q.pop();
		cout << red.x << ", " << red.y << endl;
		cout << blue.x << ", " << blue.y << endl;
		cout << cnt << endl;

		for (int i = 0; i < 4; i++) {	
			map[red.x][red.y] = '.';
			red = move(red, i);
			map[red.x][red.y] = 'R';
			if (map[red.x][red.y]=='O') return cnt;
			map[blue.x][blue.y] = '.';
			blue = move(blue, i);		
			map[blue.x][blue.y] = 'B';
			if (map[blue.x][blue.y] == 'O') continue;
			map[red.x][red.y] = '.';
			red = move(red, i);
			map[red.x][red.y] = 'R';
			if (map[red.x][red.y] == 'O') return cnt;
			map[blue.x][blue.y] = '.';
			blue = move(blue, i);
			map[blue.x][blue.y] = 'B';
			if (map[blue.x][blue.y] == 'O') continue;
			if (cnt < 10) {
				q.push({ {red,blue},cnt});
			}
		}
	}
	return -1;
}

int main() {
	char buf[11];
	pt ball[2];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> buf;
		for (int j = 0; j < m; j++) {
			map[i][j] = buf[j];
			if (map[i][j] == 'R') {
				ball[0].x = i;
				ball[0].y = j;
			}
			if (map[i][j] == 'B') {
				ball[1].x = i;
				ball[1].y = j;
			}
		}
	}	
	cout<<bfs(ball[0], ball[1]);

	return 0;
}