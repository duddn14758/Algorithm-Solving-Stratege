#include <iostream>
#include <queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		int n, m, cnt = 0;
		queue<pair<int, int>> q;
		priority_queue <int> pq;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			q.push({ i,a });		// ť�� �ε����� �켱������ �ִ´�
			pq.push(a);				// �켱������ ���� priority_queue�� ���(�ڵ����� ���������� ����)
		}
		while (!q.empty()) {
			int nowidx = q.front().first;	// ���� �迭�� �ε��� -> queue<pair<>>�� ù��° int
			int nowval = q.front().second;	// ���� �迭�� �߿䵵 -> queue<pair<>>�� �ι�° int
			q.pop();
			
			if (pq.top() == nowval) {
				pq.pop();
				cnt++;
				if (nowidx == m) {
					cout << cnt << endl;
					break;
				}
			}
			else {
				q.push({ nowidx,nowval });	// ť�� ���� �ڿ� ����
			}
		}
	}
	return 0;
}