#include <stdio.h>
#include <stdlib.h>
#define R 2
#define B 3
#define L 4
#define T 5

int **map;
int K;
bool findPath(int i, int j, int direction);

int main() {
	int N;

	scanf("%d", &N);

	while (N--) {
		scanf("%d", &K);

		map = (int**)malloc(sizeof(int*)*K);
		for (int i = 0; i < K; i++) {
			map[i] = (int*)malloc(sizeof(int)*K);
		}

		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		if (findPath(0, 0, R))
			printf("YES\n");
		else
			printf("NO");

		free(map[0]);
		free(map);
	}

	return 0;
}

bool findPath(int i, int j, int direction) {

	if (i < 0 || j < 0  || i >= K || j >= K || map[i][j] == direction || map[i][j] == 1) {
		return false;
	}

	if (i == K - 1 && j == K - 1)
		return true;
	
	map[i][j] = direction;

	if (direction == R)
		return (findPath(i, j + 1, R) || findPath(i + 1, j, B));			
	else if (direction == B)
		return (findPath(i + 1, j, B) || findPath(i, j - 1, L));
		else if (direction == L)
			return (findPath(i, j - 1, L) || findPath(i - 1, j, T));
		else if (direction == T)
			return (findPath(i - 1, j, T) || findPath(i, j + 1, R));
			

	map[i][j] = 0;
	return false;
}