#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int dist[502], cost[502];		// dist : �ش� �������� ���
vector<pair<int, int>> adj[502];	// ������(first)�� ���(second)
bool inQ[502];		// �ش� ���� update �ϱ����� ť�� ����ִ��� �ƴ����� Ȯ���ϱ�����
int cycle[502];		// �ش� �� ���� ��ģ ����

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		adj[s].push_back({ d,c });
	}
	fill(dist, dist + 502, INF);	//dist�� INF�� �ʱ�ȭ

	queue<int> q;
	dist[1] = 0;		// ������ ������ ����� 0
	inQ[1] = true;

	q.push(1);
	cycle[1]++;

	while (!q.empty()) {
		int here=q.front();
		q.pop();
		inQ[here] = false;		// here�� ���� ť�� ������� �ʱ� ������ false
		for (int i = 0; i < adj[here].size(); i++) {	// adj�� ũ�⵿��
			int nxt = adj[here][i].first;		// here���� �̾����� ������
			int cst = adj[here][i].second;		// ���
			if (dist[nxt] > dist[here]+cst) {	// ��������� ���+��������� ���� nxt������ ����� ��뺸�� �۴ٸ�
				dist[nxt] = dist[here] + cst;
				if (!inQ[nxt]) {		// inQ�� true�� �ƴ϶��? -- nxt�� ������Ʈ ���� �ʾҾ��ٸ�
					cycle[nxt]++;		// cycle++	-- nxt���� ���µ��� ��� ��θ� ���ƴ���?
					if (cycle[nxt] >= n) {		// ���Ŀ� ��ΰ� n���� ���ٸ� �ߺ�!
						cout << "-1\n";
						return 0;
					}
					q.push(nxt);		// nxt�� ������Ʈ �������� nxt�� ���İ��� ���� update���ֱ����� ť�� push
					inQ[nxt] = true;	// nxt�� ������Ʈ�ߴ�! - true
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		if (dist[i] != INF) cout << dist[i]<<endl;
		else cout << -1 << endl;
	}

	return 0;
}