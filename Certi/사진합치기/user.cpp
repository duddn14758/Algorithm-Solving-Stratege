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
	bool matched = false;
	int row[MAX_PIECE_SIZE];	// 아랫쪽
	int col[MAX_PIECE_SIZE];	// 오른쪽
}photo;

hash rowhashPool[MAX_HASH];
hash colhashPool[MAX_HASH];
photo photoList[MAXN];
int map[MAX_PICTURE_SIZE][MAX_PICTURE_SIZE];
int n, m, k;

extern bool setPicture(int id, int x, int y);

int getHashKey(char c[]) {
	int val = 0;
	for (int i = 0; i < 4; i++) {
		val = ((val << 4) + c[i]) % MAX_HASH;
	}
	return val;
}

void insertHashmap(int key, int id, int val, int num, int rc) {
	if (rc == 0) {
		while (rowhashPool[key].id != 0) {
			printf("%d exist\n", key);
			key = (key + 1) % MAX_HASH;
		}
		rowhashPool[key].id = id;
		rowhashPool[key].val = val;
		rowhashPool[key].num = num;
	}
	else {
		while (colhashPool[key].id != 0) {
			if (id == 2 && num == 1)
				printf("@@@@@@@@@ %d exist\n", key);
			key = (key + 1) % MAX_HASH;
		}
		colhashPool[key].id = id;
		colhashPool[key].val = val;
		colhashPool[key].num = num;
	}
}

void matching(int id) {	// matching 안되있는 것들중에 id랑 맞는것
	// hash에서 해당 row나 col과 같은것을 찾는다 (id의 4방향 가장자리)
	printf("call\n");

	int hashKey = photoList[id].row[0] % MAX_HASH;
	int orgKey = hashKey;
	int col = photoList[id].col[0] % MAX_HASH;
	bool existFlag = true;
	hash *pic = &rowhashPool[hashKey];

	if (photoList[pic->id].x != 0) {
		printf("loop 1\n");
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
			setPicture(pic->id, photoList[pic->id].x + pic->num - m, photoList[pic->id].y);
			matching(pic->id);
		}
	}

	hashKey = photoList[id].row[m - 1] % MAX_HASH;
	orgKey = hashKey;
	pic = &rowhashPool[hashKey];
	existFlag = true;

	if (photoList[pic->id].x + m != k - 1) {
		printf("loop 2\n");
		while (pic->id == id || pic->val != photoList[id].row[m - 1]) {
			//printf("(%d - %d) (%d - %d)\n",pic->id,id,pic->val, photoList[id].row[m-1]);
			hashKey = (hashKey + 1) % MAX_HASH;
			if (hashKey == orgKey) {
				existFlag = false;
				break;
			}
			pic = &rowhashPool[hashKey];
		}

		if (!photoList[pic->id].matched && existFlag) {
			photoList[pic->id].matched = 1;
			setPicture(pic->id, photoList[pic->id].x + pic->num, photoList[pic->id].y);
			matching(pic->id);
		}
	}

	hashKey = photoList[id].col[0] % MAX_HASH;
	orgKey = hashKey;
	pic = &rowhashPool[hashKey];
	existFlag = true;

	if (photoList[pic->id].y != 0) {
		printf("loop 3\n");
		while (pic->id == id || pic->val != photoList[id].col[0]) {
			hashKey = (hashKey + 1) % MAX_HASH;
			if (hashKey == orgKey) {
				existFlag = false;
				break;
			}
			pic = &rowhashPool[hashKey];
		}

		if (!photoList[pic->id].matched && existFlag) {
			photoList[pic->id].matched = 1;
			setPicture(pic->id, photoList[pic->id].x, photoList[pic->id].y + pic->num - m);
			matching(pic->id);
		}
	}

	hashKey = photoList[id].col[m - 1] % MAX_HASH;
	orgKey = hashKey;
	pic = &rowhashPool[hashKey];
	existFlag = true;

	if (photoList[pic->id].y + m != k - 1) {
		printf("loop 4\n");
		while (pic->id == id || pic->val != photoList[id].col[m - 1]) {
			hashKey = (hashKey + 1) % MAX_HASH;
			if (hashKey == orgKey) {
				existFlag = false;
				break;
			}
			pic = &rowhashPool[hashKey];
		}
		printf("pic->id : %d\n",pic->id);

		if (!photoList[pic->id].matched && existFlag) {
			photoList[pic->id].matched = 1;
			printf("Before Set\n");
			setPicture(pic->id, photoList[pic->id].x, photoList[pic->id].y + pic->num);
			printf("After Set\n");
			matching(pic->id);
		}
	}
	printf("out\n");
}

void mergePictures(int N, int M, int K, char pictures[MAXN][MAX_PIECE_SIZE][MAX_PIECE_SIZE]) {
	int rowkey;
	int colkey;
	char rowbuf[4];
	char colbuf[4];
	n = N, m = M, k = K;

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
			if (i == 2 && j == 1) {
				printf("colbuf : %d\n", getHashKey(colbuf));
			}
		}
	}
	photoList[0].matched = true;
	photoList[0].x = 0;
	photoList[0].y = 0;
	photoList[0].id = 0;
	matching(0);
}
