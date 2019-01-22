#include <stdio.h>

void getCount();
void DFS(int i, int j, int c);

int pan[6][6];
int numArr[10000];
int numBuff = 0;

int count = 0;

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &pan[i][j]);
		}
	}
	getCount();

	printf("%d\n", count);

	return 0;
}

void getCount() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			DFS(i, j, 0);
}

void DFS(int i, int j, int c) {	
	if (c>5||i < 0 || j < 0 || i>4 || j>4)
		return;
	numBuff *= 10;
	numBuff += pan[i][j];	

	if (c == 5) {
		for (int k = 0; k < count; k++) {
			if (numBuff == numArr[k]) {
				numBuff -= pan[i][j];
				numBuff /= 10;
				return;
			}
		}		
		numArr[count++] = numBuff;
	}
	else {
		DFS(i, j + 1, c+1);
		DFS(i + 1, j, c+1);
		DFS(i, j - 1, c+1);
		DFS(i - 1, j, c+1);
	}
	numBuff -= pan[i][j];
	numBuff /= 10;
}
