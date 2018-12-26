#include <stdio.h>

bool isIn(int n, int count);
void getMax();
void calMax(int cur, int count);
bool isSame(int count);


int first[101];
int second[101];
int stack[101];
int max = 0;
int num;

int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		first[i] = i + 1;
		scanf("%d", &second[i]);
	}

	return 0;
}

void getMax() {
	for (int i = 0; i < num; i++) {
		calMax(i,0);
	}
}

void calMax(int cur,int count) {
	if (cur >= num)
		return;

	stack[count++] = cur+1;
	

	for (int i = cur; i < num; i++) {

	}
}

bool isSame(int count) {
	for (int i = 0; i < count; i++) {
		if (!isIn)
			return false;
	}
	return true;
}

bool isIn(int n,int count) {
	bool f=false;
	bool s=false;
	for (int i = 0; i < count; i++) {
		if (n==second[stack[i]-1]) f = true;
		if (second[n - 1] == stack[i])s = true;
	}
	return f&s;
}