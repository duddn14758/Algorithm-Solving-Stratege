#include <iostream>
#include <vector>
#include <cstring>

// ������ ����
using namespace std;

vector<int> graph[501];
bool visited[501];
int routine[501];
int n, k, cnt = 0;

bool dfs(int cur) {
	if (visited[cur]) return 0;
	visited[cur] = 1;
	for (int nxt : graph[cur]) {		// graph�� ũ����� �˾Ƽ� - (auto�� �ѹ� ���ǵ� ������������ ��Ӿ��������)
		if (!routine[nxt] || dfs(routine[nxt])) {	// �ش������� ������ �������� �ʾҰų� dfs�� true�� �����Ҷ�
			routine[nxt] = cur;		// �ش������� ���� �������� ǥ�����ش�
			return true;			// ��ũ�� �ߴٸ� true����
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
		if (dfs(i)) cnt++;		// �ش� ���������� �������� ã�� ��ũ���Ѵ�
	}	
	cout << cnt;
	return 0;
}