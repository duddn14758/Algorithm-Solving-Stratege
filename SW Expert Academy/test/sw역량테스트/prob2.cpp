#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#define Pii pair<int,int>

using namespace std;

int arr[51][51];
bool visited[51][51];
int n, m;
vector<Pii> v;
vector<int> ans;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool inBoundary(int x, int y) {
	if (x > n - 1 || y > n - 1 || x < 0 || y < 0) return 0;
	return 1;
}

bool isClear() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j] && arr[i][j] == 0) return 0;
	return 1;
}

int bfs1(int a) {
	queue<pair<Pii, int>> q;
	q.push({ v[a],0 });
	visited[v[a].first][v[a].second] = 1;
	if (isClear()) return 0;
	while (!q.empty()) {
		Pii now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		//cout << now.first << now.second << endl;
		for (int i = 0; i < 4; i++) {
			int xx = now.first + dx[i];
			int yy = now.second + dy[i];
			
			if (inBoundary(xx, yy) && !visited[xx][yy] && arr[xx][yy] != 1) {
				q.push({ {xx,yy},cnt + 1 });
				visited[xx][yy] = 1;
				if (isClear()) return cnt + 1;
			}
		}
	}
	return -1;
}

int bfs2(int a, int b) {
	queue<pair<Pii, int>> q;
	q.push({ v[a],0 });
	q.push({ v[b],0 });
	visited[v[a].first][v[a].second] = 1;
	visited[v[b].first][v[b].second] = 1;
	if (isClear()) return 0;
	while (!q.empty()) {
		Pii now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = now.first + dx[i];
			int yy = now.second + dy[i];

			if (inBoundary(xx, yy) && !visited[xx][yy] && arr[xx][yy] != 1) {
				q.push({ {xx,yy},cnt + 1 });
				visited[xx][yy] = 1;
				if (isClear()) return cnt + 1;
			}
		}
	}
	return -1;
}

int bfs3(int a,int b,int c) {
	queue<pair<Pii, int>> q;
	q.push({ v[a],0 });
	q.push({ v[b],0 });
	q.push({ v[c],0 });
	visited[v[a].first][v[a].second] = 1;
	visited[v[b].first][v[b].second] = 1;
	visited[v[c].first][v[c].second] = 1;

	if (isClear()) return 0;
	while (!q.empty()) {
		Pii now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = now.first + dx[i];
			int yy = now.second + dy[i];

			if (inBoundary(xx, yy) && !visited[xx][yy] && arr[xx][yy] != 1) {
				q.push({ {xx,yy},cnt + 1 });
				visited[xx][yy] = 1;
				if (isClear()) return cnt + 1;
			}
		}
	}
	return -1;
}

int bfs(vector<int> a) {
	queue<pair<Pii, int>> q;
	for (int i = 0; i < a.size(); i++) {
		q.push({ v[a[i]],0 });
		visited[v[a[i]].first][v[a[i]].second] = 1;
	}

	if (isClear()) return 0;
	while (!q.empty()) {
		Pii now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = now.first + dx[i];
			int yy = now.second + dy[i];

			if (inBoundary(xx, yy) && !visited[xx][yy] && arr[xx][yy] != 1) {
				q.push({ {xx,yy},cnt + 1 });
				visited[xx][yy] = 1;
				if (isClear()) return cnt + 1;
			}
		}
	}
	return -1;
}

void Init() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;
}

void dfs(vector<int> a, int pt,int cnt) {	
	//if (pt >= v.size()) return;
	if (a.size() != cnt) {
		for (int i = pt; i < v.size(); i++) {
			a.push_back(i);
			dfs(a, i + 1, cnt);
			a.erase(a.begin()+a.size()-1);
		}
	}
	else {				
		ans.push_back(bfs(a));
		Init();
	}
}

int main() {
	int min_num;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == 2) v.push_back({ i,j });
			}
		vector<int> a;
		dfs(a, 0, m);
		sort(ans.begin(), ans.end());
		if (ans[ans.size() - 1] == -1) min_num = -1;
		else {
			for (int i = 0; i < ans.size(); i++) {
				if (ans[i] >= 0) {
					min_num = ans[i];
					break;
				}
			}
		}
		v.clear();
		ans.clear();

		cout << min_num;

	return 0;
}