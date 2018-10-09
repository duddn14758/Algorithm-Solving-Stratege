#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	fp = fopen("input08.txt", "r");
	int case_num;
	int N, K;
	char single;
	char *arr;
	int count[26] = { 0, };
	int length[26] = { 0 };

	fscanf(fp, "%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		fscanf(fp, "%d %d", &N, &K);

		arr = (char*)malloc(sizeof(char)*N);
		
		for (int j = 0; j < N; j++) {
			arr[j] = fgetc(fp);
			printf("%c", arr[j]);
		}
		printf("¶ç¿ì±â\n");
	}
	

	return 0;
}