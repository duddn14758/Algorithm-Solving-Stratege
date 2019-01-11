#include <stdio.h>

bool win(int a);

int arr[3] = { 1,3,4 };

int main() {
	int a;
	int player = 0;

	while (1) {

		scanf("%d", &a);

		if (win(a))
			printf("SK");
		else
			printf("CY");
	}
	return 0;
}

bool win(int a) {
	if (a < 0)
		return false;
	if (a -arr[0]==0||a-arr[1]==0||a-arr[2]==0)
		return true;
	for (int i = 0; i < 3; i++) {
		if (win(a - arr[i] - arr[0]) && win(a - arr[i] - arr[1]) && win(a - arr[i] - arr[2]))
			return true;
	}
	return false;
}