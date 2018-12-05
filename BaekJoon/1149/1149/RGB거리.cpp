#include <stdio.h>

int N;
int color[1001][3];
int cost[1001][3];

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++) {
			scanf("%d", &color[i][j]);
			if (i == 0)
				cost[i][j] = color[i][j];
			else {
				switch (j) {
				case 0:
					cost[i][j] = cost[i - 1][1] < cost[i - 1][2] ? cost[i - 1][1] : cost[i - 1][2];
					break;
				case 1:
					cost[i][j] = cost[i - 1][0] < cost[i - 1][2] ? cost[i - 1][0] : cost[i - 1][2];
					break;
				case 2:
					cost[i][j] = cost[i - 1][0] < cost[i - 1][1] ? cost[i - 1][0] : cost[i - 1][1];
					break;
				}
				cost[i][j] += color[i][j];
			}
		}
	int min = cost[N - 1][0] < cost[N - 1][1] ? cost[N - 1][0] : cost[N - 1][1];
	min = min < cost[N - 1][2] ? min : cost[N - 1][2];
	printf("%d\n", min);

	return 0;
}