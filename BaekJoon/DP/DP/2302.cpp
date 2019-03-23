#include <iostream>

// ±ØÀå ÁÂ¼®
using namespace std;
int vip[41];
int dp[41];

int main() {
	int n,vp;
	cin >> n >> vp;
	vip[0] = 0;
	for (int i = 1; i <= vp; i++) {
		cin >> vip[i];
	}
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;	
	for (int i = 3; i <= n+1; i++) {
		dp[i] = dp[i - 2] * 2 + dp[i-3];
	}
	int org = 1;	
	for (int i = 0; i < vp; i++) {
		org *= dp[vip[i + 1] - vip[i]-1];
	}
	if (n - vip[vp] > 0) org *= dp[n - vip[vp]];
	cout << org;

	return 0;
}