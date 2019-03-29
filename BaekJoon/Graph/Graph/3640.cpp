#include <iostream>
#include <vector>
#include <queue>

// Á¦µ¶
using namespace std;
vector<pair<int, int>> graph[1001];
vector<pair<int, int>> graphR[1001];
bool visited[1001];
int v, e,min_total=987654321;

void Rdfs(int cur, int cnt,int num) {
	if (cur == 1) {
		if (num != v) return;
		else {
			min_total = min(min_total, cnt);
		}
		return;
	}
	if (visited[cur]) return;
	visited[cur] = 1;
	
	for (int i = 0; i < graphR[cur].size(); i++) {
		Rdfs(graphR[cur][i].first, cnt + graphR[cur][i].second, num + 1);
	}

	visited[cur] = 0;
}

void dfs(int cur,int cnt,int num) {
	if (visited[cur]) return;
	if(cur!=1) visited[cur] = 1;

	for (int i = 0; i < graph[cur].size(); i++) {
		dfs(graph[cur][i].first, cnt + graph[cur][i].second, num + 1);
	}

	if (cur == v) {
		for (int i = 0; i < graphR[cur].size(); i++) {
			Rdfs(graphR[cur][i].first, cnt + graphR[cur][i].second, num + 1);
		}
	}
	visited[cur] = 0;
}

int main() {
	int s, d, b;

	while (cin>>v>>e) {
		for (int i = 0; i < e; i++) {
			cin >> s >> d >> b;
			graph[s].push_back({ d,b });
			graphR[d].push_back({ s,b });
		}
		dfs(1, 0, 0);
		cout << "ans : "<<min_total << endl;
	}

	return 0;
}