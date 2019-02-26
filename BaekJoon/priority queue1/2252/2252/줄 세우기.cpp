#include <stdio.h>
#include <queue>

using namespace std;

int degree[32001];		// 진입차수 기록
vector<int> v[32001];	// i번째 정점이 향하는 목표점들을 기록

int main() {		// vector를 이용한 위상 정렬 알고리즘
	int n, m;
	int small, tall;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &small, &tall);
		degree[tall]++;				// 진입차수 카운팅
		v[small].push_back(tall);			// small정점이 향한 정점 tall을 추가
	}

	queue<int> now;					// 진입차수가 0인 정점들을 삽입하기위한 큐
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) now.push(i);
	}

	while (!now.empty()) {
		int i = now.front(); now.pop();
		printf("%d ", i);
		for (int j = 0; j < v[i].size(); j++) {	// i 번째 정점이 향하던 점들의 진입차수 업데이트
			if (--degree[v[i][j]] == 0)			// 업데이트 이후에 진입차수가 0이 된다면
				now.push(v[i][j]);				// queue에 push
		}
	}

	return 0;
}