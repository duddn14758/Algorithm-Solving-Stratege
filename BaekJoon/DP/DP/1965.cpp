#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n,mx=0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[j] + 1,dp[i]);	// 무조건 arr[i]가arr[j] 보다 크다고 dp[i]=dp[j]+1로 update하면 안됨!
		}
		mx = max(mx, dp[i]);
	}
	cout << mx;

	return 0;
}