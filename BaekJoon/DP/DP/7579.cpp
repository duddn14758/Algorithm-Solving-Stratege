#include <iostream>
#include <algorithm>
#include <string.h>
#define Pii pair<int,int>

// 앱
using namespace std;
// 메인로직 : 메모리별로 최소비용을 dp

int dp[101][10001];
int mem[101],cost[101];

int getDP(int idx, int totalCost) {
	// 기저사례 : 범위초과시
	if (idx >= 100) return 0;
	int &result = dp[idx][totalCost];		// result에 dp를 바로 update할 수 있도록 주소를 저장 
	if (result != -1) return result;		// 해당 메모리 리턴
	result = getDP(idx + 1, totalCost);	// 해당 앱을 비활성화 안시켰을 경우
	// totalCost보다 해당 인덱스 내의 값이 작다면 update
	if (cost[idx] <= totalCost)
		result = max(result, mem[idx] + getDP(idx + 1, totalCost - cost[idx]));
	return result;	
}

int main() {
	int n, m;
	cin >> n >> m;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++)
		cin >> mem[i];
	for (int i = 0; i < n; i++)
		cin >> cost[i];
	int totalCost = 0;
	while (1) {
		if (getDP(0, totalCost)>=m) {	// 해당 메모리를 넘는다면
			cout << totalCost << endl;
			break;
		}
		totalCost++;
	}
	return 0;
}