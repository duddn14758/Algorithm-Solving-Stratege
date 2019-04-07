#include <iostream>
#include <algorithm>
#include <string.h>

// RGB°Å¸®
using namespace std;

int cost[1001][3];
int dp[1001][3];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	for(int i=1;i<=n;i++)
		for (int j = 0; j < 3; j++) {
			switch (j) {
			case 0:
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]);
				break;
			case 1:
				dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]);
				break;
			case 2:
				dp[i][j] = min(dp[i - 1][1], dp[i - 1][0]);
				break;
			}
			dp[i][j] += cost[i][j];
		}
	int ans = dp[n][0];
	for (int i = 1; i < 3; i++)
		ans = min(ans, dp[n][i]);
	cout << ans;

	return 0;
}