#include <stdio.h>
#include <iostream>
#include <queue>

// 적록색약
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

char pan[102][102];
int visited[102][102];
int N;

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
}

void nBFS(int x, int y, char color) {
	queue <pair<int, int>> q;
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < N&&my < N&&visited[mx][my] != 1 && pan[mx][my] == color) {
			q.push({ mx,my });
			visited[mx][my] = 1;
		}
	}
	while (!q.empty()) {
		nBFS(q.front().first, q.front().second, color);
		//if (pan[q.front().first][q.front().second] == 'G')
			//pan[q.front().first][q.front().second] = 'R';
		q.pop();
	}
}

void aBFS(int x, int y, char color) {
	queue <pair<int, int>> q;
	for (int i = 0; i < 4; i++) {
		int mx = x + dx[i];
		int my = y + dy[i];
		if (mx >= 0 && my >= 0 && mx < N&&my < N&&visited[mx][my] != 2 && pan[mx][my] == color) {
			q.push({ mx,my });
			visited[mx][my] = 2;
		}
	}
	while (!q.empty()) {
		aBFS(q.front().first, q.front().second, color);
		q.pop();
	}
}

void getCount() {
	int ncnt = 0, acnt = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (visited[i][j] != 1) {
				nBFS(i, j, pan[i][j]);
				ncnt++;
			}
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (pan[i][j] == 'G') {
				pan[i][j] = 'R';
			}
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (visited[i][j] != 2) {
				aBFS(i, j, pan[i][j]);
				acnt++;
			}
		}
	cout << ncnt << " " << acnt;
}

int main() {
	char buf[102];
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", buf);
		for (int j = 0; j < N; j++)
			pan[i][j] = buf[j];
	}
	getCount();

	return 0;
}