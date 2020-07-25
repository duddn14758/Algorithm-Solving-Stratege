#include <stdio.h>
#define MAX 1000

template <typename T>
class Queue {
private:
	T queue[MAX];
	int head = 0, tail = 0;
public:
	T pop() {
		return queue[head++];
	}
	void push(T val) {
		queue[tail++] = val;
		if (tail > MAX) printf("ASDFASDFDASFSDF\n");
	}
	bool empty() {
		return head == tail;
	}
};

typedef struct position {
	int x, y, time;
}pos;

int map[51][51];
int orgmap[51][51];
int N, M;
int min = 51 * 51;
pos virus[51 * 51];
int virus_cnt = 0;
int total = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool inBoudary(int x, int y) {
	if (x > N - 1 || y > N - 1 || x < 0 || y < 0) return 0;
	return 1;
}

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = orgmap[i][j];
}

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int bfs(int virusArr[]) {
	Queue<pos> q;
	int time = 0;
	for (int i = 0; i < M; i++) {
		q.push(virus[virusArr[i]]);
	}
	int totalCnt = total;
	while (!q.empty() && totalCnt > 0) {
		pos now = q.pop();
		time = now.time + 1;
		//if (!map[now.x][now.y]) {
		for (int i = 0; i < 4; i++) {
			int nextX = now.x + dx[i];
			int nextY = now.y + dy[i];
			if (inBoudary(nextX, nextY)) {
				if (map[nextX][nextY] == 0) {
					q.push({ nextX,nextY,time });
					map[nextX][nextY] = 3;
					totalCnt--;
				}
				else if (map[nextX][nextY] == 2) {
					q.push({ nextX,nextY,time });
					map[nextX][nextY] = 3;
				}
			}
		}
		//}
	}
	if (q.empty())
		return -1;
	else
		return time;
}

void dfs(int stt, int cnt, int arr[]) {
	arr[cnt++] = stt;
	if (cnt == M) {
		init();
		int val = bfs(arr);
		if (val == 2)
			Print();

		if (val != -1)
			min = min < val ? min : val;
	}

	for (int i = stt + 1; i < virus_cnt; i++) {
		dfs(i, cnt, arr);
	}
}

int main() {
	int arr[10];
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &orgmap[i][j]);
			if (orgmap[i][j] == 0) total++;
			else if (orgmap[i][j] == 2) {
				virus[virus_cnt++] = { i,j,0 };
			}
		}
	}

	for (int i = 0; i < virus_cnt; i++) {
		dfs(i, 0, arr);
	}

	printf("%d\n", min);
	//printf("%d\n", bfs());

	return 0;
}