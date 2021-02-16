#include <stdio.h>
#define MAX 100
enum mark {
	air,
	cheeze,
	meet,
	visited
};
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int map[MAX][MAX];
int n, m;

typedef struct position {
	int x, y;
}pos;

template <typename T>
class queue {
private:
	T arr[10000];
	int head = 0, tail = 0;
public:
	bool empty() {
		return head == tail;
	}
	void push(T a) {
		arr[tail++] = a;
	}
	T pop() {
		return arr[head++];
	}
};

bool inBoundary(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m) return 0;
	return 1;
}

int cal() {
	int num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == visited) {
				map[i][j] = air;
			}
			else if (map[i][j] == meet) {
				map[i][j] = air;
				num++;
			}
	return num;
}

int spread() {
	queue<pos> q;

	q.push({ 0,0 });
	while (!q.empty()) {
		pos now = q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = now.x + dx[i];
			int nextY = now.y + dy[i];
			if (inBoundary(nextX, nextY)) {
				if (map[nextX][nextY] == air) {
					q.push({ nextX,nextY });
					map[nextX][nextY] = visited;
				}
				else if (map[nextX][nextY] == cheeze) {
					map[nextX][nextY] = meet;
				}
			}
		}
	}
	return cal();
}

int main() {
	int tryCount = 0;
	int buf = 0;
	int prev = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	
	while (1) {
		buf = spread();
		if (buf) prev = buf;
		else break;
		tryCount++;
	}
	printf("%d\n%d\n", tryCount, prev);

	return 0;
}