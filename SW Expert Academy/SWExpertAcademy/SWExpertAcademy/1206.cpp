#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[5];

int getMaxPoint() {
	int max_point = 0;
	for (int i = 1; i < 5; i++) {
		if (arr[i] > arr[max_point])
			max_point = i;
	}
	return max_point;
}

int getSecondHigh(int max_point) {
	int second = max_point == 0 ? 1 : 0;
	for (int i = 0; i < 5; i++) {
		if (i == max_point) continue;
		if (arr[i] > arr[second])
			second = i;
	}
	return arr[max_point] - arr[second];
}

int main() {
	int n, cnt=0;
	
	for(int k=0;k<10;k++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i % 5];
			int max_point = getMaxPoint();
			if ((i - 2) % 5 == max_point) {
				cnt += getSecondHigh(max_point);
			}
		}
		cout << "#" << k + 1 << " " << cnt << endl;
		cnt = 0;
	}

	return 0;
}