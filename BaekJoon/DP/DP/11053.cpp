#include <iostream>
#include <vector>

// ���� �� �����ϴ� �κ�
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	int n, min_num,max_num=0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> arr[i];
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		min_num = 0;
		for (int j = 0; j < i; j++) {	// �ڱ⺸�� ���� ���� �� dp�� �ִ��� �� + 1
			if (arr[i] > arr[j]) {
				min_num = dp[j] > min_num ? dp[j] : min_num;
			}
		}
		dp[i] = min_num + 1;
		max_num = dp[i] > max_num ? dp[i] : max_num;
		//cout << max_num << " ";
	}		
	cout << max_num;

	return 0;
}