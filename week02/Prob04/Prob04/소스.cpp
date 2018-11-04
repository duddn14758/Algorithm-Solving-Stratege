#include <stdio.h>
#include <stdlib.h>

int getCount(int size);

int *length;
int N;

int main() {
	int K;
	long long lower=1, upper;
	int best = 0;
	long long max = 0;

	scanf("%d %d", &N, &K);

	length = (int*)malloc(sizeof(int)*N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &length[i]);
		max = max < length[i] ? length[i] : max;
	}
	upper = max;

	while (lower<=upper) {
		long long mid = (upper+lower) / 2;
		int count = getCount(mid);

		if (count < K)
			upper = mid - 1;
		else {
			best = best < mid ? mid : best;
			lower = mid + 1;
		}
	}
	printf("%d\n", best);
	   
	return 0;
}

int getCount(int size) {
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += length[i] / size;
	}
	return sum;
}