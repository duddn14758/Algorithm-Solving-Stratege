#include <iostream>
#include <vector>
#include <cstring>

// 촌수계산
using namespace std;

vector<int> pv[105];
int cv[105];
bool visited[105];

int t, st, ed, ans = 1000000;

void search(int now, int cnt, int prev) {
	if (visited[now])
		return;
	visited[now] = true;
	//cout << "now,count - (" << now <<", "<<cnt<<")"<< endl;

	if (now == ed) {
		ans = cnt;
		return;
	}

	if (cv[now] != 0) {
		//cout << "부모일치 확인\n";
		if (cv[now] == ed) {		// 부모 일치 확인
			ans = cnt + 1 < ans ? cnt + 1 : ans;
			//cout << "일치, return" << endl;
			return;
		}
		//cout << "형제탐색" << endl;
		for (int i = 0; i < pv[cv[now]].size(); i++) {	// 형제탐색
			if (pv[cv[now]][i] == ed) {
				ans = cnt + 2 < ans ? cnt + 2 : ans;
				return;
			}
		}
		search(cv[now], cnt + 1, now);
	}
	//cout << "자식탐색" << endl;
	for (int i = 0; i < pv[now].size(); i++) {
		if (pv[now][i] == ed) {
			ans = cnt + 1 < ans ? cnt + 1 : ans;
			return;
		}
		search(pv[now][i], cnt + 1, now);
	}
}

int main() {
	int p, c, n;
	cin >> t >> st >> ed >> n;
	memset(cv, 0, 105);
	for (int i = 0; i < n; i++) {
		cin >> p >> c;
		pv[p].push_back(c);
		cv[c] = p;	// 거꾸로
	}

	if (p == c) ans = 0;
	else search(st, 0, 0);
	if (ans == 1000000) ans = -1;
	cout << ans;

	return 0;
}