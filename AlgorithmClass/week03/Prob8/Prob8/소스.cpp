#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *fp;
	fp = fopen("input08.txt", "r");
	int case_num;
	int N, K;
	char *arr;
	int count[26] = { 0, };
	int num_pointer;
	int max_length=0;
	int head = 0, tail = 0;
	clock_t start, end;
	bool multi = false;

	start = clock();

	fscanf(fp, "%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		fscanf(fp, "%d %d", &N, &K);
		arr = (char*)malloc(sizeof(char)*N);
		
		for (int j = 0; j < 26; j++) {
			count[j] = 0;			
		}

		fgetc(fp);
		
		for (int j = 0; j < N; j++) {
			arr[j] = fgetc(fp);
			num_pointer = arr[j] - 65;

			if (count[num_pointer] < K) {			
				count[num_pointer]++;		//count에 ++
			}
			else if (count[num_pointer] >= K) {		//count가 K보다 크거나 도달했을시에
				multi = true;
				if (max_length < j - tail) {
					max_length = j - tail;
				}
				while (arr[tail] != arr[j]&&tail<j) {	//해당 문자가 나올 때 까지 tail을 증가시킨다.
					count[arr[tail] - 65]--;
					tail++;
				}				
				tail++;			// 해당 문자에 도달했다면 tail을 한번 더 ++
			}
			if (max_length < j - tail) {
				max_length = j - tail;
			}			
		}		

		if (multi == false) {
			max_length = N;
		}
		
		printf("max length : %d\n",max_length);
		max_length = 0;
		head = 0;
		multi = false;
		tail = 0;
		for (int j = 0; j < 26; j++) {
			count[j] = 0;
		}
	}
	end = clock();
	printf("걸린 시간 = %f초", (double)(end - start) / 1000);

	return 0;
}