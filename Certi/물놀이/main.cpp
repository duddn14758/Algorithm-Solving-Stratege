#pragma warning (disable:4996)
#include <stdio.h>
#define abs(a) (((a) < (0))?-(a):(a))
#define MAX_N 100000

typedef struct pos {
	int x, y;
}pos;

typedef struct qpos {
	int x, y, cnt;
}qpos;

int dist[1000][1000];
bool map[1000][1000];
int N, M;
pos Warr[MAX_N];
int arrN = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

enum {
	L,
	W
};

int front;
int rear;
qpos queue[MAX_N];


void queueInit(void)
{
	front = 0;
	rear = 0;
}

int queueIsEmpty(void)
{
	return (front == rear);
}

int queueIsFull(void)
{
	if ((front + 1) % MAX_N == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int queueEnqueue(qpos value)
{
	if (queueIsFull())
	{
		printf("queue is full!");
		return 0;
	}
	queue[front] = value;
	front++;
	if (front == MAX_N)
	{
		front = 0;
	}

	return 1;
}

int queueDequeue(qpos* value)
{
	if (queueIsEmpty())
	{
		printf("queue is empty!");
		return 0;
	}
	*value = queue[rear];
	rear++;
	if (rear == MAX_N)
	{
		rear = 0;
	}
	return 1;
}


void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist[i][j] = 0;
}

int calc() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(map[i][j] == L)
				ret += dist[i][j];
			//printf("%d ", dist[i][j]);
		}
		//puts("");
	}
	return ret;
}

void setDist(int x, int y) {
	//printf("- set at (%d,%d)\n", x, y);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == W) continue;
			int nDist = abs(x - i) + abs(y - j);
			if (dist[i][j] == 0) dist[i][j] = nDist;
			else dist[i][j] = dist[i][j] < nDist ? dist[i][j] : nDist;
			//printf(" -- %d %d¿¡¼­ dist : %d\n", i,j,dist[i][j]);
		}
	}
}

bool inBoundary(int x, int y) {
	if (N - 1 > x || M - 1 > y || x < 0 || y < 0) return 0;
	return 1;
}

void setDistByRound(pos p) {
	queueInit();
	queueEnqueue({p.x,p.y,1});
	while (!queueIsEmpty()) {
		qpos now;
		queueDequeue(&now);
		for (int i = 0; i < 4; i++) {
			int nextX = now.x + dx[i];
			int nextY = now.y + dy[i];

			if (inBoundary(nextX, nextY) && map[nextX][nextY] == L && (dist[nextX][nextY] == 0 || dist[nextX][nextY]>now.cnt)) {
				dist[nextX][nextY] = now.cnt;
				queueEnqueue({ nextX,nextY,now.cnt + 1 });
				//printf("enqueue %d %d %d\n", nextX, nextY, now.cnt);
			}
		}
	}
}

int main(void)
{
	int test_case;
	int T;
	char buf[1000];
	
	freopen("input.txt", "r", stdin);
	
	setbuf(stdout, NULL);
	scanf("%d", &T);	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%s", buf);
			for (int j = 0; j < M; j++) {
				if (buf[j] == 'W') {
					map[i][j] = W;
					Warr[arrN++] = {i, j};
				}
				else
					map[i][j] = L;
			}
		}
		
		for (int i = 0; i < arrN; i++) {
			setDistByRound(Warr[i]);
		}
		/*
		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if (map[i][j] == W) 
					setDist(i, j);
					*/
		printf("#%d %d\n", test_case, calc());
	}
	return 0;
}