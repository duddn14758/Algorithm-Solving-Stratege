#include <stdio.h>
#include <stdlib.h>

// 피보나치 함수

//     1 0 호출
// 0 - 0 1
// 1 - 1 0
// 2 - 1 1
// 3 - 2 1

int dp[41][2];

int main() {
	int n,f;
	scanf("%d", &n);

	dp[0][1] = 0;
	dp[0][0] = 1;
	dp[1][1] = 1;
	dp[1][0] = 0;

	for (int i = 2; i <= 40; i++) {
		for(int j=0;j<=1;j++)
			dp[i][j] = dp[i - 1][j] + dp[i - 2][j];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &f);
		printf("%d %d\n", dp[f][0],dp[f][1]);
	}

	return 0;
}