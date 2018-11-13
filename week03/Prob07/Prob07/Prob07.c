#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

typedef struct SlideWindow {
	LL value;
	int index;
}window;

int main() {
	int N, L;
	LL *arr;
	LL buffer;
	window min;
	int front = 0, back = 0;
	int pointer = 0;

	scanf("%d %d", &N, &L);

	arr = (window*)malloc(sizeof(window)*L);
	
	for (int i = 0; i < N; i++) {
		

	}


	return 0;
}