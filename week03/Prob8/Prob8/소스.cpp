#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	int case_num;
	int N, K;
	char single='A';
	char *arr;
	int count[26] = { 0, };
	int **point;
	int max_length = 0;
	int num_pointer;
	bool multi = false;
	int min_start=0;
	clock_t start, end;

	start = clock();

	fscanf(fp, "%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		fscanf(fp, "%d %d", &N, &K);
		printf("%d %d\n",N,K);
		arr = (char*)malloc(sizeof(char)*N);
		point = (int**)malloc(sizeof(int*) * 26);
		for (int j = 0; j < 26; j++) {
			point[j] = (int*)malloc(sizeof(int)*(K+1));
		}
		for (int j = 0; j < 26; j++) {
			count[j] = 0;
			for (int k = 0; k <= K; k++) {
				point[j][k] = 0;
			}
		}

		fgetc(fp);
		
		for (int j = 0; j < N; j++) {
			arr[j] = fgetc(fp);
			num_pointer = arr[j] - 65;
			if (count[num_pointer] < K+1) {		//count가 K+1보다 작을 시에는
				point[num_pointer][count[num_pointer]++] = j;
			}
			if (count[num_pointer] == K + 1) {			//숫자에 도달했을시 배열을 한행씩 밀고 maxcheck
				printf("처음 : %d, 끝 : %d\n", point[num_pointer][0], point[num_pointer][count[num_pointer]-1]);


				for (int k = 0; k < 26; k++) {			// 만약 시작을 했는데 count가 K까지 도달하지 못한 알파벳이있다면 point를 민다
					if (point[k][K] == 0 && point[k][0] < min_start) {
						int r = 0;
						while(point[k][0]<point[num_pointer][0]&&r<K){
							//printf("알파벳 : %c, r : %d, point : %d\n", num_pointer+65,r,point[k][r]);
							point[k][r++] = point[k][r];
						}//해당 알파벳의 첫번째보다 작은동안 계속민다
						point[k][r] = j;
						count[k] -= r;
					}						
				}

				min_start = point[num_pointer][0];

				int result;

				for (int k = 0; k < 26; k++) {
					if (point[num_pointer][0]>point[k][0] && point[num_pointer][K]<point[k][K])
						result = point[k][K] - point[k][0];
					else
						result = j - min_start;
				}
							   
				//printf("%d %d\n", min_start, j);
				max_length = max_length > result ? max_length : result;
				
				for (int k = 0; k < K-1; k++) {	//한칸씩 밀기
					point[num_pointer][k] = point[num_pointer][k + 1];
				}
				point[num_pointer][K - 1] = j;
				count[num_pointer]--;
				multi = true;
			}
		}
		if (multi == false)
			max_length = N;

		printf("max length : %d\n",max_length);
		multi = false;
		max_length = 0;
		for (int j = 0; j < 26; j++) {
			count[j] = 0;
			for (int k = 0; k < K; k++) {
				point[j][k] = 0;
			}
		}

	}
	end = clock();
	printf("걸린 시간 = %f초", (double)(end - start) / 1000);

	return 0;
}