#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	int case_count;
	int line_count;
	int **arr;
	int height;
	int max_left=0, max_right=0;
	int sum = 0;

	fscanf(fp, "%d", &case_count);
	
	for (int i = 0; i < case_count; i++) {
		fscanf(fp, "%d", &line_count);

		arr = (int**)malloc(sizeof(int) * 3);

		for (int j = 0; j < 3; j++) {
			arr[j] = (int*)malloc(sizeof(int)*line_count);
		}
		//0: Left, 1: Right, 2:height

		for (int j = 0; j < line_count; j++) {
			fscanf(fp, "%d", &height);
			arr[2][j] = height;
			if (max_left < height) {
				max_left = height;
			}
			arr[0][j] = max_left;
		}
		for (int j = line_count - 1; j >= 0; j--) {
			if (max_right < arr[2][j]) {
				max_right = arr[2][j];
			}
			arr[1][j] = max_right;
		}
		
		for (int j = 0; j < line_count; j++) {
			height = arr[0][j] < arr[1][j] ? arr[0][j] : arr[1][j];
			sum += height - arr[2][j];
		}
		max_left = 0;
		max_right = 0;
		printf("sum = %d\n",sum);
		sum = 0;
	}
	
	return 0;
}