#include <stdio.h>

int main() {
	int v1, v2;
	int min, max;
	int origin;
	int jari = 1;

	scanf("%d %d", &v1, &v2);

	origin = v1 + v2;
	min = origin;
	max = origin;

	while (v1 > 0 || v2 > 0) {
		if (v1 % 10 == 5)
			max += jari;
		if (v2 % 10 == 5)
			max += jari;
		if (v1 % 10 == 6)
			min -= jari;
		if (v2 % 10 == 6)
			min -= jari;
		jari *= 10;
		v1 /= 10;
		v2 /= 10;
	}
	printf("%d %d\n", min, max);

	return 0;
}