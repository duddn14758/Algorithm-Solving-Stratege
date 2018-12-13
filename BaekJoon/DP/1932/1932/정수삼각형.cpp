#include <stdio.h>

int tree[501][501];
int dp[501][501];

int main() {
	int num;

	scanf("%d", &num);

	scanf("%d", &tree[0][0]);
	scanf("%d", &dp[0][0]);

	for (int i = 1; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &tree[i][j]);
			if (j == 0) dp[i][j] = tree[i - 1][j];
			else if (i == j) dp[i][j] = tree[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j] > dp[i][j + 1] ? dp[i - 1][j] : dp[i - 1][j + 1];
			dp[i][j] += tree[i][j];
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}


	return 0;
}