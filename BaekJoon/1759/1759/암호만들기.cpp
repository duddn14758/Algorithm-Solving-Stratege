#include <stdio.h>
#include <stdlib.h>

void sort(char ch);
void change(int point);
void guessPassword(int point, int count);
void PrintStack();

char *password;
int p_num;
int pointer = 0;
char *stack;

int main() {
	int input;
	char buffer;

	scanf("%d %d", &p_num,&input);

	password = (char*)malloc(sizeof(char)*input);
	stack = (char*)malloc(p_num);

	for (int i = 0; i < input; i++) {
		scanf(" %c", &buffer);
		//password[i] = buffer;
		sort(buffer);
	}
	
	for(int i=0;i<pointer;i++)
		guessPassword(i, 1);


	return 0;
}

void sort(char ch) {
	int i;
	for (i = 0; i < pointer; i++) {
		if (password[i] > ch) {
			change(i);
			break;
		}
	}
	password[i] = ch;
	pointer++;
}

void change(int point) {
	for (int i = point; i < pointer; i++) {
		password[i + 1] = password[i];
	}
}

void guessPassword(int point,int count) {
	stack[count - 1] = password[point];

	if (count == p_num) {
		PrintStack();
	}
	else if (count > p_num) {
		return;
	}
	
	for (int i = point+1; i < pointer; i++) {
		guessPassword(i, count + 1);
	}
}

void PrintStack() {
	for (int i = 0; i < p_num; i++) {
		printf("%c", stack[i]);
	}
	printf("\n");
}