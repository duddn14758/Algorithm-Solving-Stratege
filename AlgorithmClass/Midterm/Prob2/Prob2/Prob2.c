#include <stdio.h>
#include <stdlib.h>
#define R 2
#define B 3
#define L 4
#define T 5

void findPath(int i, int j, int dir, int count);

int **arr;
int result = -1;
int N;

int main() {
	FILE *fp = fopen("input2.txt", "r");

	int Case;

	fscanf(fp, "%d", &Case);
	while (Case--) {
		fscanf(fp, "%d", &N);

		arr = (int**)malloc(sizeof(int*)*N);
		for (int i = 0; i < N; i++) {
			arr[i] = (int*)malloc(sizeof(int)*N);
			for (int j = 0; j < N; j++) {
				fscanf(fp, "%d", &arr[i][j]);
			}
		}
		findPath(0, 0, R, 0);
		printf("°¹¼ö : %d\n", result);
		result = -1;

	}
	return 0;
}

void findPath(int i,int j,int dir, int count) {
	
	if (i<0 || j<0 || i>N - 1 || j>N - 1||arr[i][j]==1||arr[i][j]==dir)
		return;

	if (result != -1&&result<count) {
		return;
	}

	if (i == N - 1 && j == N - 1) {
		if (result != -1)
			result = result < count ? result : count;
		else
			result = count;
		
		return;
	}
		
	arr[i][j] = dir;
		
	if (dir == R) {
		findPath(i, j + 1, R, count);
		findPath(i + 1, j, B, count);
		findPath(i - 1, j, T, count + 1);
	}
	else if (dir == B) {
		findPath(i + 1, j, B, count);
		findPath(i, j - 1, L, count);
		findPath(i, j + 1, R, count+1);
	}
	else if (dir == L) {
		findPath(i, j - 1, L, count);
		findPath(i - 1, j, T, count);
		findPath(i + 1, j, B, count+1);
	}
	else if (dir == T) {
		findPath(i - 1, j, T, count);
		findPath(i, j + 1, R, count);
		findPath(i, j - 1, L, count + 1);
	}
	arr[i][j] = 0;

	return;
}