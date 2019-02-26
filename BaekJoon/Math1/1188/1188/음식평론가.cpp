#include <stdio.h>

int main() {
	int n, m;
	int count;
	int tmp;
	int l = 1;
	int origin;

	scanf("%d %d", &n, &m);

	origin = m;

	if (m%n == 0) {
		count = ((m / n) - 1)*n;
	}
	else {
		while (m%n != 0) {
			tmp = n;
			n = m%n;
			m = tmp;
			l *= 2;
			if (n == 1) {
				break;
			}
		}		
		count = origin - n;
	}

	printf("%d\n", count);

	return 0;
}