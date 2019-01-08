#include <stdio.h>
#include <stdlib.h>

int ground[26][26];
int visited[26][26];
int N;
void getApt();
int countWidth(int x, int y);
int compare(const void *a, const void *b);
int stack[26 * 26];
int pointer = 0;

int main() {
	scanf("%d", &N);

	char buffer[26];
	
	for (int i = 0; i < N; i++) {
		scanf("%s", buffer);
		for (int j = 0; j < N; j++) {
			ground[i][j] = buffer[j]-'0';
		}
	}

	getApt();

	return 0;
}

void getApt() {
	int count;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			count = countWidth(i, j);
			if (count>0)
				stack[pointer++]=count;
		}
	qsort(stack, pointer, sizeof(int), compare);
			
	printf("%d\n", pointer);
	for (int i = 0; i < pointer; i++)
		printf("%d\n", stack[i]);
}

int countWidth(int x, int y) {
	if (x >= N || y >= N || x < 0 || y < 0 || visited[x][y] == 1 || ground[x][y] == 0)
		return 0;
	visited[x][y] = 1;

	return 1 + countWidth(x + 1, y) + countWidth(x - 1, y) + countWidth(x, y + 1) + countWidth(x, y - 1);
}

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;    // 오름차순
}