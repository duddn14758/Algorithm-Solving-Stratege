#include <iostream>

// 만취한 상범
using namespace std;

int dp[101][101];

int main() {
	int t, n;

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++)
			dp[i][j] = dp[i - 1][j];
		for (int j = i; j <= 100; j+=i) {
			dp[i][j] += 1;
		}		
	}
	/*
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/
	cin >> t;

	while (t-- > 0) {
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (dp[n][i] % 2) ans++;
		}
		cout << ans << endl;
	}

	return 0;
}