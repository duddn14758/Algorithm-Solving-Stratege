#include <iostream>
#include <algorithm>
#include <string.h>
#define Pii pair<int,int>

// ��
using namespace std;
// ���η��� : �޸𸮺��� �ּҺ���� dp

int dp[101][10001];
int mem[101],cost[101];

int getDP(int idx, int totalCost) {
	// ������� : �����ʰ���
	if (idx >= 100) return 0;
	int &result = dp[idx][totalCost];		// result�� dp�� �ٷ� update�� �� �ֵ��� �ּҸ� ���� 
	if (result != -1) return result;		// �ش� �޸� ����
	result = getDP(idx + 1, totalCost);	// �ش� ���� ��Ȱ��ȭ �Ƚ����� ���
	// totalCost���� �ش� �ε��� ���� ���� �۴ٸ� update
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
		if (getDP(0, totalCost)>=m) {	// �ش� �޸𸮸� �Ѵ´ٸ�
			cout << totalCost << endl;
			break;
		}
		totalCost++;
	}
	return 0;
}