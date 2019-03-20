#include <iostream>

// 초콜릿 자르기
using namespace std;

int dp[301][301], cnt = 0;

int main() {
	int n, m;
	cin >> n >> m;

	dp[1][1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1 && j == 1) continue;
			if (i > j) {
				if (i % 2==0) dp[i][j] = dp[i / 2][j] * 2 + 1;
				else dp[i][j] = dp[i / 2][j] + dp[i / 2 + 1][j] + 1;
			}
			else {
				if (j % 2==0) dp[i][j] = dp[i][j/2] * 2 + 1;
				else dp[i][j] = dp[i][j/2] + dp[i][j/2+1] + 1;
			}
		}
	}
	cout << dp[n][m];

	return 0;
}