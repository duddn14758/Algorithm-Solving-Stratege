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
			q.push({ i,a });		// 큐에 인덱스와 우선순위를 넣는다
			pq.push(a);				// 우선순위를 위한 priority_queue를 사용(자동으로 높은순서로 정렬)
		}
		while (!q.empty()) {
			int nowidx = q.front().first;	// 현재 배열의 인덱스 -> queue<pair<>>의 첫번째 int
			int nowval = q.front().second;	// 현재 배열의 중요도 -> queue<pair<>>의 두번째 int
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
				q.push({ nowidx,nowval });	// 큐는 제일 뒤에 삽입
			}
		}
	}
	return 0;
}