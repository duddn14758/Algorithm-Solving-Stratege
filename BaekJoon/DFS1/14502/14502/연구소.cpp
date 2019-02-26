#include <stdio.h>

void Build_wall(int i, int count);
int count_size();
void init(int order);
void startSpread();
void spread(int i, int j);

int lab[8][8];
int origin[8][8];
int visited[8][8];
int x, y;
int max = 0;

int main() {
	scanf("%d %d", &x, &y);

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			scanf("%d", &lab[i][j]);
			origin[i][j] = lab[i][j];
		}
	}
	for (int i = 0; i < x*y; i++) {
		Build_wall(i, 0);
	}

	printf("%d\n", max);
	return 0;
}

void Build_wall(int i, int count) {
	int a = i / y;
	int b = i % y;
	if (lab[a][b])
		return;
	else
		lab[a][b] = 1;

	if (count == 2) {
		init(0);
		startSpread();
		int num = count_size();
		max = max > num ? max : num;
		init(1);
	}
	else if (count > 2)
		return;
	else {		
		for (int j = i + 1; j < x*y; j++) {
			Build_wall(j, count + 1);
		}
	}
	lab[a][b] = 0;
}

void startSpread() {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (lab[i][j] == 2 && !visited[i][j])
				spread(i, j);
		}
	}
}

int count_size() {
	int count = 0;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			if (!lab[i][j])
				count++;
	return count;
}

void spread(int i, int j) {
	if (visited[i][j]||i < 0 || j < 0 || i >= x || j >= y || lab[i][j] == 1)
		return;

	visited[i][j] = 1;

	if (!lab[i][j])
		lab[i][j] = 2;
	spread(i + 1, j);
	spread(i - 1, j);
	spread(i, j + 1);
	spread(i, j - 1);
}

void init(int order) {
	if(!order)
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++)
				origin[i][j] = lab[i][j];
		}
	else
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				lab[i][j] = origin[i][j];
				visited[i][j] = 0;
			}
		}
}