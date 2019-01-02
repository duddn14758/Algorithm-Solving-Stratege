#include <stdio.h>
#include <stdlib.h>

int backtracking(int col);
void draw(int row, int col);
void erase(int row, int col);
void Print();

int **pan;
int size;

int main() {

	scanf("%d", &size);
	pan = (int**)malloc(sizeof(int*)*size);
	for (int i = 0; i < size; i++) {
		pan[i] = (int*)malloc(sizeof(int)*size);
		for (int j = 0; j < size; j++) {
			pan[i][j] = 0;
		}
	}
	printf("%d\n", backtracking(0));
	   
	return 0;
}

int backtracking(int col) {
	int count = 0;
	if (col == size - 1) {
		for (int i = 0; i < size; i++) {			
			if (pan[col][i] == 0)
				count++;
		}
	}
	else {
		bool visited = false;
		for (int i = 0; i < size; i++) {
			if (pan[col][i] == 0) {
				visited = true;
				draw(col, i);
				//printf("draw\n");
				//Print();

				count+=backtracking(col + 1);
				erase(col, i);
				//printf("erase\n");
				//Print();
				
			}
		}
		if (visited == false)
			return 0;
	}
	return count;
}

void draw(int row, int col) {
	int left = col;
	int right = col;
	printf("draw -- %d %d\n", row, col);

	for (int i = row; i < size; i++) {
		if (left >= 0 && pan[i][left] == 0)
			pan[i][left--] = row;
		if (right < size&&pan[i][right] == 0)
			pan[i][right++] = row;
		pan[i][col] = row;
	}
}

void erase(int row, int col) {
	int left = col;
	int right = col;

	for (int i = row; i < size; i++) {
		if (left >= 0 && pan[i][left] == row)
			pan[i][left] = 0;
		if (right < size&&pan[i][right] == row)
			pan[i][right] = 0;
		pan[i][col] = 0;
	}
}

void Print() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			printf("%d ", pan[i][j]);
		printf("\n");
	}
	printf("\n");
}