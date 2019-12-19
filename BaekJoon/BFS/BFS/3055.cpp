#include <stdio.h>
#define MAXSIZE 3000

template <typename T>
class Queue {
private:
	T queue[MAXSIZE];
	int head, tail;
	
public:
	Queue() {
		head = 0;
		tail = 0;
	}
	void push(T val) {
		queue[tail++] = val;
	}
	T front() {
		return queue[head];
	}
	T pop() {
		return queue[head++];
	}
	bool empty() {
		return head == tail;
	}
};

struct pos {
	int x, y;
};
struct gosm {
	pos p;
	int cnt;
};

char map[51][51];
int R, C;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void Print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool inBoundary(int x,int y) {
	if (x > R - 1 || y > C - 1 || x < 0 || y < 0) return 0;
	return 1;
}

int bfs(pos w[],pos g, int wcount) {
	Queue<gosm> water;	// water는 map에 바로 퍼뜨리고
	Queue<gosm> gsm;	
	for (int i = 0; i < wcount; i++) {
		water.push({ w[i],0 });
	}
	gsm.push({ g,0 });
	int nowcnt = 0;

	while (!water.empty()||!gsm.empty()) {
		// water 먼저 flow해주고
		// 고슴도치 flow

		while (!water.empty() && water.front().cnt == nowcnt) {
			gosm noww = water.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = noww.p.x + dx[i];
				int nextY = noww.p.y + dy[i];
				if (inBoundary(nextX, nextY) && map[nextX][nextY] != 'X'
					&& map[nextX][nextY] != 'D' && map[nextX][nextY] != '*') {
					map[nextX][nextY] = '*';
					water.push({ { nextX,nextY },nowcnt + 1 });
				}
			}
		}

		while (!gsm.empty() && gsm.front().cnt == nowcnt) {
			gosm nowg = gsm.pop();
			for (int i = 0; i < 4; i++) {
				int nextX = nowg.p.x + dx[i];
				int nextY = nowg.p.y + dy[i];
				if (inBoundary(nextX, nextY) && map[nextX][nextY] != 'X'
					&& map[nextX][nextY] != '*' && map[nextX][nextY] != 'S') {
					if (map[nextX][nextY] == 'D') return nowcnt + 1;
					map[nextX][nextY] = 'S';
					gsm.push({ { nextX,nextY },nowcnt + 1 });
				}
			}
		}
		nowcnt++;
		//Print();
	}
	return 0;
}

int main() {
	scanf("%d %d", &R, &C);
	char buf[50];
	pos ws[MAXSIZE], gs;
	int wcount = 0;
	for (int i = 0; i < R; i++) {
		scanf("%s", buf);
		for (int j = 0; j < C; j++) {
			map[i][j] = buf[j];
			if (buf[j] == '*') {
				ws[wcount++] = { i,j };
			}
			else if (buf[j] == 'S') {
				gs = { i,j };
			}
		}
	}
	int ans = bfs(ws,gs,wcount);
	if (ans) printf("%d",ans);
	else printf("KAKTUS");

	return 0;
}