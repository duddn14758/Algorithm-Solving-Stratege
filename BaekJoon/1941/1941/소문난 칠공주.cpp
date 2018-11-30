#include <stdio.h>

int makeSeven(int count, int pos, int s, int y);
bool component(int pos);
void PrintMap();
void PrintSeat();

char seat[25];
int visited[5][5];

int main() {
	char buffer[6];
	int number = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%s", buffer);
		for (int j = 0; j < 5; j++) {
			seat[i*5+j] = buffer[j];
		}
	}

	for (int i = 0; i <= 19; i++)
		number += makeSeven(1, i, 0, 0);

	printf("%d\n", number);

	return 0;
}

int makeSeven(int count, int pos, int s,int y) {	
	//printf("%d %d %d %d\n", count, pos, s, y);

	int num = 0;

	if (y > 3) return 0;

	visited[pos/5][pos%5] = 1;
	
	if (seat[pos] == 'Y') y++;
	else s++;

	if (count == 7 && s >= 4) {
		//printf("%d %d %d %d\n", count, pos, s, y);
		PrintMap();		
		return 1;
	}
	for (int i = pos+1; i < 25; i++) {
		if(component(i))
			num+=makeSeven(count + 1, i, s, y);
	}

	visited[pos/5][pos%5] = 0;
	   
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

	if (x > 3 && visited[x + 1][y])
		isNear = true;
	if (x > 0 && visited[x - 1][y])
		isNear = true;

	for (int i = 0; i < pos; i++) {
		int x = i / 5;
		int y = i % 5;
		if(visited[pos-1])
			

	}
	return isNear;
}