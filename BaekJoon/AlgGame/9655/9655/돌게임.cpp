#include <stdio.h>

bool winArr[1001];

int main() {
	int a;

	scanf("%d", &a);

	winArr[1] = 1;
	winArr[2] = 0;
	winArr[3] = 1;
	winArr[4] = 1;

	for (int i = 5; i <= a; i++) {
		if (winArr[i-1]&& winArr[i - 3]&& winArr[i - 4])
			winArr[i] = false;
		else
			winArr[i] = true;
	}

	if (winArr[a])
		printf("SK");
	else
		printf("CY");
	
	return 0;
}