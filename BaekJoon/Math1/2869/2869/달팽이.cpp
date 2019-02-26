#include <stdio.h>

int main() {
	int a, b, v;
	int height = 0;
	int day = 0;

	scanf("%d %d %d", &a, &b, &v);

	height = v - a;
	day = height / (a - b)+1;
	if (height % (a - b) != 0)
		day++;

	printf("%d", day);

	return 0;
}