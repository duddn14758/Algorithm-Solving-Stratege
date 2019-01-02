#include <stdio.h>

int MakeBoom();
bool Boom();
int isNear(char color, int x, int y);
bool isVisited(char color, int x, int y);
void MoveDown();
void Print();

char pan[12][6];
char buffer[6];
int visited[12][6];

int main() {
	
	for (int i = 0; i < 12; i++) {		
		scanf("%s", &pan[i]);		
	}

	Print();

	return 0;
}

int MakeBoom() {
	int count = 0;
	
	while (Boom()) {
		MoveDown();
		count++;
	}

	return count;
}

bool Boom() {
	int count = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (isNear(pan[i][j], i, j) >= 3)
				return true;
		}
	}
	return false;
}

int isNear(char color,int x,int y) {
	if (x<0||y<0||x>11||y>11||isVisited(color,x,y) || pan[x][y] == '.')
		return 0;
	switch (color) {
	case 'R':
		visited[x][y] = 0;
		break;
	case 'G':
		visited[x][y] = 1;
		break;
	case 'B':
		visited[x][y] = 2;
		break;
	case 'P':
		visited[x][y] = 3;
		break;
	case 'Y':
		visited[x][y] = 4;
		break;
	default:
		break;
	}
	if (color == pan[x][y])
		return isNear(pan[x][y], x + 1, y) + isNear(pan[x][y], x - 1, y) + isNear(pan[x][y], x, y + 1) + isNear(pan[x][y], x + 1, y - 1);
	else
		return 0;
}

bool isVisited(char color, int x, int y) {
	if (color == 'R'&&visited[x][y] == 0) return true;
	else if (color == 'G'&&visited[x][y] == 1) return true;
	else if (color == 'B'&&visited[x][y] == 2) return true;
	else if (color == 'P'&&visited[x][y] == 3) return true;
	else if (color == 'Y'&&visited[x][y] == 4) return true;
	else return false;
}

void MoveDown() {
	return;
}

void Print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			printf("%c", pan[i][j]);
		printf("\n");
	}
}