#include <stdio.h>
#include <stdlib.h>

int main() {
	int T, N;
	int sum;
	int *arr;

	scanf("%d", &T);

	while (T--) {
		scanf("%d %d", &N,&sum);
		arr = (int*)malloc(sizeof(int)*N);
		int min = -1;
		int tail = 0;
		int cur = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			cur += arr[i];
			if (cur >= sum) {

				while (cur >= sum) {
					cur -= arr[tail++];					
				}
				if (min != -1) {
					min = min < i - tail+1 ? min : i - tail+1;
				}
				else {
					min = i - tail + 1;
				}

			}			

		}
		printf("answer : %d\n", min);


		free(arr);
	}


	return 0;
}