#include <iostream>
#include <algorithm>
#include <string.h>

// 내려가기
using namespace std;

int arr[3];
int dp_min[2][3];
int dp_max[2][3];

int main() {
	int n, i, mx, mn;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[0] >> arr[1] >> arr[2];

		dp_min[i % 2][0] = min(dp_min[(i + 1) % 2][0], dp_min[(i + 1) % 2][1]);
		dp_min[i % 2][2] = min(dp_min[(i + 1) % 2][1], dp_min[(i + 1) % 2][2]);
		dp_min[i % 2][1] = min(dp_min[i % 2][0], dp_min[i % 2][2]);

		dp_max[i % 2][0] = max(dp_max[(i + 1) % 2][0], dp_max[(i + 1) % 2][1]);
		dp_max[i % 2][2] = max(dp_max[(i + 1) % 2][1], dp_max[(i + 1) % 2][2]);
		dp_max[i % 2][1] = max(dp_max[i % 2][0], dp_max[i % 2][2]);
		
		for (int j = 0; j < 3; j++) {
			dp_min[i % 2][j] += arr[j];
			dp_max[i % 2][j] += arr[j];
		}
	}
	mx = max(max(dp_max[(i + 1) % 2][0], dp_max[(i + 1) % 2][1]), dp_max[(i + 1) % 2][2]);
	mn = min(min(dp_min[(i + 1) % 2][0], dp_min[(i + 1) % 2][1]), dp_min[(i + 1) % 2][2]);

	cout << mx << " " << mn;

	return 0;
}