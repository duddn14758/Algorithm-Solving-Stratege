//#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#define pii pair<int,int>

using namespace std;

typedef struct stt {
	int x, y, dir;
};

int N, K, L, X, C;
int map[101][101];
int apple[101][101];
int sec[10001];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool canGo(int x, int y) {
	if (x<0 || y<0 || x>N - 1 || y>N - 1 || map[x][y]) return 0;
	return 1;
}

void print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int run() {
	int second = 1;
	stt now = { 0,0,0 };
	deque<pii> dq;
	dq.push_back({ now.x,now.y });
	map[now.x][now.y] = 1;
	now.x += dx[now.dir];
	now.y += dy[now.dir];
	//map[now.x][now.y] = 1;
	while (canGo(now.x,now.y)) {
		//print();
		map[now.x][now.y] = 1;		// 현재위치 1
		if (apple[now.x][now.y]) apple[now.x][now.y] = 0;
		else if(!apple[now.x][now.y]) {		// 사과를 먹지 않았을 경우
			map[dq.front().first][dq.front().second] = 0;	// 뒤를빼고
			dq.pop_front();
		}
		if (sec[second] == 1) now.dir = (now.dir + 1) % 4;
		else if (sec[second] == 2) now.dir = (now.dir + 3) % 4;
		dq.push_back({ now.x,now.y });
		now.x += dx[now.dir];	// 다음칸으로전진
		now.y += dy[now.dir];
		second++;
		//print();
	}
	return second;
}

int main() {
	cin >> N;
	cin >> K;
	int x, y;
	for (int i = 0; i < K; i++) {
		cin >> x >> y;
		apple[x-1][y-1] = 1;
	}
	cin >> L;
	int X;
	char C;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		if (C == 'D') sec[X] = 1;
		else sec[X] = 2;
	}
	cout << run();

	return 0;
}