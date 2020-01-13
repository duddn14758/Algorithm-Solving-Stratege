#include <stdio.h>

int C = 0;

int tree[300002];

void insert(int num, int now) {
	C++;
	if (num < tree[now]) {
		now *= 2;
		if (tree[now] == 0) {
			tree[now] = num;
		}
		else {
			insert(num, now);
		}
	}
	else {
		now = now * 2 + 1;
		if (tree[now] == 0) {
			tree[now] = num;
		}
		else {
			insert(num, now);
		}
	}
}

int main() {
	int N, num;
	scanf("%d", &N);
	scanf("%d", &tree[1]);
	printf("0\n");
	for (int i = 1; i < N; i++) {
		scanf("%d", &num);
		insert(num, 1);
		printf("%d\n", C);
	}
	return 0;
}