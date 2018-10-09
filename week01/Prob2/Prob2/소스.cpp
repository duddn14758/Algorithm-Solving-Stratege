#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	
	int case_num, train_num;
	int d_time, a_time;
	int o_start, o_finish;
	int **arr;
	int max_count = 0;
	int cur_count = 0;

	fscanf(fp, "%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		fscanf(fp, "%d", &train_num);
		o_start = 0;
		o_finish = 0;
		arr = (int**)malloc(sizeof(int*)*train_num*2);
		for (int k = 0; k < train_num; k++) {
			arr[k] = (int*)malloc(sizeof(int) * 2);
		}

		for (int j = 0; j < train_num; j++) {
			fscanf(fp, "%d %d", &d_time, &a_time);
			arr[j][0] = d_time;
			arr[j][1] = a_time;

			printf("%d %d\n", arr[j][0], arr[j][1]);			
		}

		for (int j = 0; j < train_num; j++) {
			for (int k = 0; k < train_num; k++) {
				if (arr[j][0] > arr[k][0] && arr[j][0] < arr[k][1]) {
					cur_count++;
				}
			}
			if (cur_count > max_count)
				max_count = cur_count;
			cur_count = 0;

			for (int k = 0; k < train_num; k++) {
				if (arr[j][1] > arr[k][0] && arr[j][1] < arr[k][1]) {
					cur_count++;
				}
			}
			if (cur_count > max_count)
				max_count = cur_count;
			cur_count = 0;
		}

		printf("maxcount : %d\n", max_count+1);
		max_count = 0;
	}

	return 0;
}
