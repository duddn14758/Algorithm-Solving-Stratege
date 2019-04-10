#include <iostream>
#include <algorithm>
#include <string.h>

// 이동하기
using namespace std;

int maze[1001][1001];
int dp[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
			dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1])+maze[i][j];
		}
	cout << dp[n][m];
	return 0;
}