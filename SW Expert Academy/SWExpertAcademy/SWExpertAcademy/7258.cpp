#include <iostream>
#include <cstdlib>
#include <queue>

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
	pt() {
		this->x = 0;
		this->y = 0;
		this->mem = 0;
		this->dir = 0;
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
	queue <pt> q;
	q.push(p);
	while (!q.empty()) {
		pt cur = q.front();
		//cout << cur.x << ", " << cur.y << endl;
		q.pop();
		//p = controll(p);
		visit[cur.x][cur.y]++;
		char ch = arr[cur.x][cur.y];
		if (ch >= '0'&&ch <= '9') {
			cur.mem = ch - '0';
		}
		else {
			switch (ch) {
			case '<':
				cur.dir = 2;
				break;
			case '^':
				cur.dir = 3;
				break;
			case '>':
				cur.dir = 0;
				break;
			case 'v':
				cur.dir = 1;
				break;
			case '_':
				if (cur.mem == 0) cur.dir = 0;
				else cur.dir = 2;
				break;
			case '|':
				if (cur.mem == 0) cur.dir = 1;
				else cur.dir = 3;
				break;
			case '?':
				for (int i = 0; i < 4; i++) {	// ?일때는 move까지 여기서
					int nx = (cur.x + dx[i] + r) % r;
					int ny = (cur.y + dy[i] + c) % c;
					pt tmp=pt();
					tmp.x = nx;
					tmp.y = ny;
					tmp.mem = cur.mem;
					tmp.dir = i;
					q.push(tmp);
				}
				continue;
				//p.dir = rand() % 4;
				break;
			case '+':
				cur.mem = (cur.mem + 1) % 16;
				break;
			case '-':
				cur.mem = (cur.mem + 15) % 16;
				break;
			case '@':
				return true;
			default:
				break;
			}
		}	// 기능
		cur.x = (cur.x + dx[cur.dir] + r) % r;
		cur.y = (cur.y + dy[cur.dir] + c) % c;
		q.push(cur);
		if (visit[cur.x][cur.y] >= 500) return false;
	}
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
		bool Can = 0;
		for (int j = 0; j < r; j++) {
			cin >> arr[j];
			for(int k=0;k<c;k++)
				if (arr[j][k] == '@') Can = 1;
		}
		cout << "#" << i << " ";
		if(!Can||!simul()) cout << "NO" << endl;
		else cout << "YES" << endl;
		Init();
	}

	return 0;
}