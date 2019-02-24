#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool pan[301][301];
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
pair<int, int> start_point, end_point;
int p, length = 0;

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>p - 1 || y>p - 1 || pan[x][y])
		return 0;
	return 1;
}

void Init() {
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
			pan[i][j] = 0;
	length = 0;
}

void bfs(int x, int y) {
	queue <pair<pair<int, int>,int>> q;
	q.push({ {x,y},0 });
	pan[x][y] = 1;
	
	while (!q.empty()) {
		pair<pair<int, int>,int> now;
		now = q.front();		
		q.pop();
		if (now.first.first == end_point.first&&now.first.second == end_point.second) {
			length = now.second;
			return;
		}		
		for (int i = 0; i < 8; i++) {
			if (inBoundary(now.first.first + dx[i], now.first.second + dy[i])) {
				pan[now.first.first+dx[i]][now.first.second+dy[i]] = 1;
				q.push({ { now.first.first + dx[i], now.first.second + dy[i] }, now.second + 1 });
			}
		}
	}
}

int main() {
	int c;
	cin >> c;
	while (c-- > 0) {
		cin >> p >> start_point.first >> start_point.second >> end_point.first >> end_point.second;
		bfs(start_point.first, start_point.second);
		cout << length << endl;
		Init();
	}
	return 0;
}