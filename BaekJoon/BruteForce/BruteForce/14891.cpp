#include <iostream>

using namespace std;

bool tow[5][9];
int st[5];

int ddb(int n) {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		ret *= 2;
	}
	return ret;
}

int main() {
	int t,t_num,r;
	int rr[4], ll[4];
	char buf[10];
	for (int i = 0; i < 4; i++) {
		cin >> buf;
		st[i] = 0;
		for (int j = 0; j < 8; j++)
			if (buf[j] == '0') tow[i][j] = 0;
			else tow[i][j]=1;
	}
	cin >> t;
	while (t-->0) {
		cin >> t_num >> r;

		bool lright,rright;
		if (r == 1) {		// 1:시계방향,오른쪽
			ll[t_num-1] = 1;
			lright = 1;
			rright = 1;
		}
		else {
			ll[t_num - 1] = 2;
			lright = 0;
			rright = 0;
		}
		lright = !lright;
		rright = !rright;

		for (int i = t_num-2; i >= 0; i--) {	// 맞닿은 극이 다르면 회전 check
			if (tow[i][(st[i] + 2) % 8] != tow[i+1][(st[i + 1] + 6) % 8]) {
				if (lright) ll[i] = 1;
				else ll[i] = 2;
				lright = !lright;
			}
			else break;
		}

		for (int i = t_num; i < 4; i++) {
			if (tow[i][(st[i] + 6) % 8] != tow[i - 1][(st[i - 1] + 2) % 8]) {
				if (rright) ll[i] = 1;
				else ll[i] = 2;
				rright = !rright;
			}
			else break;
		}

		for (int i = 0; i < 4; i++) {
			if (ll[i] == 1) st[i] = (st[i] + 7) % 8;
			else if (ll[i] == 2) st[i] = (st[i] + 1) % 8;
		}

		for (int i = 0; i < 4; i++) {
			ll[i] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += ddb(i)*tow[i][st[i]];
	}
	cout << ans;

	return 0;
}