#include <stdio.h>
#include <stdlib.h>

int answer = 0;
int line;
int *r, *g, *b;
int *color[3];

int main() {		
	int pointer = 0;
	int result = 0;

	scanf("%d", &line);
	r = (int*)malloc(sizeof(int)*line);
	g = (int*)malloc(sizeof(int)*line);
	b = (int*)malloc(sizeof(int)*line);
	color[0] = r;
	color[1] = g;
	color[2] = b;

	for (int i = 0; i < line; i++) {
		scanf("%d %d %d", &r[i],&g[i],&b[i]);
		if (pointer % 3 == 0) result += r[i];
		else if (pointer % 3 == 1) result += g[i];
		else result += b[i];
		pointer++;
	}
	answer = result;

	//for (int i = 0; i < 3; i++)
	//	painting(i, line, 0);

	printf("%d %d %d %d\n", r[0], g[0], b[0],result);

	return 0;
}

void painting(int before, int count, int result) {
	int less;
	if (count == line && result < answer) {
		answer = result;
		return;
	}
	else
		painting((before + 1) % 3, count + 1, result + );
	
}