#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 6;
int INF = 1000000;

vector<pair<int, int>> v[7];		// ������ ���� (a->b �� ���� �Ÿ�)
int d[7];						// �ּҺ��

void dijkstra(int start) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start,0));
	// ����� ������� ó���ϱ� ���� �켱���� ť
	while (!pq.empty()) {
		int current = pq.top().first;
		// ª�� ���� ���� ������ ����ȭ
		int distance = -pq.top().second;
		pq.pop();
		// �ִ� �Ÿ��� �ƴ� ��� ��ŵ
		if (d[current] < distance) continue;
		for (int i = 0; i < v[current].size(); i++) {
			// ���õ� ������ ���� ���
			int next = v[current][i].first;
			// ���õ� ��带 ������带 ���� ���� ���
			int nextDistance = distance + v[current][i].second;
			// ������ �ּҺ�뺸�� �����ϸ� ��ü
			if (nextDistance < d[current]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}

}


int main() {

	return 0;
}