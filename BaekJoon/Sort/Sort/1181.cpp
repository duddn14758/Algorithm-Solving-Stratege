#include <stdio.h>

int getLength(char *c);
void Push(int p);
int compare(char *a, char*b, int size);

char v[20001][52];
int stack[20001];		//stack���� v�� �������� ����!
int length[20001];
int pointer = 0;

int main() {
	int num;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", v[i]);
		length[i] = getLength(v[i]);
	}

	for (int i = 1; i <= 50; i++) {
		pointer = 0;
		for (int j = 0; j < num; j++) {
			if (length[j] == i) {
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
		state = compare(v[stack[pos]], v[p], length[p]);
		if (state == 1) {
			pos++;
			continue;
		}
		else if (state == -1)
			break;
		else
			return;
	}
	for (int i = pointer; i > pos; i--) {
		stack[i] = stack[i - 1];
	}

	stack[pos] = p;
	pointer++;
}

int compare(char *a, char*b, int size) {		//a�� b���� ������ 1 ����  else -1 ����
	//printf("compare -- %s %s\n", a, b);
	for (int i = 0; i < size; i++) {
		if (a[i] < b[i]) {
			return 1;
		}
		else if (a[i] > b[i]) {
			return -1;
		}
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