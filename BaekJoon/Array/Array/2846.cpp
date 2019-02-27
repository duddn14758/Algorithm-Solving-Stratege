#include <iostream>

// 오르막길
using namespace std;

int main() {
	int n, up=0, high, pt1, pt2, prev;
	cin >> n >> pt1;
	prev = pt1;
	for (int i = 1; i < n; i++) {
		cin >> high;
		if (high <= prev) pt1 = high;
		pt2 = high;
		up = up > pt2 - pt1 ? up : pt2 - pt1;
		prev = high;
	}
	cout << up;

	return 0;
}