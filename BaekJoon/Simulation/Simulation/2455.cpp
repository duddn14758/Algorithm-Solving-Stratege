#include <iostream>

// 지능형 기차
using namespace std;

int main() {
	int in, out, total = 0, mx=0;
	for (int i = 0; i < 4; i++) {
		cin >> out >> in;
		total += in;
		total -= out;
		mx = total > mx ? total : mx;
	}
	cout << mx;

	return 0;
}