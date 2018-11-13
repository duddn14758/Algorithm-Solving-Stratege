#include <stdio.h>
#include <stdbool.h>

int **arr;
int *visited;
int K;

int main() {
	FILE *fp;
	int T, N;
	int buffer;
	int number;

	fp = fopen("input13.txt", "r");

	fscanf(fp, "%d", &T);
	while (T--) {
		fscanf(fp, "%d %d", &N, &K);
		arr = (int**)malloc(sizeof(int*)*N);
		visited = (int*)malloc(sizeof(int)*N);
		
		for (int i = 0; i < N; i++) {
			visited[i] = 0;
			fscanf(fp, "%d", &buffer);
			fscanf(fp, "%d", &buffer);
			fscanf(fp, "%d", &buffer);
			fscanf(fp, "%d", &number);
			arr[i] = (int*)malloc(sizeof(int)*(number + 1));
			arr[i][0] = number;
			for (int j = 1; j <= number; j++) {
				fscanf(fp, "%d", &arr[i][j]);
			}
		}
		printf("%d", getCycle(N));
	}


	return 0;
}

int getCycle(int N) {
	int num = 0;
	for (int i = 0; i < N; i++) {
		num+=Cycle(i, i,0);
	}
	return num;
}

int Cycle(int start, int cur,int count) {
	
	if (start == cur && count == K) {
		printf("current : %d, count : %d\n",cur,count);
		return 1;
	}
	else if (visited[cur] == 1) {
		return 0;
	}
	else if (count >= K)
		return 0;

	visited[cur] = 1;
	
	int num = 0;
	for (int i = 1; i <= arr[cur][0]; i++) {
		num += Cycle(start, arr[cur][i] - 1, count + 1);
	}
	visited[cur] = 0;
	return num;
}