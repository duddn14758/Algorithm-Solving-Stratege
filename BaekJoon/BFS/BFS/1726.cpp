#include <stdio.h>
#define MAX 30000

struct pos {
	int x, y,dir;
};
struct stat {
	pos now;
	int cnt;
};

int dx[] = { 0,0,1,-1 };	
int dy[] = { 1,-1,0,0 };
//int dx[] = { 0,1,0,-1 };
//int dy[] = { 1,0,-1,0 };

bool visited[102][102][5];
bool map[102][102];
int N, M;
int ans = 99999;
pos stt, dst;

template <typename T>
class Queue{
private:
	T queue[MAX+1];
	int head = 0, tail = 0;
public:
	bool empty() {
		return head == tail;
	}
	void push(T n) {
		queue[(tail++)%MAX] = n;
	}
	T pop() {
		return queue[(head++)%MAX];
	}
	T peek() {
		return queue[head];
	}
};

bool inBoundary(int x, int y) {
	if (x <= 0 || y <= 0 || x > M || y > N) return 0;
	return 1;
}

void Print() {
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	puts("");
}

int bfs() {
	Queue<stat> q;
	q.push({stt,0});
	visited[stt.x][stt.y][stt.dir] = 1;
	while (!q.empty()) {
		stat now = q.pop();
		//printf("%d %d %d\n", now.now.x, now.now.y,now.cnt);
		if (now.now.x == dst.x && now.now.y == dst.y) {
			if (now.now.dir==dst.dir) {
				ans = ans < now.cnt ? ans : now.cnt;
			}
			else if ((now.now.dir == 0 && dst.dir == 1) || (now.now.dir == 1 && dst.dir == 0)
				|| (now.now.dir == 3 && dst.dir == 2) || (now.now.dir == 2 && dst.dir == 3)) {
				ans = ans < now.cnt+2 ? ans : now.cnt+2;
			}
			else {
				ans = ans < now.cnt+1 ? ans : now.cnt+1;
			}
		}
		else {
			for (int i = 1; i <= 3; i++) {		// 진행방향 3칸
				int nextX = now.now.x + dx[now.now.dir] * i;
				int nextY = now.now.y + dy[now.now.dir] * i;
				if (visited[nextX][nextY][now.now.dir]) continue;
				if (!inBoundary(nextX, nextY) || map[nextX][nextY]) {
					break;
				}
				visited[nextX][nextY][now.now.dir] = 1;
				q.push({ nextX,nextY,now.now.dir,now.cnt+1 });
			}
			for (int i = 0; i < 4; i++) {		// 다른 3방향				
				if (i != now.now.dir) {	
					if (!visited[now.now.x][now.now.y][i]) {
						if ((i == 0 && now.now.dir == 1) || (i == 1 && now.now.dir == 0)
							|| (i == 2 && now.now.dir == 3) || (i == 3 && now.now.dir == 2)) {
							visited[now.now.x][now.now.y][i] = 1;
							q.push({ now.now.x,now.now.y,i,now.cnt + 2 });
						}
						else {
							visited[now.now.x][now.now.y][i] = 1;
							q.push({ now.now.x,now.now.y,i,now.cnt + 1 });
						}
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	scanf("%d %d %d", &stt.x, &stt.y, &stt.dir);
	scanf("%d %d %d", &dst.x, &dst.y, &dst.dir);
	stt.dir -= 1;
	dst.dir -= 1;
	printf("%d",bfs());

	return 0;
}