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

shark s[400];
smell map[20][20];

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j].who);
		}
		printf("   ");
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j].duration);
		}
		puts("");
	}
	puts(" -- shark status");
	for (int i = 1; i <= M; i++) {
		if(s[i].alive==ALIVE)
		printf("   - shark[%d] : (%d, %d)\n", i, s[i].x, s[i].y);
	}
	puts("");
}

void initSharkByPos(int n, int x,int y) {
	s[n].alive = ALIVE;
	s[n].x = x;
	s[n].y = y;
	s[n].size = n;
	map[x][y].who = n;
	map[x][y].duration = M;
}

bool inBoundary(int x, int y) {
	if (x > N - 1 || y > N - 1 || x < 0 || y < 0) return 0;
	return 1;
}

int findNextDir(int n) {
	// 아무냄새도 없거나 smell의 duration이 max인곳 먼저
	int x = s[n].x;
	int y = s[n].y;
	for (int i = 0; i < 4; i++) {
		int nextDir = s[n].priority[s[n].dir][i];
		int nextX = s[n].x + dx[nextDir];
		int nextY = s[n].y + dy[nextDir];
		//printf("%d에서 다음방향 : %d, num : %d, dur : %d\n", n, nextDir,map[nextX][nextY].who, nextDir, map[nextX][nextY].duration);
		if (!inBoundary(nextX, nextY)) continue;
		else if (map[nextX][nextY].duration == 0) {
			map[nextX][nextY].who = n;
			map[nextX][nextY].duration = M;
			s[n].x = nextX;
			s[n].y = nextY;

			return nextDir;
		}
		else if (map[nextX][nextY].duration == M) {
			if (s[map[nextX][nextY].who].alive == ALIVE) {
				shkcnt--;
				s[map[nextX][nextY].who].alive = DIE;
				printf("@@@@@ %d Die at (%d,%d) (killed by %d) @@@@\n", map[nextX][nextY].who,nextX,nextY,n);
			}
			map[nextX][nextY].who = n;
			s[n].x = nextX;
			s[n].y = nextY;

			return nextDir;
		}
	}

	//printf("%d는 자기냄새로 (%d,%d)\n", n, x, y);
	// 없다면 자신의 냄새가 있는 곳
	for (int i = 0; i < 4; i++) {
		int nextDir = s[n].priority[s[n].dir][i];
		int nextX = x + dx[nextDir];
		int nextY = y + dy[nextDir];
		if (map[nextX][nextY].who == n) {
			map[nextX][nextY].duration = M;
			return nextDir;
		}
	}
	return -1;
}
/*
int moveShark(int n) {
	
	s[n].dir = findNextDir(n);

}
*/
int moveAllShark() {
	// now pos duration decrease
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].duration > 0)
				map[i][j].duration--;
			if (map[i][j].duration == 0) {
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
	Print();
	while (moveAllShark()>1) {
		if (ans++ > 1000)
			break;
		Print();
		printf(" - %d turn print\n\n", ans - 1);
	}
	if (ans > 1000)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}