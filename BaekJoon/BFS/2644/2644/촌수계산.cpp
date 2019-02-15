#include <iostream>
#include <vector>

using namespace std;

vector<int> pv[105];
vector<int> cv[105];

int t, st, ed, ans = -1;

void search(int now ,int cnt, int prev) {
	if (now == ed) {
		ans = cnt;
		return;
	}

	if (!pv[cv[now].front()].empty()) {
		if (cv[now].front() == ed) {		// 부모 일치 확인
			ans = cnt + 2;
			return;
		}
		for (int i = 0; i < pv[cv[now].front()].size(); i++) {	// 형제탐색
			if (pv[cv[now].front()][i] == ed) {
				ans = cnt + 1;
				return;
			}			
		}
		search(cv[now].front(), cnt + 2, now);
	}
	for (int i = 0; i < pv[now].size(); i++) {
		if (pv[now][i] == ed) {
			ans = cnt + 2;
			return;
		}
		search(pv[now][i], cnt + 2, now);
	}
}


int main() {
	int p, c, n;
	cin >> t >> st >> ed >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> c;
	
		pv[p].push_back(c);
		cv[c].push_back(p);
	}
	search(st, 0,0);
	cout << ans;

	return 0;
}