#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
typedef struct SlideWindow {
	int index;
	int value;
=======
typedef long long LL;

typedef struct SlideWindow {
	LL value;
	int index;
>>>>>>> fadeeddfccdcdb1fd377212e0a8cc7ae7b087f98
}window;

int main() {
	int N, L;
<<<<<<< HEAD
	window *arr;
	window min;
	int pointer = 0;
	int buffer;
	int front = 0, back = 0;
=======
	LL *arr;
	LL buffer;
	window min;
	int front = 0, back = 0;
	int pointer = 0;
>>>>>>> fadeeddfccdcdb1fd377212e0a8cc7ae7b087f98

	scanf("%d %d", &N, &L);

	arr = (window*)malloc(sizeof(window)*L);
<<<<<<< HEAD
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
=======
	
	for (int i = 0; i < N; i++) {
		

>>>>>>> fadeeddfccdcdb1fd377212e0a8cc7ae7b087f98
	}

	return 0;
}