#include <stdio.h>
#include <stdlib.h>


typedef long long LL;

typedef struct SlideWindow {
	LL value;
	int index;
}window;

int main() {
	int N, L;

	window *arr;
	LL buffer;
	window min;
	int front = 0, back = 0;
	int pointer = 0;


	scanf("%d %d", &N, &L);

	arr = (window*)malloc(sizeof(window)*L);
	for (int i = 0; i < L; i++) {
		arr[i].value = 0;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d", &buffer);
		if (arr[front].value == 0) {
			arr[front].value = buffer;
			arr[front].index = i;
		}
		else {
			

		}
		if (i >= L&&arr[front].index == i - L) {

		}
	
	for (int i = 0; i < N; i++) {
		

	}

	return 0;
}