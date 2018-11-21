#include <stdio.h>
#include <stdlib.h>

typedef struct SlideWindow {
	int index;
	int value;
}window;

int main() {
	int N, L;
	window *arr;
	window min;
	int pointer = 0;
	int buffer;
	int front = 0, back = 0;

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
	}

	return 0;
}