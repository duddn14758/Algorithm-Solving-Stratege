#include <iostream>

// µ¿Àü 0
using namespace std;

int arr[11];

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	while (k > 0) {		
		while (arr[--n] > k);
		while (arr[n] <= k) {
			k -= arr[n];
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}