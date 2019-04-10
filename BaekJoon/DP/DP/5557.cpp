#include <iostream>

using namespace std;

long long dp[105][25];

int main() {
	int n,num;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> num;
		if (i == 1) dp[i][num] = 1;
		else
		for (int j = 0; j <= 20; j++) {
			if (dp[i-1][j]&&j + num <= 20 && j + num >= 0) dp[i][j + num] += dp[i - 1][j];
			if (dp[i-1][j]&&j - num <= 20 && j - num >= 0) dp[i][j - num] += dp[i - 1][j];
		}
	}
	cin >> num;
	
	cout << dp[n-1][num];

	return 0;
}