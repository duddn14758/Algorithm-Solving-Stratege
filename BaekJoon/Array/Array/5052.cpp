#include <iostream>
#include <vector>
#include <string>
#include <math.h>

// 전화번호 목록 by int devide
using namespace std;
vector <pair<int, int>> v;

int main() {
	int t, c;
	string s;
	int phone_num,phone_len;

	cin >> t;
	while (t-- > 0) {
		cin >> c;
		bool consistency = true;
		int k;
		for (int i = 0; i < c; i++) {
			cin >> s;
			phone_num = stoi(s);
			phone_len = s.length();
			v.push_back({ phone_num,phone_len });
			for (int j = 0; j < i; j++) {
				int buf1, buf2;
				if (v[j].second > phone_len) {	// buf1이 나눌수
					buf1 = v[j].first;
					buf2 = phone_num;
				}
				else {
					buf2 = v[j].first;
					buf1 = phone_num;
				}
				//cout << buf1 << ", " << buf2 << endl;
				for (int k = 0; k < abs(phone_len - v[j].second); k++) {
					buf1 /= 10;
				}
				if (buf1 == buf2) {
					consistency = false;
					break;
				}
			}			
		}
		if (consistency) cout << "YES" << endl;
		else cout << "NO" << endl;
		v.clear();
		consistency = true;
	}
	return 0;
}