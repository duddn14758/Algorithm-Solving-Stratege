#include <iostream>
#include <limits.h>

// 파일 합치기
using namespace std;

int arr[501];
int dp[501][501];
int sum[501];

int main() {
	int t,c,buf;
	cin >> t;

	while (t-- > 0) {
		cin >> c;
		for (int i = 1; i <= c; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];
		}
		
		for (int d = 1; d < c; d++) {
			for (int tx = 1; tx + d <= c; tx++) {
				int ty = tx + d;
				dp[tx][ty] = INT_MAX;

				for (int mid = tx; mid < ty; mid++) {
					dp[tx][ty] =
						dp[tx][ty] < dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1] ?
						dp[tx][ty] : dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1];
				}		
			}
		}
		cout << dp[1][c] << endl;
	}
	return 0;
}