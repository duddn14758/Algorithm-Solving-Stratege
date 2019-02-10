#include <stdio.h>
#include <stdlib.h>

int **arr;
int *visited;
int length,end;

int main() {
	FILE *fp = fopen("input.txt", "r");
	int N, T,num;
	int start;
	int result = 0;

	fscanf(fp, "%d", &N);

	while(N--) {
		fscanf(fp, "%d", &T);
		arr = (int**)malloc(sizeof(int*)*T);
		visited = (int*)malloc(sizeof(int)*T);
		for(int i=0;i<T;i++) {
			fscanf(fp, "%d", &num);
			arr[i] = malloc(sizeof(int)*(num+1));
			visited[i] = 0;
			arr[i][0] = num;
			for (int j = 1; j < num+1; j ++ ) {
				fscanf(fp, "%d", &arr[i][j]);
			}
		}
		fscanf(fp, "%d %d %d", &start, &end, &length);
		
		printf("°¹¼ö : %d\n", findMap(start, 0));

		free(arr[0]);
		free(arr);
	}

	return 0;
}

int findMap(int point,int cur) {

	int result = 0;
	if (visited[point] == 1) {
		return 0;
	}

	if (cur > length)
		return 0;
	else if (point == end && cur <= length) {
		return 1;
	}
	else
		visited[point] = 1;
	
	for (int i = 1; i <= arr[point][0]; i++) {
		result += findMap(arr[point][i], cur + 1);
	}

	visited[point] = 0;
	return result;
}