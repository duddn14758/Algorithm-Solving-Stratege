#include <stdio.h>
#include <stdlib.h>

bool isIn(int n, int count);
void getMax();
void calMax(int cur, int count);
bool isSame(int count);
void setMax(int count);

int MaxStack[101];
int second[101];
int stack[101];
int max = 0;
int num;

int compare(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &second[i]);
	}

	getMax();

	printf("%d\n", max);
	for (int i = 0; i < max; i++)
		printf("%d\n", MaxStack[i]);	

	return 0;
}

void setMax(int count) {
	for (int i = 0; i < count; i++) {
		MaxStack[i] = stack[i];
	}
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

	if (count>max&&isSame(count)) {
		setMax(count);
		max = count;
	}

	for (int i = cur+1; i < num; i++) {
		calMax(i, count);
	}
}

bool isSame(int count) {
	int copied[101];

	for (int i = 0; i < count; i++) {
		copied[i] = second[stack[i] - 1];
	}
	qsort(copied, count, sizeof(int), compare);

	for (int i = 0; i < count; i++) {
		if (copied[i] != stack[i])
			return false;
	}
	return true;
	/*for (int i = 0; i < count; i++) {
		if (!isIn(stack[i],count))
			return false;
	}
	return true;*/
}

bool isIn(int n,int count) {
	bool f=false;
	bool s=false;
	for (int i = 0; i < count; i++) {		
		if (n == second[stack[i] - 1]) f = true;
		if (second[n - 1] == stack[i]) s = true;
	}

	return f & s;
}