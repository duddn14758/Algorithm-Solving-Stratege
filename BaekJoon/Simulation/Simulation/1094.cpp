#include <iostream>

// ¸·´ë±â
using namespace std;

int main() {
	int a, cnt=0;
	cin >> a;

	while (a > 0) {
		int b = 1;
		while (b <= a) { b *= 2; }
		if(b>1) b /= 2;
		a -= b;
		cnt++;
	}
	cout << cnt;

	return 0;
}