#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int dist[502], cost[502];		// dist : 해당 점까지의 비용
vector<pair<int, int>> adj[502];	// 인접점(first)과 비용(second)
bool inQ[502];		// 해당 점이 update 하기위해 큐에 들어있는지 아닌지를 확인하기위함
int cycle[502];		// 해당 점 까지 거친 정점

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, d, c;
		cin >> s >> d >> c;
		adj[s].push_back({ d,c });
	}
	fill(dist, dist + 502, INF);	//dist를 INF로 초기화

	queue<int> q;
	dist[1] = 0;		// 시작점 까지의 비용은 0
	inQ[1] = true;

	q.push(1);
	cycle[1]++;

	while (!q.empty()) {
		int here=q.front();
		q.pop();
		inQ[here] = false;		// here는 현재 큐에 들어있지 않기 때문에 false
		for (int i = 0; i < adj[here].size(); i++) {	// adj의 크기동안
			int nxt = adj[here][i].first;		// here에서 이어지는 다음곳
			int cst = adj[here][i].second;		// 비용
			if (dist[nxt] > dist[here]+cst) {	// 현재까지의 비용+다음비용이 현재 nxt까지에 저장된 비용보다 작다면
				dist[nxt] = dist[here] + cst;
				if (!inQ[nxt]) {		// inQ가 true가 아니라면? -- nxt를 업데이트 하지 않았었다면
					cycle[nxt]++;		// cycle++	-- nxt까지 오는동안 몇개의 경로를 거쳤느냐?
					if (cycle[nxt] >= n) {		// 거쳐온 경로가 n보다 많다면 중복!
						cout << "-1\n";
						return 0;
					}
					q.push(nxt);		// nxt를 업데이트 했음으로 nxt를 거쳐가는 점도 update해주기위해 큐에 push
					inQ[nxt] = true;	// nxt는 업데이트했다! - true
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