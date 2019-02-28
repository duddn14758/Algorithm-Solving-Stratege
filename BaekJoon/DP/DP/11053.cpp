#include <iostream>

// 가장 긴 증가하는 부분
using namespace std;

int dp[1001];
int arr[1001];

int getCloseSmall(int n) {
	for (int i = n-1; i >= 0; i--) {
		if (arr[i] < arr[n])
			return i;
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) dp[i] = 1;
		else dp[i]=d
	}

	return 0;
}