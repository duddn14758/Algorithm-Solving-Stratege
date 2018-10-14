#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	int case_num;
	int N, K;
	char *arr;
	int count[26] = { 0, };
	int num_pointer;
	int max_length=0;
	int head = 0, tail = 0;
	clock_t start, end;

	start = clock();

	fscanf(fp, "%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		fscanf(fp, "%d %d", &N, &K);
		printf("%d %d\n",N,K);
		arr = (char*)malloc(sizeof(char)*N);
		
		for (int j = 0; j < 26; j++) {
			count[j] = 0;			
		}

		fgetc(fp);
		
		for (int j = 0; j < N; j++) {
			arr[j] = fgetc(fp);
			num_pointer = arr[j] - 65;

			if (count[num_pointer] < K) {		//count�� K���� ���� �ÿ� head ����				
				count[num_pointer]++;		//count�� ++
			}
			else if (count[num_pointer] >= K) {		//count�� K���� ũ�ų� ���������ÿ�
				while (arr[tail] != arr[j]) {	//�ش� ���ڰ� ���� �� ���� tail�� ������Ų��.
				tail++;
				printf("tail ���� : %d, %c\n", tail,arr[tail]);
				}				
				tail++;			// �ش� ���ڿ� �����ߴٸ� tail�� �ѹ� �� ++
				printf("���������� tail ���� : %d, %c\n", tail, arr[tail]);
			}
			if (max_length < j - tail) {
				printf("j : %d, TAIL : %d\n", j, tail);
				max_length = j - tail;
			}
			//printf("HEAD : %d, TAIL : %d\n", head, tail);
		}		
		//printf("HEAD : %d, TAIL : %d\n", head, tail);
		printf("max length : %d\n",max_length);
		max_length = 0;
		head = 0;
		tail = 0;
		for (int j = 0; j < 26; j++) {
			count[j] = 0;
		}
	}
	end = clock();
	printf("�ɸ� �ð� = %f��", (double)(end - start) / 1000);

	return 0;
}