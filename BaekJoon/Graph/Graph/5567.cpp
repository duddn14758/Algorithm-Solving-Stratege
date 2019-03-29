#include <iostream>
#include <vector>
#include <queue>

// °áÈ¥½Ä
using namespace std;

bool visited[501];
vector<int> f[501];

int main() {
	int n, m, cnt = 0, f1,f2;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> f1 >> f2;
		f[f1].push_back(f2);
		f[f2].push_back(f1);
	}
	queue<pair<int,int>> q;
	q.push({ 1,0 });
	visited[1] = 1;
	while (!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		for(int i=0;i<f[cur.first].size();i++){
			if (!visited[f[cur.first][i]]&&cur.second<2) {
				q.push({ f[cur.first][i],cur.second+1 });
				visited[f[cur.first][i]]=1;
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}