#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);
int getDiff(int N, int M, int *Arr);


int main() {
	FILE *fp;
	fp = fopen("input.txt","r");

	int case_num;

	fscanf(fp, "%d", &case_num);

	//scanf("%d", &case_num);

	for (int i = 0; i < case_num; i++) {
		int N, M;
		int *NumArr;
		
		//scanf("%d %d", &N, &M);
		fscanf(fp, "%d %d", &N, &M);
		NumArr = (int*)malloc(sizeof(int)*N);

		for (int i = 0; i < N; i++) {
			//scanf("%d", &NumArr[i]);
			fscanf(fp, "%d", &NumArr[i]);
		}

		qsort(NumArr,N, sizeof(int), compare);
		
		printf("answer is : %d\n", getDiff(N,M, NumArr));

		free(NumArr);
	}

	fclose(fp);

	return 0;
}

int compare(const void *a, const void *b)   
{
	int num1 = *(int *)a;    
	int num2 = *(int *)b;    

	if (num1 < num2)    
		return -1;     

	if (num1 > num2)    
		return 1;       

	return 0;   
}

int getDiff(int N, int M, int *Arr) {
	int answer;
	answer = Arr[M - 1] - Arr[0];

	for (int i = 0; i <=  N - M; i++) {
		if (Arr[i + M - 1] - Arr[i] < answer) {
			answer = Arr[i + M - 1] - Arr[i];
		}
	}

	return answer;
}