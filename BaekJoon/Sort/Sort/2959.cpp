#include <iostream>
#include <algorithm>

// °ÅºÏÀÌ
using namespace std;

int main() {
	int arr[5];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	sort(arr, arr + 4);
	cout << arr[0] * arr[2];

	return 0;
}