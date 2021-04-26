#include <stdio.h>
#define MAX_STU 20
#define CHK 5

int fav[MAX_STU][4];
int map[MAX_STU][MAX_STU];

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

struct pos {
	int x, y;
};

struct prt {
	pos p;
	int cnt;
};

pos student[MAX_STU];
int priority[MAX_STU];
int num;
int total;

bool inBoundary(int x, int y) {
	if (x > MAX_STU - 1 || y > MAX_STU - 1 || x < 0 || y < 0) return 0;
	return 1;
}

void init() {

}

void select(int num) {
	prt p = { 0,0,0 };
	pos *std;
	bool existFlag = false;

	for (int i = 0; i < 4; i++) {
		if (student[fav[num][i]].x != -1) {
			existFlag = true;
			std = &student[fav[num][i]];
			for (int j = 0; j < 8; j++) {
				int nextX = std->x + dx[j];
				int nextY = std->y + dy[j];
				if (inBoundary(nextX, nextY) && map[nextX][nextY] != CHK) {
					map[nextX][nextY]++;
					if (map[nextX][nextY] > p.cnt) {
						p.p.x = nextX;
						p.p.y = nextY;
						p.cnt = map[nextX][nextY];
					}
				}
			}
		}
	}
	if (existFlag) {
		for (int i = 0; i < 4; i++) {
			if (student[fav[num][i]].x != -1) {
				std = &student[fav[num][i]];
				for (int j = 0; j < 8; j++) {
					int nextX = std->x + dx[j];
					int nextY = std->y + dy[j];
					if (inBoundary(nextX, nextY) && map[nextX][nextY] != CHK && map[nextX][nextY] != 0) {
						map[nextX][nextY]=0;
					}
				}
			}
		}
		student[num].x = p.p.x;
		student[num].y = p.p.y;
		return;
	}

	for (int i = 0; i < MAX_STU; i++) {
		for (int j = 0; j < MAX_STU; j++) {
			if (map[i][j] != CHK) {
				map[i][j] = CHK;
				student[num].x = i;
				student[num].y = j;
				return;
			}
		}
	}

	printf("ERR\n");
	return;
}

int counting() {
	int cnt = 0;
	for (int i = 0; i < total; i++) {

	}
}

int main() {
	scanf("%d", &num);
	total = num * num;
	for (int i = 0; i < total; i++) {
		scanf("%d", &priority[i]);
		for (int j = 0; j < 4; j++) {
			scanf("%d", &fav[priority[i]][j]);
		}
	}

	return 0;
}