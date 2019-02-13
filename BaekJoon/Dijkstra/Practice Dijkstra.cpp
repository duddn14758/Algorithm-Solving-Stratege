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