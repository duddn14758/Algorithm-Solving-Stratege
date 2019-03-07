#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 전화번호 목록 by ascending sort
using namespace std;

string s[10001];

int main() {
	int t, c, buf=0;

	cin >> t;
	while (t-- > 0) {
		cin >> c;
		bool consistency = true;
		int k;
		for (int i = 0; i < c; i++) {
			cin >> s[i];
		}
		sort(s, s + c);

		for (int i = 1; i < c; i++) {
			if (s[i].length() <= s[i - 1].length()) continue;
			else {
				int j;
				for (j = 0; j < s[i - 1].length(); j++) {
					if (s[i][j] != s[i - 1][j]) break;
				}
				if (j == s[i - 1].length()) {
					consistency = false;
					break;
				}
			}
		}
		if (consistency) cout << "YES" << endl;
		else cout << "NO" << endl;
		consistency = true;
	}
	return 0;
}