#include <stdio.h>

int A, B, N, M;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int visited[101][101];

void Print() {
	for (int i = 1; i <= A;i++) {
		for (int j = 1; j <= B; j++) {
			printf("%d ", visited[i][j]);
		}
		puts("");
	}
	puts("");
}

class Robot {
private:
	int x, y, dir, Rnum;
	bool checkMsg() {
		if (x<1 || y<1 || x>A || y>B) {
			printf("Robot %d crashes into the wall", Rnum);
			return 1;
		}
		if (visited[x][y]) {
			printf("Robot %d crashes into robot %d", Rnum, visited[x][y]);
			return 1;
		}
		return 0;
	}		

public:
	void turnLeft() {
		dir = (dir + 3) % 4;
	}
	void turnRight() {
		dir = (dir + 1) % 4;
	}
	int Go() {
		visited[x][y] = 0;
		x += dx[dir];
		y += dy[dir];
		if (checkMsg()) return 1;
		visited[x][y] = Rnum;
		//Print();
		return 0;
	}
	void setStart(int Rnum,int x, int y, int dir) {
		this->Rnum = Rnum;
		this->x = x;
		this->y = y;
		this->dir = dir;
		visited[x][y] = Rnum;
	}
};

Robot Rb[101];

int main() {
	scanf("%d %d", &A, &B);
	scanf("%d %d", &N, &M);
	
	int x, y;
	char dir;
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %c", &x, &y, &dir);
		switch (dir) {
		case 'E':
			Rb[i].setStart(i,x, y, 1);
			break;
		case 'W':
			Rb[i].setStart(i,x, y, 3);
			break;
		case 'S':
			Rb[i].setStart(i,x, y, 2);
			break;
		case 'N':
			Rb[i].setStart(i,x, y, 0);
			break;
		}
	}

	int Rnum, re;
	char cmd;
	for (int i = 0; i < M; i++) {
		scanf("%d %c %d", &Rnum, &cmd, &re);
		switch(cmd) {
		case 'L':
			re %= 4;
			for(int i=0;i<re;i++)
				Rb[Rnum].turnLeft();
			break;
		case 'R':
			re %= 4;
			for (int i = 0; i < re; i++)
				Rb[Rnum].turnRight();
			break;
		case 'F':
			for (int i = 0; i < re; i++) {
				if (Rb[Rnum].Go()) return 0;
			}
			break;			
		}		
	}
	printf("OK");

	return 0;
}