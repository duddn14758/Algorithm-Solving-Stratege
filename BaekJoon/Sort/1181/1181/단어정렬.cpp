#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstdio>

using namespace std;

int getLength(char *c);
void Push(int p);
int compare(char *a, char*b, int size);

char v[20000][50];
int stack[20000];		//stack에는 v의 포지션을 저장!
int length[20000];
int pointer = 0;

queue<int> q;

int main() {
	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {
		scanf("%s", v[i]);
		length[i] = getLength(v[i]);
	}

	for (int i = 1; i < 50; i++) {
		pointer = 0;
		for (int j = 0; j < num; j++) {
			if (length[j] == i) {
				printf("%s\n", v[j]);
				Push(j);
			}
		}
		for (int j = 0; j < pointer; j++)
			printf("%s\n", v[stack[j]]);
	}
	return 0;
}

void Push(int p) {
	int pos = 0;
	int state;
	while (pos < pointer) {
		state = compare(v[stack[pos]], v[stack[p]], length[p]);
		if (state == 1)
			continue;
		else if (state == -1)
			break;
		else
			return;
	}	
	for (int i = pos; i < pointer; i++) {
		stack[i + 1] = stack[i];
	}
	stack[pos] = p;

	pointer++;
}

int compare(char *a, char*b,int size) {		//a가 b보다 작으면 1 리턴  else -1 리턴
	for (int i = 0; i < size; i++) {
		if (a[i] < b[i])
			return 1;
		else if (a[i] > b[i])
			return -1;
		else
			continue;
	}
	return 0;
}

int getLength(char *c) {
	int length = 0;
	while (c[length] >= 'a'&&c[length++] <= 'z');
	return length;
}