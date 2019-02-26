#include <stdio.h>
#include <math.h>

void countHeavy(int origin, int n, int pointer);
void counting(int origin,int n);
void Rcounting(int origin, int n);

int visited[102];
int arr[102];
int buffer[50][2];
int c;
int num;
bool v[102] = { 0 };

int main() {
	int count = 0;

	scanf("%d %d", &num, &c);

	for (int i = 0; i < c; i++) {
		scanf("%d %d", &buffer[i][0], &buffer[i][1]);
		countHeavy(buffer[i][0], buffer[i][1], i);
	}

	for (int i = 1; i <= num; i++) {
		//counting(i,i);
		//Rcounting(i, i);
		//printf("%d %d\n", i, arr[i]);
		if (abs(arr[i]) > num/2)
			count++;
	}
	printf("%d\n", count);

	return 0;
}

void counting(int origin, int n) {
	if (v[n])
		return;

	v[n] = true;
	arr[origin]++;
	for (int i = 0; i < c; i++) {
		if (buffer[i][0] == n && !v[buffer[i][1]])
			counting(origin,buffer[i][1]);
	}
	v[n] = false;
}

void Rcounting(int origin, int n) {
	//printf("origin : %d %d\n", origin, n);
	if (v[n])
		return;

	v[n] = true;
	arr[origin]++;
	for (int i = 0; i < c; i++) {
		if (buffer[i][1] == n && !v[buffer[i][0]])
			Rcounting(origin, buffer[i][0]);
	}
	v[n] = false;
}

void countHeavy(int origin, int n, int pointer) {
	//printf("origin : %d, n : %d, pointer : %d\n", origin, n, pointer);

	if (visited[n]==origin)
		return;

	visited[n] = origin;
	arr[n]--;
	arr[origin]++;
	for (int i = 0; i < pointer; i++) {
		if (buffer[i][0] == n&&visited[buffer[i][1]]!=origin) {
			countHeavy(origin, buffer[i][1],i);
		}
	}
}