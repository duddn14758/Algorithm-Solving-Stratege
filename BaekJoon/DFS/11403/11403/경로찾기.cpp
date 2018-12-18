#include <stdio.h>

void GoPath(int prev, int cur);
void Print();

int line[101][101];
int num;

int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			scanf("%d", &line[i][j]);
	}
	
	for(int i=0;i<num;i++)
		if(line[0][i])
			GoPath(0, i);

	return 0;
}

void GoPath(int prev, int cur) {
	printf("%d %d\n", prev, cur);
	line[cur][prev] = 1;
	for (int i = 0; i < num; i++) {
		if (i == prev) continue;
		if (line[cur][i])
			GoPath(cur, i);
	}
	Print();
}

void Print() {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			printf("%d ", line[i][j]);
		printf("\n");
	}
}