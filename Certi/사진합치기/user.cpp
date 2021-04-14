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

hash rowhashPool[MAX_HASH];
hash colhashPool[MAX_HASH];
photo photoList[MAXN];
int map[MAX_PICTURE_SIZE][MAX_PICTURE_SIZE];
int n, m, k;
int gNum = 0;

extern bool setPicture(int id, int x, int y);

int getHashKey(char c[]) {
	int val = 0;
	for (int i = 0; i < 4; i++) {
		val = ((val << 4) + c[i]) % MAX_HASH;
	}
	return val;
}

void init() {
	for (int i = 0; i < MAX_HASH; i++) {
		rowhashPool[i].val = 0;
		colhashPool[i].val = 0;
	}
	for (int i = 0; i < MAXN; i++) {
		photoList[i].matched = false;
	}
	gNum = 0;
}

void insertHashmap(int key, int id, int val, int num, int rc) {
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

void matching(int id) {	// matching 안되있는 것들중에 id랑 맞는것
	// hash에서 해당 row나 col과 같은것을 찾는다 (id의 4방향 가장자리)
	//printf("gNum : %d\n", gNum + 1);
	setPicture(id, photoList[id].y, photoList[id].x);
	if (++gNum == n) return;

	int hashKey = photoList[id].row[0] % MAX_HASH;
	int orgKey = hashKey;
	bool existFlag = true;
	hash *pic = &rowhashPool[hashKey];

	if (photoList[id].x != 0) {
		while (pic->id == id || pic->val != photoList[id].row[0]) {
			hashKey = (hashKey + 1) % MAX_HASH;
			if (hashKey == orgKey) {
				existFlag = false;
				break;
			}
			pic = &rowhashPool[hashKey];
		}

		if (!photoList[pic->id].matched && existFlag) {
			photoList[pic->id].matched = 1;
			photoList[pic->id].x = photoList[id].x - pic->num;
			photoList[pic->id].y = photoList[id].y;
			//printf("up %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
			matching(pic->id);
		}
	}

	hashKey = photoList[id].row[m - 1] % MAX_HASH;
	orgKey = hashKey;
	pic = &rowhashPool[hashKey];
	existFlag = true;

	if (photoList[id].x + m != k) {
		while (pic->id == id || pic->val != photoList[id].row[m - 1]) {
			hashKey = (hashKey + 1) % MAX_HASH;
			if (hashKey == orgKey) {
				existFlag = false;
				break;
			}
			pic = &rowhashPool[hashKey];
		}

		if (!photoList[pic->id].matched && existFlag) {
			photoList[pic->id].matched = 1;
			photoList[pic->id].x = photoList[id].x + m - pic->num - 1;
			photoList[pic->id].y = photoList[id].y;
			//printf("down %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
			matching(pic->id);
		}
	}

	hashKey = photoList[id].col[0] % MAX_HASH;
	orgKey = hashKey;
	pic = &colhashPool[hashKey];
	existFlag = true;

	if (photoList[id].y != 0) {
		while (pic->id == id || pic->val != photoList[id].col[0]) {
			hashKey = (hashKey + 1) % MAX_HASH;
			if (hashKey == orgKey) {
				existFlag = false;
				break;
			}
			pic = &colhashPool[hashKey];
		}

		if (!photoList[pic->id].matched && existFlag) {
			photoList[pic->id].matched = 1;
			photoList[pic->id].x = photoList[id].x;
			photoList[pic->id].y = photoList[id].y - pic->num;
			//printf("left %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
			matching(pic->id);
		}
	}

	hashKey = photoList[id].col[m - 1] % MAX_HASH;
	orgKey = hashKey;
	pic = &colhashPool[hashKey];
	existFlag = true;

	if (photoList[id].y + m != k) {
		while (pic->id == id || pic->val != photoList[id].col[m - 1]) {
			hashKey = (hashKey + 1) % MAX_HASH;
			if (hashKey == orgKey) {
				existFlag = false;
				break;
			}
			pic = &colhashPool[hashKey];
		}

		if (!photoList[pic->id].matched && existFlag) {
			photoList[pic->id].matched = 1;
			photoList[pic->id].x = photoList[id].x;
			photoList[pic->id].y = photoList[id].y + m - pic->num - 1; 
			//printf("right %d - (%d, %d)\n", pic->id, photoList[pic->id].x, photoList[pic->id].y);
			matching(pic->id);
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

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < M; k++) {
				rowbuf[k] = pictures[i][j][k];
				colbuf[k] = pictures[i][k][j];
			}
			photoList[i].row[j] = getHashKey(rowbuf);
			photoList[i].col[j] = getHashKey(colbuf);
			insertHashmap(photoList[i].row[j] % MAX_HASH, i, photoList[i].row[j], j, 0);
			insertHashmap(photoList[i].col[j] % MAX_HASH, i, photoList[i].col[j], j, 1);
		}
	}
	photoList[0].matched = true;
	photoList[0].x = 0;
	photoList[0].y = 0;
	photoList[0].id = 0;
	matching(0);
}
