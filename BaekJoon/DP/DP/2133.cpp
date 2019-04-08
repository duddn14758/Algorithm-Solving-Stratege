#include <iostream>

// 타일 채우기
using namespace std;

int dp[31];

int main() {
	int n;
	cin >> n;
	
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	
	for (int i = 4; i <= n; i+=2) {
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j++) dp[i] += 2 * dp[i - j];
	}
	cout << dp[n];

	return 0;
}