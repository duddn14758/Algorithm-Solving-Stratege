#include <iostream>
#include <queue>

using namespace std;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int n,INF=1000000;
int pan[133][133], dijk[133][133];

struct node {
	int x, y, c;
	bool operator <(node nd)const { return c > nd.c; }
};

int main() {
	cin >> n;
	int p = 1;
	while (n > 0) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> pan[i][j];
				dijk[i][j] = INF;
			}
		priority_queue<node> pq;
		dijk[0][0] = pan[0][0];
		pq.push({ 0,0,pan[0][0] });
		while (!pq.empty()) {
			node now = pq.top();
			pq.pop();
			if (now.c != dijk[now.x][now.y]) continue;
			for (int i = 0; i < 4; i++) {
				int nx = now.x + dx[i];
				int ny = now.y + dy[i];
				if (nx<0 || nx>n - 1 || ny<0 || ny>n - 1) continue;
				if (dijk[nx][ny] > dijk[now.x][now.y] + pan[nx][ny]) {
					dijk[nx][ny] = dijk[now.x][now.y] + pan[nx][ny];
					pq.push({ nx,ny,dijk[nx][ny] });
				}
			}
		}
		cout << "Problem " << p++ << ": " << dijk[n - 1][n - 1] << endl;
		cin >> n;
	}
	return 0;
}