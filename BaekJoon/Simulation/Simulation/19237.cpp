#include <stdio.h>

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int N, M, K;
int shkcnt;

enum {
	DIE,
	ALIVE
};

typedef struct smell {
	int who, duration;
};

typedef struct shark{
	bool alive;
	int x, y, size, dir;
	int priority[4][4];
};

shark s[401];
smell map[21][21];

void initSharkByPos(int n, int x,int y) {
	s[n].alive = ALIVE;
	s[n].x = x;
	s[n].y = y;
	s[n].size = n;
	map[x][y].who = n;
	map[x][y].duration = K;
}

bool inBoundary(int x, int y) {
	if (x > N - 1 || y > N - 1 || x < 0 || y < 0) return 0;
	return 1;
}

int findNextDir(int n) {
	int x = s[n].x;
	int y = s[n].y;
	for (int i = 0; i < 4; i++) {
		int nextDir = s[n].priority[s[n].dir][i];
		int nextX = s[n].x + dx[nextDir];
		int nextY = s[n].y + dy[nextDir];
		if (!inBoundary(nextX, nextY)) continue;
		else if (map[nextX][nextY].who == 0) {
			map[nextX][nextY].who = n;
			map[nextX][nextY].duration = K;
			s[n].x = nextX;
			s[n].y = nextY;

			return nextDir;
		}
		else if (map[nextX][nextY].duration == K) {
			if (s[map[nextX][nextY].who].alive == ALIVE) {
				shkcnt--;
				s[map[nextX][nextY].who].alive = DIE;
			}
			map[nextX][nextY].who = n;
			s[n].x = nextX;
			s[n].y = nextY;

			return nextDir;
		}
	}

	for (int i = 0; i < 4; i++) {
		int nextDir = s[n].priority[s[n].dir][i];
		int nextX = x + dx[nextDir];
		int nextY = y + dy[nextDir];
		if (map[nextX][nextY].who == n) {
			map[nextX][nextY].duration = K+1;
			s[n].x = nextX;
			s[n].y = nextY;

			return nextDir;
		}
	}
	return -1;
}

int moveAllShark() {
	// now pos duration decrease
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].duration == K + 1)
				map[i][j].duration--;
			if (map[i][j].duration > 0)
				map[i][j].duration--;
			else if (map[i][j].duration == 0) {
				map[i][j].who = 0;
			}
		}
	}
	
	for (int i = M; i > 0; i--) {
		// move
		if(s[i].alive==ALIVE)
			s[i].dir = findNextDir(i);
	}
	return shkcnt;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	int ans = 1;
	shkcnt = M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j].who);
			if (map[i][j].who) {
				initSharkByPos(map[i][j].who, i, j);
			}
		}
	}
	for (int i = 1; i <= M; i++) {
		scanf("%d", &s[i].dir);
		s[i].dir--;
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				scanf("%d", &s[i].priority[j][k]);
				s[i].priority[j][k]--;
			}
		}
	}
	while (moveAllShark()>1) {
		if (ans++ > 1000)
			break;
	}
	if (ans > 1000)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}