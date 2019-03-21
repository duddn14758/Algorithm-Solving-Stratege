#include <iostream>

// 오르막수
int dp[1001][10];

int main() {
	int num, prev, count = 0;
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		count = 0;
		for (int j = 0; j < 10; j++) {
			if (i == 0) dp[i][j] = 1;
			else {
				dp[i][j] = prev % 10007;
				prev -= dp[i - 1][j] % 10007;
			}
			count += dp[i][j];
		}
		prev = count;
	}
	std::cout << count % 10007;

	return 0;
}