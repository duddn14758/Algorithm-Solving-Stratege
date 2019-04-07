#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int dp[1001];
int arr[1001];

int main() {
	int n,mx=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[i];
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = dp[j] +arr[i] > dp[i]?dp[j] + arr[i] : dp[i];
			}
		}
		mx = max(mx, dp[i]);
	}
	cout << mx;

	return 0;
}