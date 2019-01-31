#include <iostream>

int dp[2][10001];

int main() {
	int n, k, exp;
	std::cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		std::cin >> exp;
		dp[i%2][0] = 1;
		for (int j = 1; j <= k; j++) {
			if (i == 0) dp[i][j] = j % exp == 0 ? 1 : 0;
			else {
				dp[i%2][j] = dp[(i+1)%2][j];
				if (j >= exp) dp[i%2][j] += dp[i%2][j - exp];
			}
		}
	}
	std::cout << dp[(n+1)%2][k];

	return 0;
}