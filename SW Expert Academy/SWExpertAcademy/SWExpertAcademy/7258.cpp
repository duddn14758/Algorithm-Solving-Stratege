#include <iostream>
#include <cstdlib>

// 혁진이의 프로그램 검증
using namespace std;
char arr[21][21];
int visit[21][21];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int r, c;

class pt{
public:
	int x;
	int y;
	int mem;
	int dir;		// 0: 오른쪽 1:아래 2:왼쪽 3: 위쪽
	int dur;
	pt() {
		this->x = 0;
		this->y = 0;
		this->mem = 0;
		this->dir = 0;
		this->dur = 0;
	}
};

pt controll(pt p) {
	char ch = arr[p.x][p.y];
	visit[p.x][p.y]++;
	if (ch >= '0'&&ch <= '9') {
		p.mem = ch - '0';
	}
	else {
		switch (ch) {
		case '<':
			p.dir = 2;
			break;
		case '^':
			p.dir = 3;
			break;
		case '>':
			p.dir = 0;
			break;
		case 'v':
			p.dir = 1;
			break;
		case '_':
			if (p.mem == 0) p.dir = 0;
			else p.dir = 2;
			break;
		case '|':
			if (p.mem == 0) p.dir = 1;
			else p.dir = 3;
			break;
		case '?':
			p.dir = rand() % 4;
			break;
		case '+':
			p.mem = (p.mem + 1) % 16;
			break;
		case '-':
			p.mem = (p.mem + 15) % 16;
			break;
		default:
			break;
		}
	}	// 기능
	p.x = (p.x + dx[p.dir] + r) % r;
	p.y = (p.y + dy[p.dir] + c) % c;
	// 이동
	return p;
}

bool simul() {
	pt p= pt();
	while (p.dur++ <= 10000) {
		p = controll(p);
		if (arr[p.x][p.y] == '@') return true;
		if (visit[p.x][p.y] > 5000) return false;
	}
	return false;
}

void Init() {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			visit[i][j] = 0;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cin >> r >> c;
		for (int j = 0; j < r; j++) {
			cin >> arr[j];
		}
		cout << "#" << i << " ";
		if (simul()) cout << "YES" << endl;
		else cout << "NO" << endl;
		Init();
	}

	return 0;
}