#include <iostream>
#include <algorithm>
#include <string.h>

// ÇÕºÐÇØ
using namespace std;

long long dp[201][201];

int main() {
	int n ,k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 1) dp[i][j] = 1;
			else
			for (int m = 0; m <= j; m++) {
				dp[i][j] += dp[i - 1][m];
			}
			dp[i][j] %= 1000000000;
		}
	}
	cout << dp[k][n];

	return 0;
}