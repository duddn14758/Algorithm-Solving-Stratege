#include <stdio.h>
#include <stdlib.h>

void Init(int N);
void goDFS(int start);
void goBFS(int start);
void Push(int n);
int Pop();

int *arr;
int *queue;
int M,N;
int front = 0, rear = 0;

typedef struct Line {
	int start;
	int end;
};

Line *line;


int main() {
	int start;

	scanf("%d %d %d", &N, &M, &start);
	arr = (int*)malloc(sizeof(int)*N);
	queue = (int*)malloc(sizeof(int)*N);
	line = (Line*)malloc(sizeof(Line)*M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &line[i].start, &line[i].end);
	}

	Init(N);
	goDFS(0);
	printf("\n");
	Init(N);
	goBFS(0);


	return 0;
}

void Init(int N) {
	for (int i = 0; i < N; i++) {
		arr[i] = 0;
	}
}

void goDFS(int start) {
	if (arr[start] == 1)
		return;
	else
		arr[start] = 1;
	printf("%d ", start + 1);
	for (int i = 0; i < M; i++) {
		if (line[i].start == start+1)
			goDFS(line[i].end - 1);
	}
}

void goBFS(int start) {
	Push(start+1);
	arr[start] = 1;

	while (rear > 0) {
		int x = Pop();
		printf("%d ", x);
		for (int i = 0; i < M; i++) {
			if (arr[line[i].end-1] == 0) {
				Push(line[i].end);
				arr[line[i].end-1]=1;
			}
		}
	}

}

void Push(int n) {
	queue[rear++] = n;
}

int Pop() {
	int first = queue[0];
	for (int i = 0; i < rear; i++) {
		queue[i] = queue[i+1];
	}
	rear--;
	return first;
}