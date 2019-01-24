#include <stdio.h>

void setDP();
long long dp[200000];

int main() {
	int a, b, c, distance;

	scanf("%d", &c);
	setDP();
	while (c-- > 0) {
		scanf("%d %d", &a, &b);
		distance = b - a;
		for (int i = 1; i < 200000; i++) {
			if (dp[i] >= distance) {
				printf("%d\n", i);
				break;
			}
		}		
	}
}

void setDP() {
	dp[1] = 1;
	for (int i = 2; i < 200000; i++) {
		if (i % 2 == 1)
			dp[i] = dp[i - 1] + i / 2 + 1;
		if (i % 2 == 0)
			dp[i] = dp[i - 1] + i / 2;
	}
}