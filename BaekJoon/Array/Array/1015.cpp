#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int arr[51];
int arrb[51];
int arrc[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arrb[i] = arr[i];
	}
	sort(arrb, arrb + n);
	
	for (int i = 0; i < n; i++)
		arrc[arrb[i]] = i;

	for (int i = 0; i < n; i++) {
		cout << arrc[arr[i]] << " ";
	}

	return 0;
}