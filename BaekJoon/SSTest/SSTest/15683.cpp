#include <iostream>
#include <vector>

// 감시
using namespace std;

class cam {
public:
	int x;
	int y;
	int type;
	cam(int x, int y, int type) {
		this->x = x;
		this->y = y;
		this->type = type;
	}
};

int n,m,map[9][9],max_sight=0;
int sight[9][9];
vector<cam> cam_pos;

bool inBoundary(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>m - 1 || map[x][y] == 6) return 0;
	return 1;
}

void sightR(int x, int y, int e) {
	while (inBoundary(x, y)) {
		sight[x][y++] += e;
	}
}

void sightL(int x, int y, int e) {
	while (inBoundary(x, y)) {
		sight[x][y--] += e;
	}
}

void sightB(int x, int y, int e) {
	while (inBoundary(x, y)) {
		sight[x++][y] += e;
	}
}

void sightT(int x, int y, int e) {
	while (inBoundary(x, y)) {
		sight[x--][y] += e;
	}
}

void cam1(int x, int y, int dir,int e) {	//cam1 4방향
	switch (dir) {
	case 0:
		sightR(x, y, e);
		break;
	case 1:
		sightB(x, y, e);
		break;
	case 2:
		sightL(x, y, e);
		break;
	case 3:
		sightT(x, y, e);
		break;
	}
}

void cam2(int x, int y, int dir,int e) {	//cam2 2방향
	int x1 = x, y1 = y;
	switch (dir) {
	case 0:
		sightR(x, y, e);
		sightL(x, y, e);
		break;
	case 1:
		sightB(x, y, e);
		sightT(x, y, e);
		break;
	}
}

void cam3(int x, int y, int dir,int e) {	//cam3 4방향
	switch (dir) {
	case 0:
		sightR(x, y, e);
		sightT(x, y, e);
		break;
	case 1:
		sightT(x, y, e);
		sightL(x, y, e);
		break;
	case 2:
		sightL(x, y, e);
		sightB(x, y, e);
		break;
	case 3:
		sightB(x, y, e);
		sightR(x, y, e);
		break;
	}
}

void cam4(int x, int y, int dir,int e) {	//cam4 4방향
	switch (dir) {
	case 0:
		sightR(x, y, e);
		sightT(x, y, e);
		sightL(x, y, e);
		break;
	case 1:
		sightT(x, y, e);
		sightL(x, y, e);
		sightB(x, y, e);
		break;
	case 2:
		sightL(x, y, e);
		sightB(x, y, e);
		sightR(x, y, e);
		break;
	case 3:
		sightB(x, y, e);
		sightR(x, y, e);
		sightT(x, y, e);
		break;
	}
}

void cam5(int x, int y,int e) {	//cam5
	sightR(x, y, e);
	sightT(x, y, e);
	sightL(x, y, e);
	sightB(x, y, e);
}

void getSight() {
	int num = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (sight[i][j]||map[i][j]==6) num++;
	max_sight = max_sight > num ? max_sight : num;
}

void dfs(int cnum) {
	if (cnum == cam_pos.size()) {
		getSight();
		return;
	}
	cam cur = cam_pos[cnum++];
	switch (cur.type) {
	case 1:
		for (int i = 0; i < 4; i++) {
			cam1(cur.x, cur.y, i, 1);
			dfs(cnum);
			cam1(cur.x, cur.y, i, -1);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			cam2(cur.x, cur.y, i, 1);
			dfs(cnum);
			cam2(cur.x, cur.y, i, -1);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			cam3(cur.x, cur.y, i,1);
			dfs(cnum);
			cam3(cur.x, cur.y, i, -1);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			cam4(cur.x, cur.y, i,1);
			dfs(cnum);
			cam4(cur.x, cur.y, i, -1);
		}
		break;
	case 5:
		cam5(cur.x, cur.y,1);
		dfs(cnum);
		cam5(cur.x, cur.y, -1);
		break;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] < 6 && map[i][j]>0) cam_pos.push_back(cam(i, j, map[i][j]));
			sight[i][j] = 0;
		}
	dfs(0);
	cout << n*m-max_sight;

	return 0;
}