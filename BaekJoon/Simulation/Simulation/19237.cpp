#include <stdio.h>

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,0 };
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

void initSharkByPos(int n, int x,int y) {
	s[n].alive = ALIVE;
	s[n].x = x;
	s[n].y = y;
	s[n].size = n;
}

bool inBoundary(int x, int y) {
	if (x > N - 1 || y > N - 1 || x < 0 || y < 0) return 0;
	return 1;
}

int findNextDir(int n) {

}

int moveShark(int n) {
	
	s[n].dir = findNextDir(n);

	//return die shark num
}

int moveAllShark() {
	
	for (int i = M; i > 0; i--) {
		// now pos duration decrease
		map[s[i].x][s[i].y].duration--;

		// move




		// if equal duration decrease shark cnt, set alive die, set smell
	}

}

int main() {
	scanf("%d %d %d", &N, &M, &K);
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
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				scanf("%d", &s[i].priority[j][k]);
			}
		}
	}

	return 0;
}