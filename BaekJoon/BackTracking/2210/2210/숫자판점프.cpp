#include <stdio.h>

void getCount();
void DFS(int i, int j, int c);

int pan[5][5];
int stack[10000][6];
int buffer[6];

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
	if (c>5||i < 0 || j < 0 || i>5 || j>5)
		return;
	buffer[c++] = pan[i][j];

	

	if (c == 6) {
		/*printf("%d %d %d", i, j, c);
		printf(" buffer : ");
		for (int k = 0; k < c; k++)
			printf("%d ", buffer[k]);
		printf("\n");*/
		for (int k = 0; k < count; k++) {
			int pointer = 0;
			while (pointer < 6 && buffer[pointer] == stack[k][pointer]) {
				pointer++;
			}
			if (pointer == 6)
				return;
			else {
				pointer = 0;
				while (pointer != 6) {
					stack[count++][pointer] = buffer[pointer++];
				}
			}
		}
	}
	else {
		DFS(i, j + 1, c);
		DFS(i + 1, j, c);
		DFS(i, j - 1, c);
		DFS(i - 1, j, c);
	}
}
