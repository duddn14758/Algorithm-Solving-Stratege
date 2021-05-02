#include <stdio.h>
#define MAX_STU 20
#define CHK 5
#define MAX_SIZE 401

int fav[MAX_STU + 1][4];		// 좋아하는 친구 순위
int map[MAX_STU][MAX_STU];	// 자리배치도

int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

struct pos {
	int x, y;
};

struct prt {
	pos p;
	int cnt;
};

struct versePos {
	pos p;
	int favorCnt;
	int emptyCnt;
};

pos student[MAX_STU + 1];	// 학생의 좌표
bool sit[MAX_STU + 1];		// 학생이 착석했는지
int num;
int total;


bool inBoundary(int x, int y) {
	if (x > num - 1 || y > num - 1 || x < 0 || y < 0) return 0;
	return 1;
}

/*
int getEmtptyCnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (inBoundary(nextX, nextY) && map[nextX][nextY] != CHK) {
			cnt++;
		}
	}
	return cnt;
}

int getDistance(pos a, pos b) {
	return ((a.x - b.x) > 0 ? (a.x - b.x) : (b.x - a.x)) + ((a.y - b.y) > 0 ? (a.y - b.y) : (b.y - a.y));
}

int getSatisfaction() {
	int favFrd;
	int totalCnt = 0;
	for (int i = 1; i <= total; i++) {
		int satisCnt = 0;
		for (int j = 0; j < 4; j++) {
			favFrd = fav[i][j];
			if (getDistance(student[i], student[favFrd]) == 1) {
				satisCnt++;
			}
		}
		if (satisCnt == 1) {
			totalCnt += 1;
		}
		else if (satisCnt == 2) {
			totalCnt += 10;
		}
		else if (satisCnt == 3) {
			totalCnt += 100;
		}
		else if (satisCnt == 4) {
			totalCnt += 1000;
		}
	}
	return totalCnt;
}

*/

bool oper(versePos a, versePos b) {
	if (a.favorCnt < b.favorCnt || (a.favorCnt == b.favorCnt && a.emptyCnt < b.emptyCnt)
		|| (a.favorCnt == b.favorCnt && a.emptyCnt == b.emptyCnt && a.p.x > b.p.x)
		|| (a.favorCnt == b.favorCnt && a.emptyCnt == b.emptyCnt && a.p.x == b.p.x && a.p.y > b.p.y))
		return true;
	return false;
}

int getFavorCnt(int n, int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (inBoundary(nextX, nextY)) {
			for (int j = 0; j < 4; j++) {
				if (map[nextX][nextY] == fav[n][j]) cnt++;
			}
		}
	}
	return cnt;
}

int getSatisfy() {
	int val = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int favorCnt = getFavorCnt(map[i][j], i, j);
			switch (favorCnt) {
			case 1:
				val += 1;
				break;
			case 2:
				val += 10;
				break;
			case 3:
				val += 100;
				break;
			case 4:
				val += 1000;
				break;
			}
		}
	}
	return val;
}

int getEmptyCnt(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if (inBoundary(nextX, nextY)) {
			for (int j = 0; j < 4; j++) {
				if (map[nextX][nextY] == 0) cnt++;
			}
		}
	}
	return cnt;
}

void select(int n) {
	versePos most = { -1,-1, 0, 0 };
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			if (map[i][j] == 0) {
				versePos now = { i,j,0,0 };
				now.favorCnt = getFavorCnt(n, i, j);
				now.emptyCnt = getEmptyCnt(i, j);
				if (oper(most, now)) {
					most = now;
				}
			}
		}
	}
	map[most.p.x][most.p.y] = n;
}

/*
void select(int n) {
	prt p = { 0,0,0 };
	pos *std;
	bool existFlag = false;
	int emptyCnt = 0;

	for (int i = 0; i < 4; i++) {
		if (sit[fav[n][i]] != 0) {
			existFlag = true;
			std = &student[fav[n][i]];
			for (int j = 0; j < 4; j++) {
				int nextX = std->x + dx[j];
				int nextY = std->y + dy[j];
				if (inBoundary(nextX, nextY) && map[nextX][nextY] != CHK) {
					map[nextX][nextY]++;
					int cntBuf = getEmtptyCnt(nextX, nextY);
					if (map[nextX][nextY] > p.cnt ||
						(map[nextX][nextY] == p.cnt && cntBuf > emptyCnt)) {
						p.p.x = nextX;
						p.p.y = nextY;
						p.cnt = map[nextX][nextY];
						emptyCnt = cntBuf;
					}
				}
			}
		}
	}
	if (existFlag) {
		for (int i = 0; i < 4; i++) {
			if (sit[fav[n][i]] != 0) {
				std = &student[fav[n][i]];
				for (int j = 0; j < 4; j++) {
					int nextX = std->x + dx[j];
					int nextY = std->y + dy[j];
					if (inBoundary(nextX, nextY) && map[nextX][nextY] != CHK && map[nextX][nextY] != 0) {
						map[nextX][nextY]=0;
					}
				}
			}
		}
		student[n].x = p.p.x;
		student[n].y = p.p.y;
		map[student[n].x][student[n].y] = CHK;
		return;
	}

	int cnt = 0;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			int cntBuf = getEmtptyCnt(i, j);
			if (map[i][j] != CHK && cnt < cntBuf) {
				student[n].x = i;
				student[n].y = j;
				cnt = cntBuf;
			}
		}
	}
	map[student[n].x][student[n].y] = CHK;

	return;
}
*/

int main() {
	/*
	int stdnt;
	scanf("%d", &num);
	total = num * num;
	for (int i = 0; i < total; i++) {
		scanf("%d", &stdnt);
		for (int j = 0; j < 4; j++) {
			scanf("%d", &fav[stdnt][j]);
		}
		select(stdnt);
		sit[stdnt] = 1;
	}
*/
	int stdnt[MAX_STU + 1];
	scanf("%d", &num);
	total = num * num;
	for (int i = 0; i < total; i++) {
		scanf("%d", &stdnt[i]);
		for (int j = 0; j < 4; j++) {
			scanf("%d", &fav[stdnt[i]][j]);
		}
	}

	for (int i = 0; i < total; i++) {
		select(stdnt[i]);
	}

	printf("%d\n", getSatisfy());

	return 0;
}