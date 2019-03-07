#include <iostream>
#include <algorithm>

// ทฮวม
using namespace std;

int arr[100001];

int main() {
	int n, max_weight, sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	max_weight = arr[0] * n;
		
	for (int i = 1; i < n; i++) {
		sum = arr[i] * (n - i);
		max_weight = max_weight > sum ? max_weight : sum;
	}
	cout << max_weight;

	return 0;
}