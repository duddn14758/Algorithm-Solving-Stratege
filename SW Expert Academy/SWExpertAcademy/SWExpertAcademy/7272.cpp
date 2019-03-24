#include <iostream>
#include <string>

// 안경이 없어
using namespace std;

char one[] = { "ADOPQR" };
char zero[] = { "CEFGHIJKLMNSTUVWXYZ" };

int circle(char c) {
	for (int i = 0; i < 6; i++)
		if (c == one[i]) return 1;
	for (int i = 0; i < 19; i++)
		if (c == zero[i]) return 0;
	return 2;
}

int main() {
	int c;
	string buf1, buf2,ans;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> buf1 >> buf2;
		ans = "SAME";
		if (buf1.length() != buf2.length()) ans = "DIFF";
		else {
			for (int j = 0; j < buf1.length(); j++) {
				if (circle(buf1[j]) != circle(buf2[j])) ans = "DIFF";
			}
		}
		cout << "#" << i + 1 << " " << ans << endl;
	}
	return 0;
}