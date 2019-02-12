#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 6;
int INF = 1000000;

vector<pair<int, int>> v[7];		// 간선의 정보 (a->b 로 가는 거리)
int d[7];						// 최소비용

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start,0));
	// 가까운 순서대로 처리하기 위한 우선순위 큐
	while (!pq.empty()) {
		int current = pq.top().first;
		// 짧은 것이 먼저 오도록 음수화
		int distance = -pq.top().second;
		pq.pop();
		// 최단 거리가 아닌 경우 스킵
		if (d[current] < distance) continue;
		for (int i = 0; i < v[current].size(); i++) {
			// 선택된 노드들의 인접 노드
			int next = v[current][i].first;
			// 선택된 노드를 인접노드를 통해 가는 비용
			int nextDistance = distance + v[current][i].second;
			// 기존의 최소비용보다 저렴하면 교체
			if (nextDistance < d[current]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
}

int main() {

	for (int i = 1; i <= number; i++)
		d[i] = INF;

	v[1].push_back(make_pair(2, 2));
	v[1].push_back(make_pair(3, 5));
	v[1].push_back(make_pair(4, 1));

	v[2].push_back(make_pair(1, 2));
	v[2].push_back(make_pair(3, 3));
	v[2].push_back(make_pair(4, 2));

	v[3].push_back(make_pair(1, 5));
	v[3].push_back(make_pair(2, 3));
	v[3].push_back(make_pair(4, 3));
	v[3].push_back(make_pair(5, 1));
	v[3].push_back(make_pair(6, 5));

	v[4].push_back(make_pair(1, 1));
	v[4].push_back(make_pair(2, 2));
	v[4].push_back(make_pair(3, 3));
	v[4].push_back(make_pair(5, 1));

	v[5].push_back(make_pair(3, 1));
	v[5].push_back(make_pair(4, 1));
	v[5].push_back(make_pair(6, 2));

	v[6].push_back(make_pair(3, 5));
	v[6].push_back(make_pair(5, 2));
	
	dijkstra(1);

	for (int i = 1; i <= number; i++)
		cout << d[i] << " ";

	return 0;
}