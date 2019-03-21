#include <stdio.h>
#include <queue>
void DP(int count);

// ½ºÆ¼Ä¿
using namespace std;

int dp[100001][2];
int sticker[100001][2];

int main() {
	int C, n;
	scanf("%d", &C);
	int answer;

	while (C-- > 0) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < n; i++) {
				scanf("%d", &sticker[i][j]);
			}
		}
		for (int i = 0; i < n; i++)
			DP(i);
		answer = dp[n - 1][0] > dp[n - 1][1] ? dp[n - 1][0] : dp[n - 1][1];
		printf("%d\n", answer);
	}

	return 0;
}

void DP(int count) {
	if (count == 0) {
		dp[count][0] = sticker[count][0];
		dp[count][1] = sticker[count][1];
	}
	else if (count == 1) {
		dp[count][0] = sticker[count - 1][1] + sticker[count][0];
		dp[count][1] = sticker[count - 1][0] + sticker[count][1];
	}
	else {
		int buf = dp[count - 2][0] > dp[count - 2][1] ? dp[count - 2][0] : dp[count - 2][1];
		dp[count][0] = dp[count - 1][1] > buf ? dp[count - 1][1] : buf;
		dp[count][1] = dp[count - 1][0] > buf ? dp[count - 1][0] : buf;
		dp[count][0] += sticker[count][0];
		dp[count][1] += sticker[count][1];
	}
}