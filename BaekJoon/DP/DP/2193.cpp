#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

// ÀÌÄ£¼ö
using namespace std;

pair<long long, long long> arr[91];

int main() {
	int n;
	cin >> n;
	
	memset(arr, 0, sizeof(arr));
	arr[0] = { 0,1 };

	for (int i = 1; i < n; i++) {
		arr[i].first = arr[i - 1].second+arr[i-1].first;
		arr[i].second = arr[i - 1].first;
	}
	cout << arr[n - 1].first + arr[n - 1].second;

	return 0;
}