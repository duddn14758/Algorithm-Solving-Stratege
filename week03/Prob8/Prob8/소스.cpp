#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	fp = fopen("input08.txt", "r");
	int case_num;
	int N, K;
	char single='A';
	char *arr;
	int count[26] = { 0, };
	int point[26] = { 0 };
	int max_length = 0;
	int num_pointer;
	bool multi = false;

	fscanf(fp, "%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		fscanf(fp, "%d %d", &N, &K);
		printf("%d %d\n",N,K);
		arr = (char*)malloc(sizeof(char)*N);
		fgetc(fp);
		
		for (int j = 0; j < N; j++) {
			arr[j] = fgetc(fp);
			num_pointer = arr[j] - 65;
			if (count[num_pointer]++ == 0) {
				point[num_pointer] = j;
			}
			if (count[num_pointer] <= K+1&&(j-point[num_pointer])>max_length) {
				max_length = j - point[num_pointer];
				printf("문자열 : %c, 시작 : %d, 마지막 : %d\n", num_pointer, num_pointer, j);
				multi = true;
			}
			if (count[num_pointer] == K + 1) {
				count[num_pointer]--;
				point[num_pointer] = j;
			}
		}
		if (multi == false)
			max_length = N;

		printf("max length : %d\n",max_length);
		multi = false;
		max_length = 0;
		for (int j = 0; j < 26; j++) {
			count[j] = 0;
			point[j] = 0;
		}

	}
	

	return 0;
}