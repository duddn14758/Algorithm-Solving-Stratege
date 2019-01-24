#include <stdio.h>
#include <stdlib.h>

int map[2][101];

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;    // 오름차순
}

int rcompare(const void *a, const void *b)
{
	return *(int *)b - *(int *)a; 
}

int n, min = 0;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[0][i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &map[1][i]);
	}
	
	qsort(map[0], n, 4, compare);
	qsort(map[1], n, 4, rcompare);

	for (int i = 0; i < n; i++) {
		min += map[0][i] * map[1][i];
	}

	printf("%d\n", min);

	return 0;
}