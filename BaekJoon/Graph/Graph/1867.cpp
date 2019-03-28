#include <iostream>
#include <vector>
#include <cstring>

// 돌멩이 제거
using namespace std;

vector<int> graph[501];
bool visited[501];
int routine[501];
int n, k, cnt = 0;

bool dfs(int cur) {
	if (visited[cur]) return 0;
	visited[cur] = 1;
	for (int nxt : graph[cur]) {		// graph의 크기까지 알아서 - (auto는 한번 정의된 변수형에대해 계속쓰고싶을때)
		if (!routine[nxt] || dfs(routine[nxt])) {	// 해당정점의 시작이 정해지지 않았거나 dfs가 true를 리턴할때
			routine[nxt] = cur;		// 해당정점에 대한 시작점을 표시해준다
			return true;			// 마크를 했다면 true리턴
		}
	}
	return false;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i)) cnt++;		// 해당 정점에대한 시작점을 찾아 마크를한다
	}	
	cout << cnt;
	return 0;
}