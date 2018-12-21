#include <stdio.h>

void draw(int lx, int ly, int rx, int ry);
int getWidth(int i, int j);
void Sort();
void swap(int i, int j);

int pan[101][101];
int x, y;
int count = 0;
int stack[10000];

int main() {
	int num;
	int lx, ly, rx, ry;

	scanf("%d %d %d", &x, &y, &num);
	
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d %d", &lx, &ly, &rx, &ry);
		draw(lx, ly, rx, ry);
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (!pan[i][j]) {
				stack[count]=getWidth(i, j);
				count++;
			}
		}
	}
	Sort();

	printf("%d\n", count);
	for (int i = 0; i < count; i++) {
		printf("%d ", stack[i]);
	}
	return 0;
}

void draw(int lx, int ly, int rx, int ry) {
	for (int i = lx; i < rx; i++) {
		for (int j = ly; j < ry; j++) {
			pan[j][i] = 1;
		}
	}
}

int getWidth(int i,int j) {
	if (pan[i][j]||i<0||j<0||i>=x||j>=y)
		return 0;
	pan[i][j] = 2;	
	return 1 + getWidth(i + 1, j) + getWidth(i, j + 1) + getWidth(i - 1, j) + getWidth(i, j - 1);
}

void Sort() {
	for (int i = 0; i < count-1; i++) {
		for (int j = i+1; j < count; j++) {
			if (stack[i] > stack[j])
				swap(i, j);
		}
	}
}

void swap(int i, int j) {
	int temp;
	temp = stack[i];
	stack[i] = stack[j];
	stack[j] = temp;
}