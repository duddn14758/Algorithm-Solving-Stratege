#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[105];
bool visited[105];

int BFS(int frd, int now) {
	queue <int> q;
	int cnt = 0;
	for (int i = 0; i < v[frd].size(); i++) {
		if (visited[v[frd][i]]) continue;
		visited[v[frd][i]] = 1;
		cnt += now+1;
		q.push(v[frd][i]);
	}
	while (!q.empty()) {
		cnt+=BFS(q.front(),now+1);
		q.pop();
	}
	return cnt;
}

void Init(int n) {
	for (int i = 1; i <= n; i++)
		visited[i] = 0;
}

int main() {
	int buf1, buf2,n,m,cnt;
	cin >> n >> m;
	pair <int, int> minper;
	for (int i = 0; i < m; i++) {
		cin >> buf1 >> buf2;
		v[buf1].push_back(buf2);
		v[buf2].push_back(buf1);
	}

	for (int i = 1; i <= n; i++) {
		visited[i] = 1;
		cnt = BFS(i,0);
		if (i==1 || minper.second > cnt) {
			minper.first = i;
			minper.second = cnt;
		}
		//cout << cnt << endl;
		Init(n);
	}
	cout << minper.first;

	return 0;
}