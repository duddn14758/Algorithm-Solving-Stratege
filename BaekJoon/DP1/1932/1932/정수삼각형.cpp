#include <stdio.h>

int tree[501][501];
int dp[501][501];

int main() {
	int num;
	int max = 0;

	scanf("%d", &num);
	scanf("%d", &tree[0][0]);
	dp[0][0] = tree[0][0];

	for (int i = 1; i < num; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &tree[i][j]);
			if (j == 0) dp[i][j] = dp[i - 1][j];
			else if (i == j) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = dp[i - 1][j-1] > dp[i-1][j] ? dp[i - 1][j-1] : dp[i - 1][j];
			dp[i][j] += tree[i][j];
			//printf("%d ", dp[i][j]);
		}
		//printf("\n");
	}
	for (int i = 0; i < num; i++)
		max = max > dp[num - 1][i] ? max : dp[num - 1][i];
	printf("%d\n", max);

	return 0;
}