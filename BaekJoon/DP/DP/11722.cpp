#include <iostream>

// 가장 긴 감소하는 부분 수열
using namespace std;
int arr[1001];
int dp[1001];

int main() {
	int a, max_len=0;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> arr[i];
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[i]) dp[i] = dp[j] + 1 > dp[i] ? dp[j] + 1 : dp[i];
			max_len = max_len > dp[i] ? max_len : dp[i];
		}
	}
	cout << max_len;

	return 0;
}