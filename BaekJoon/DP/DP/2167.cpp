#include <iostream>

// 2차원 배열의 합
using namespace std;

int arr[301][301];
int dp[301][301];

int main() {
	int n, m, k, start_x, start_y, dest_x, dest_y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> start_x >> start_y >> dest_x >> dest_y;
		cout << dp[dest_x][dest_y] - dp[dest_x][start_y - 1] - dp[start_x - 1][dest_y] + dp[start_x - 1][start_y - 1] << endl;
	}

	return 0;
}