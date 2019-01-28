#include <iostream>

int dp[1000001];

int main() {
	int n;
	std::cin >> n;
	
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] * 2 + 1;
	}
	std::cout << dp[n]%15746;

	return 0;
}