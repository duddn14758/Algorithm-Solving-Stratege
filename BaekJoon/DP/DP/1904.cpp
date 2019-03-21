#include <iostream>

// 01Å¸ÀÏ
long long dp[1000002];

int main() {
	int n;
	std::cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	std::cout << dp[n];

	return 0;
}