#include <stdio.h>

int main() {
	char seat[5][5];
	char buffer[6];

	for (int i = 0; i < 5; i++) {
		scanf("%s", buffer);
		for (int j = 0; j < 5; j++) {
			seat[i][j] = buffer[j];
		}
	}

	return 0;
}