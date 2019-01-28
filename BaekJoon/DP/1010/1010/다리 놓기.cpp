#include <iostream>

int dp[35][35];

int main() {
	int c,l,r;
	std::cin >> c;

	for (int i = 1; i < 35; i++) {
		dp[i][i] = 1;
		for (int j = i+1; j < 35; j++) {
			if (i == 1) dp[i][j] = j;
			else dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}

	while (c-- > 0) {
		std::cin >> l >> r;
		std::cout << dp[l][r] << std::endl;
	}

	return 0;
}