#include <iostream>
#include <vector>
#include <cstring>

// �̼����
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
		//cout << "�θ���ġ Ȯ��\n";
		if (cv[now] == ed) {		// �θ� ��ġ Ȯ��
			ans = cnt + 1 < ans ? cnt + 1 : ans;
			//cout << "��ġ, return" << endl;
			return;
		}
		//cout << "����Ž��" << endl;
		for (int i = 0; i < pv[cv[now]].size(); i++) {	// ����Ž��
			if (pv[cv[now]][i] == ed) {
				ans = cnt + 2 < ans ? cnt + 2 : ans;
				return;
			}
		}
		search(cv[now], cnt + 1, now);
	}
	//cout << "�ڽ�Ž��" << endl;
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
		cv[c] = p;	// �Ųٷ�
	}

	if (p == c) ans = 0;
	else search(st, 0, 0);
	if (ans == 1000000) ans = -1;
	cout << ans;

	return 0;
}