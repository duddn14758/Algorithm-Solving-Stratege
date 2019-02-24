#include <stdio.h>

// µπ∞‘¿”4

int main() {
	int N;
	bool win[1005];

	scanf("%d", &N);

	win[1] = false;
	win[2] = true;
	win[3] = false;
	win[4] = true;
	win[5] = true;

	for (int i = 5; i <= N; i++) {
		if (!win[i - 1] || !win[i - 3] || !win[i - 4]) {
			win[i] = true;
		}
		else
			win[i] = false;
	}

	if (win[N])
		printf("SK");
	else
		printf("CY");

	return 0;
}
