#include <stdio.h>

void GoPath(int prev, int cur);
void Print();
void findPath(int first);

int line[101][101];
int visited[101][101];
int num;

int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			scanf("%d", &line[i][j]);
	}
	
	for (int i = 0; i < num; i++)
		findPath(i);
	Print();

	return 0;
}

void findPath(int first) {
	for (int i = 0; i < num; i++) {
		if (line[first][i]) {
			GoPath(first, i);
		}
	}

}

void GoPath(int first, int cur) {
	if (visited[first][cur])
		return;

	line[first][cur] = 1;
	visited[first][cur] = 1;

	for (int i = 0; i < num; i++) {
		if (line[cur][i])
			GoPath(first, i);
	}

}

void Print() {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			printf("%d ", line[i][j]);
		printf("\n");
	}
}