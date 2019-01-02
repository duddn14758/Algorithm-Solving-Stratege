#include <stdio.h>

void printCase(int pointer, int count);

int num;
int buffer[7];
int arr[14];


int main() {
	int stop;

	while (1) {
		scanf("%d", &num);
		if (!num)
			break;

		for (int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i <= num-6; i++)
			printCase(i, 0);
		
		printf("\n");
	}


	return 0;
}

void printCase(int pointer, int count) {
	if (pointer > num || count > 5)
		return;
	
	buffer[count] = arr[pointer];	

	if (count == 5) {
		for (int i = 0; i < 6; i++)
			printf("%d ", buffer[i]);
		printf("\n");
	}

	for (int i = pointer+1; i < num; i++) {
		printCase(i, count + 1);
	}
}