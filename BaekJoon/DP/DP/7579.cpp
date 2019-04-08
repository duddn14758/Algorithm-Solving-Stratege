#include <iostream>
#include <algorithm>
#include <string.h>
#define Pii pair<int,int>

// 앱
using namespace std;

int dp[10000000];
Pii mem[101];

int main() {
	int n, m;
	cin >> n >> m;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		cin >> mem[i].first;
	for (int i = 0; i < n; i++)
		cin >> mem[i].second;
	sort(mem, mem + n);

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i; k++) {
				if (i == k) continue;
				// mem[j]+mem[k]>mem[i]보다 클경우에 cost비교
			}
		}
	}

	return 0;
}