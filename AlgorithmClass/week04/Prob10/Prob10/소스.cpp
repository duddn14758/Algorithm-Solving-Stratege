#include <stdio.h>
#include <stdlib.h>

void PrintArr(int *arr, int size);
void MakeArr(int *arr, int size, int pointer,int value);

int N, K;

int main() {
	int *arr;

	scanf("%d %d", &N, &K);

	arr = (int*)malloc(sizeof(int)*K);	

	MakeArr(arr, K, 0, 0);

	return 0;
}

void PrintArr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void MakeArr(int *arr, int size, int pointer,int value) {
	if (pointer == size) {
		PrintArr(arr, size);
		return;
	}

	for (int i = value+1; i <= N - size + 1 + pointer; i++) {
		arr[pointer] = i;
		MakeArr(arr, size, pointer+1,i);
	}
}