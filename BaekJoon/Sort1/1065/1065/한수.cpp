#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int num, count;
	int o, t, h;
	cin >> num;

	if (num < 100) {
		cout << num;
	}
	else {
		count = 99;
		for (int i = 100; i <= num; i++) {
			if (i == 1000)
				break;
			o = i % 10;
			t = (i / 10) % 10;
			h = (i / 100) % 10;
			if (h - t == t - o)
				count++;
		}
		cout << count;
	}

	return 0;
}