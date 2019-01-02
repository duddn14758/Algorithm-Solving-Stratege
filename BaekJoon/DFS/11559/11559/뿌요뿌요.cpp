#include <stdio.h>

int MakeBoom();
bool Boom();
void Boomb(char color, int x, int y);
int isNear(char color, int x, int y);
bool isVisited(char color, int x, int y);
void MoveDown();
void Print();
void initVisit();

char pan[13][7];
char buffer[7];
int visited[13][7];

int main() {
	
	for (int i = 0; i < 12; i++) {		
		scanf("%s", &pan[i]);		
	}
	printf("%d",MakeBoom());

	return 0;
}

int MakeBoom() {
	int count = 0;
	
	while(Boom()) {
		while (Boom());
		//printf("Æã\n");
		MoveDown();
		//Print();
		initVisit();
		count++;
	}

	return count;
}

void initVisit() {
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			visited[i][j] = 0;
}

bool Boom() {	
	bool isBoom = false;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (isNear(pan[i][j], i, j)>=4) {
				Boomb(pan[i][j], i, j);
				isBoom = true;
			}
		}
	}
	return isBoom;
}

void Boomb(char color, int x, int y) {
	if (x < 0 || y < 0 || x>11 || y>11 || pan[x][y] == '.')
		return;
	if (pan[x][y] == color) {
		pan[x][y] = '.';
		Boomb(color, x + 1, y);
		Boomb(color, x - 1, y);
		Boomb(color, x, y + 1);
		Boomb(color, x, y - 1);
	}
}

int isNear(char color,int x,int y) {
	if (x<0||y<0||x>11||y>11||isVisited(color,x,y) || pan[x][y] == '.')
		return 0;
	switch (color) {
	case 'R':
		visited[x][y] = 1;
		break;
	case 'G':
		visited[x][y] = 2;
		break;
	case 'B':
		visited[x][y] = 3;
		break;
	case 'P':
		visited[x][y] = 4;
		break;
	case 'Y':
		visited[x][y] = 5;
		break;
	default:
		break;
	}

	if (color == pan[x][y]) 
		return 1 + isNear(pan[x][y], x + 1, y) + isNear(pan[x][y], x - 1, y) + isNear(pan[x][y], x, y + 1) + isNear(pan[x][y], x, y - 1);
	else
		return 0;
}

bool isVisited(char color, int x, int y) {
	if (color == 'R'&&visited[x][y] == 1) return true;
	else if (color == 'G'&&visited[x][y] == 2) return true;
	else if (color == 'B'&&visited[x][y] == 3) return true;
	else if (color == 'P'&&visited[x][y] == 4) return true;
	else if (color == 'Y'&&visited[x][y] == 5) return true;
	else return false;
}

void MoveDown() {
	for (int i = 0; i < 6; i++) {
		int floor = 11;
		for (int j = 11; j >= 0; j--) {
			if (pan[j][i] != '.') {
				if (floor != j) {
					pan[floor][i] = pan[j][i];
					pan[j][i] = '.';
				}
				floor--;
			}
		}
	}
	return;
}

void Print() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++)
			printf("%c", pan[i][j]);
		printf("\n");
	}
}