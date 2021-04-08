#define MAX_PICTURE_SIZE 1000
#define MAX_PIECE_SIZE 100
#define MAXN 1500
#define MAX_HASH 50007

typedef struct hash {
	int id;
	int row;	// 아랫쪽
	int col;	// 오른쪽
}hash;

typedef struct photo {
	int id;
	int row[MAX_PIECE_SIZE];	// 아랫쪽
	int col[MAX_PIECE_SIZE];	// 오른쪽
}photo;

hash hashPool[MAX_HASH];
photo photoList[MAXN];
int map[MAX_PICTURE_SIZE][MAX_PICTURE_SIZE];

extern bool setPicture(int id, int x, int y);

int getHashKey(char c[], int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = ((val << 4) + c[i]) % MAX_HASH;
	}
	return val;
}

void insertHashmap(int key, int id, int row, int col) {
	while (hashPool[key].id != 0) {
		key = (key + 1) % MAX_HASH;
	}
	hashPool[key].id = id;
	hashPool[key].row = row;
	hashPool[key].col = col;
}


void mergePictures(int N, int M, int K, char pictures[MAXN][MAX_PIECE_SIZE][MAX_PIECE_SIZE]) {
	int rowkey;
	int colkey;

	
	// add hash pool
	// add photo list

}
