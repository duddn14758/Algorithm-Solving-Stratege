#include <stdio.h>

struct point {
	int l, r;
};

point line[1000];

int main() {
	int TC,N;
	scanf("%d", &TC);
	for (int k = 1; k <= TC; k++) {
		scanf("%d", &N);
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &line[i].l, &line[i].r);
			for (int j = 0; j < i; j++) {
				if ((line[i].l<line[j].l && line[i].r>line[j].r)
					|| line[i].l > line[j].l&& line[i].r < line[j].r)
					cnt++;
			}
		}
		printf("#%d %d\n", k, cnt);
	}

	return 0;
}