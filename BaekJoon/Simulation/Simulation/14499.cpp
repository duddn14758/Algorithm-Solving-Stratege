#include <stdio.h>

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int map[20][20];
int N, M;

class Dice {
public:
	int top = 0, bottom = 0, right = 0, left = 0, front = 0, back = 0;
	int diceRoll(int dir, int x, int y) {
		int tmp = top;
		switch (dir) {
		case 1:			// 悼率
			top = left;
			left = bottom;
			bottom = right;
			right = tmp;
			break;
		case 2:			// 辑率
			top = right;
			right = bottom;
			bottom = left;
			left = tmp;
			break;
		case 3:			// 合率
			top = front;
			front = bottom;
			bottom = back;
			back = tmp;
			break;
		case 4:			// 巢率
			top = back;
			back = bottom;
			bottom = front;
			front = tmp;
			break;
		}
		if (map[x][y] == 0) {
			map[x][y] = bottom;
		}
		else {
			bottom = map[x][y];
			map[x][y] = 0;
		}
		return top;
	}
};

bool inBoundary(int x, int y) {
	if (x > N - 1 || y > M - 1 || x < 0 || y < 0) return 0;
	return 1;
}

int main() {
	int x, y, c, command;
	Dice d;
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &c);
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < c; i++) {
		scanf("%d", &command);
		int nextX = x + dx[command - 1];
		int nextY = y + dy[command - 1];
		if (inBoundary(nextX, nextY)) {
			x = nextX;
			y = nextY;
			printf("%d\n", d.diceRoll(command, x, y));
		}
	}

	return 0;
}