#include <stdio.h>
#define MAX 2500

template <typename T>
class Queue {
private:
	T queue[MAX+1];
	int head = 0, tail = 0;
public:
	bool empty() {
		return head == tail;
	}
	void push(T a) {
		queue[(tail++)%MAX] = a;
	}
	T pop() {
		return queue[(head++)%MAX];
	}
};

struct pos {
	int x, y;
};

int N, L, R;
int map[51][51];
int visited[51][51];
pos width[MAX+2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int abs(int a) {
	if (a < 0) return a * -1;
	return a;
}

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1) return 0;
	return 1;
}

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		puts("");
	}
	puts("");
}

void bfs(int x,int y,int cnt) {	
	Queue<pos> q;
	q.push({ x,y });
	visited[x][y] = cnt;
	width[cnt].x += map[x][y];		// ³ÐÀÌ
	width[cnt].y++;					// °¹¼ö

	while (!q.empty()) {
		pos now = q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = now.x + dx[i];
			int nextY = now.y + dy[i];			
			if (inBoundary(nextX,nextY)&&!visited[nextX][nextY]) {
				int dif = abs(map[now.x][now.y] - map[nextX][nextY]);
				if (dif >= L && dif <= R) {
					q.push({ nextX,nextY });
					width[cnt].x += map[nextX][nextY];
					width[cnt].y++;
					visited[nextX][nextY] = cnt;
				}
			}
		}
	}
}

void init(int cnt) {
	for (int i = 1; i <= cnt; i++) {
		width[i].x /= width[i].y;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = width[visited[i][j]].x;
			visited[i][j] = 0;
		}
	}
	for (int i = 1; i <= cnt; i++) {
		width[i].x = 0;
		width[i].y = 0;
	}
}

int routine() {
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j]) {
				bfs(i, j, cnt++);				
			}
		}
	}
	cnt--;	
	init(cnt);
	//Print();
	return cnt;
}

int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	int total = N * N;
	int ans = 0;
	while (routine() != total) {
		ans++;
	}
	printf("%d", ans);
	
	return 0;
}