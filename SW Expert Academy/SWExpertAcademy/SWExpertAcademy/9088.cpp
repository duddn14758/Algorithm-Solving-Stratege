//다이아몬드
#include <stdio.h>
#define MAX 1000
#define MAXD 10000

int dia[MAX + 1];

void selec(int n,int top) {
	int i = 0;
	int pos = 0;
	for (i = 0; i < top; i++) {
		if (dia[i] > n) break;
	}
	pos = i;
	for (int j = top; j > pos; j--) {
		dia[j] = dia[j - 1];
	}
	dia[pos] = n;
}

int main() {
	int TC, N, K,buf;
	scanf("%d", &TC);

	for (int k = 1; k <= TC; k++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &buf);
			selec(buf, i);
		}
		int maxSize = 0;
		int head = 0, tail = 0;
		while (tail < N) {
			while (tail < N&& dia[tail] - dia[head] <= K) {
				tail++;			
			}
			maxSize = maxSize > tail - head ? maxSize : tail - head;
			head++;
		}
		printf("#%d %d\n", k, maxSize);
	}

	return 0;
}