#include <stdio.h>
#define MAX_PICTURE_SIZE 1000
#define MAX_PIECE_SIZE 100
#define MAXN 1500
#define MAX_HASH 50007

typedef struct hash {
	int id;
	int val;		// 값
	int num;		// 몇번째
}hash;

typedef struct photo {
	int id;
	int x, y;
	bool matched;
	int row[MAX_PIECE_SIZE];	// 아랫쪽
	int col[MAX_PIECE_SIZE];	// 오른쪽
}photo;

typedef struct Point {
	int x, y;
}Point;

hash rowhashPool[MAX_HASH];
hash colhashPool[MAX_HASH];
// 지금과 같이 전부를 hashpool에 등록하면 메모리 초과
// 따라서 4방향 끝만 hash에 담아서 현재 맞추고자 하는 조각의 안쪽과 hash를 비교
photo photoList[MAXN];
int map[MAX_PICTURE_SIZE][MAX_PICTURE_SIZE];
int n, m, k;
int gNum = 0;

extern bool setPicture(int id, int x, int y);

int getHashKey(char c[]) {
	int val = 0;
	for (int i = 0; i < 4; i++) {
		val = ((val << 4) + c[i]);
	}
	return val;
}

void init() {
	printf("init\n");
	for (int i = 0; i < MAX_HASH; i++) {
		rowhashPool[i].val = 0;
		colhashPool[i].val = 0;
	}
	for (int i = 0; i < MAXN; i++) {
		photoList[i].matched = false;
	}
	gNum = 0;
	printf("init complete\n");
}

void insertHashmap(int key, int id, int val, int num, int rc) {
	if (n == 1053 && id>=1000)
		printf("insert hashmap : %d\n", id);
	if (rc == 0) {
		while (rowhashPool[key].val != 0) {
			key = (key + 1) % MAX_HASH;
		}
		rowhashPool[key].id = id;
		rowhashPool[key].val = val;
		rowhashPool[key].num = num;
	}
	else {
		while (colhashPool[key].val != 0) {
			key = (key + 1) % MAX_HASH;
		}
		colhashPool[key].id = id;
		colhashPool[key].val = val;
		colhashPool[key].num = num;
	}
}

void matching(int id, int dir) {	// matching 안되있는 것들중에 id랑 맞는것
	// hash에서 해당 row나 col과 같은것을 찾는다 (id의 4방향 가장자리)
	printf("%d - (%d, %d)\n", id, photoList[id].x, photoList[id].y);

	photoList[id].matched = true;
	if (++gNum == n) return;

	int hashKey = photoList[id].row[0] % MAX_HASH;
	int orgKey = hashKey;
	bool existFlag = true;
	hash* pic = &rowhashPool[hashKey];

	if (photoList[id].x != 0 && dir != 0) {
		while (existFlag) {
			while (pic->id == id || pic->val != photoList[id].row[0]) {
				hashKey = (hashKey + 1) % MAX_HASH;
				if (hashKey == orgKey) {
					existFlag = false;
					break;
				}
				pic = &rowhashPool[hashKey];
			}

			if (!photoList[pic->id].matched && existFlag) {
				photoList[pic->id].x = photoList[id].x - pic->num;
				photoList[pic->id].y = photoList[id].y;
				//printf("up %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
				if (setPicture(pic->id, photoList[pic->id].y, photoList[pic->id].x)) {
					matching(pic->id, 1);
					break;
				}
			}
			//printf("1\n");
			hashKey = (hashKey + 1) % MAX_HASH;
			pic = &rowhashPool[hashKey];
			if (hashKey == orgKey || pic->val == 0) break;
		}
	}

	hashKey = photoList[id].row[m - 1] % MAX_HASH;
	orgKey = hashKey;
	pic = &rowhashPool[hashKey];
	existFlag = true;

	if (photoList[id].x + m != k && dir != 1) {
		while (existFlag) {
			while (pic->id == id || pic->val != photoList[id].row[m - 1]) {
				hashKey = (hashKey + 1) % MAX_HASH;
				if (hashKey == orgKey) {
					existFlag = false;
					break;
				}
				pic = &rowhashPool[hashKey];
			}

			if (!photoList[pic->id].matched && existFlag) {
				photoList[pic->id].x = photoList[id].x + m - pic->num - 1;
				photoList[pic->id].y = photoList[id].y;
				//printf("down %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
				if (setPicture(pic->id, photoList[pic->id].y, photoList[pic->id].x)) {
					matching(pic->id, 0);
					break;
				}
			}
			//printf("2\n");
			hashKey = (hashKey + 1) % MAX_HASH;
			pic = &rowhashPool[hashKey];
			if (hashKey == orgKey || pic->val == 0) break;
		}
	}

	hashKey = photoList[id].col[0] % MAX_HASH;
	orgKey = hashKey;
	pic = &colhashPool[hashKey];
	existFlag = true;

	if (photoList[id].y != 0 && dir != 2) {
		while (existFlag) {
			while (pic->id == id || pic->val != photoList[id].col[0]) {
				hashKey = (hashKey + 1) % MAX_HASH;
				if (hashKey == orgKey) {
					existFlag = false;
					break;
				}
				pic = &colhashPool[hashKey];
			}

			if (!photoList[pic->id].matched && existFlag) {
				photoList[pic->id].x = photoList[id].x;
				photoList[pic->id].y = photoList[id].y - pic->num;
				//printf("left %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
				if (setPicture(pic->id, photoList[pic->id].y, photoList[pic->id].x)) {
					matching(pic->id, 3);
					break;
				}
			}
			//printf("3\n");
			hashKey = (hashKey + 1) % MAX_HASH; 
			pic = &colhashPool[hashKey];
			if (hashKey == orgKey || pic->val == 0) break;
		}
	}

	hashKey = photoList[id].col[m - 1] % MAX_HASH;
	orgKey = hashKey;
	pic = &colhashPool[hashKey];
	existFlag = true;

	if (photoList[id].y + m != k && dir != 3) {
		while (existFlag) {
			while (pic->id == id || pic->val != photoList[id].col[m - 1]) {
				hashKey = (hashKey + 1) % MAX_HASH;
				if (hashKey == orgKey) {
					existFlag = false;
					break;
				}
				pic = &colhashPool[hashKey];
			}

			if (!photoList[pic->id].matched && existFlag) {
				photoList[pic->id].x = photoList[id].x;
				photoList[pic->id].y = photoList[id].y + m - pic->num - 1;
				//printf("right %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
				if (setPicture(pic->id, photoList[pic->id].y, photoList[pic->id].x)) {
					matching(pic->id, 2);
					break;
				}
			}
			//printf("4\n");
			hashKey = (hashKey + 1) % MAX_HASH;
			pic = &colhashPool[hashKey];
			if (hashKey == orgKey || pic->val == 0) break;
		}
	}
	//printf("out\n");
}

void mergePictures(int N, int M, int K, char pictures[MAXN][MAX_PIECE_SIZE][MAX_PIECE_SIZE]) {
	int rowkey;
	int colkey;
	char rowbuf[MAX_PIECE_SIZE];
	char colbuf[MAX_PIECE_SIZE];
	n = N, m = M, k = K;
	init();
	printf("%d %d %d\n", n, m, k);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				rowbuf[k] = pictures[i][j][k];
				colbuf[k] = pictures[i][k][j];
			}
			photoList[i].row[j] = getHashKey(rowbuf);
			photoList[i].col[j] = getHashKey(colbuf);
			insertHashmap(photoList[i].row[j] % MAX_HASH, i, photoList[i].row[j], j, 0);
			insertHashmap(photoList[i].col[j] % MAX_HASH, i, photoList[i].col[j], j, 1);
			if(n==1053&&i>999)
			printf("%d %d\n", i, j);
		}
	}
	printf("process\n");
	photoList[0].matched = true;
	photoList[0].x = 0;
	photoList[0].y = 0;
	photoList[0].id = 0;
	matching(0, 0);
}
