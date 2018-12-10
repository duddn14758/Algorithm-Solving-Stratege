#include <stdio.h>

int dp[12];

int main() {
	int num;
	int n;
	scanf("%d", &num);

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for (int i = 4; i < 12; i++) {
		dp[i] = 0;
		for (int j = 1; j <= 3; j++) {
			dp[i] += dp[i - j];
		}
	}

	for (int i = 0; i < num; i++) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}

	return 0;
}