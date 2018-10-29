#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	clock_t start, end;
	FILE *fp;
	int N, K;
	int **arr;
	int count = 0;
	int max_count = 0;
	int tail = 0;
	int buffer;


	fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &N);

	while(N--) {

		fscanf(fp, "%d", &K);
		arr = (int**)malloc(sizeof(int*)*K);
		for (int i = 0; i < K; i++) {
			arr[i] = (int*)malloc(sizeof(int) * 2);		
		
		}

		for (int i = 0; i < K; i++) {
			fscanf(fp, "%d", &buffer);
			for (int j = tail; j < i; j++) {
				if (arr[j] == arr[tail])
					tail = j;
			}
			max_count = max_count < i - tail ? i - tail : max_count;
		}
		printf("max count = %d\n", max_count);
		max_count = 0;
		tail = 0;
	}


	return 0;
}