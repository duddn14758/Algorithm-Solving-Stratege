#include <stdio.h>

typedef struct Point {
	int x;
	int y;
}pt;

int makeSeven(int count, int pos, int s, int y);
bool component(int pos);
void PrintMap();
void PrintSeat();

char seat[26];
int visited[6][6];
pt point[7];


int main() {
	char buffer[6];
	int number = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%s", buffer);
		for (int j = 0; j < 5; j++) {
			seat[i*5+j] = buffer[j];
			visited[i][j] = 0;
		}
	}

	for (int i = 0; i <= 19; i++)
		number += makeSeven(1, i, 0, 0);

	printf("%d\n", number);

	return 0;
}

int makeSeven(int count, int pos, int s,int y) {	
	int num = 0;

	point[count - 1].x = pos / 5;
	point[count - 1].y = pos % 5;

	if (y > 3||count>7) return 0;

	visited[pos/5][pos%5] = 1;
	
	//PrintMap();
	
	if (seat[pos] == 'Y') y++;
	else s++;

	if (count == 7 && s >= 4) {
		//PrintMap();		
		visited[pos / 5][pos % 5] = 0;
		return 1;
	}
	for (int i = pos+1; i < 19+count; i++) {
		if (component(i)) 
			num += makeSeven(count + 1, i, s, y);		
	}
	visited[pos / 5][pos % 5] = 0;

	   
	return num;
}

void PrintMap() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", visited[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void PrintSeat() {
	for (int i = 0; i < 25; i++) {
		if (i % 5 == 0)
			printf("\n");
		printf("%c ", seat[i]);
	}
	printf("\n");
}

bool component(int pos) {
	bool isNear = false;
	int x = pos / 5;
	int y = pos % 5;

	if (x < 4 && visited[x + 1][y])
		isNear = true;
	if (x > 0 && visited[x - 1][y])
		isNear = true;
	if (y < 4 && visited[x][y + 1])
		isNear = true;
	if (y > 0 && visited[x][y - 1])
		isNear = true;

	//if (isNear)
		//printf("true position : %d\n", pos);
		
	return isNear;
}

bool check() {
	for (int i = 0; i < 7; i++) {
		if (!component(point[i].x * 5 + point[i].y))
			return false;
	}
}