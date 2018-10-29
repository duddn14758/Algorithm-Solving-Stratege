#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}


int main() {
	int N, K;
	int *length, *margin, *sumArr;
	int sum = 0;
	int max;
	int pointer=0;
	int count;


	scanf("%d %d", &N, &K);

	length = (int*)malloc(sizeof(int)*N);
	margin = (int*)malloc(sizeof(int)*N);
	sumArr = (int*)malloc(sizeof(int)*N);		// 남은 길이의 랭킹을 매긴다

	for (int i = 0; i < N; i++) {
		scanf("%d", &length[i]);
		sum += length[i];		// 요기 sum은 전체길이합
	}
	// 바로 순차적으로 정렬해보는 방법은??
	qsort(length, N, sizeof(int), compare);

	max = sum / K;

	sum = 0;

	while (sum!=K) {		//요기 sum은 끈 갯수합
		sum = 0;
		for (int i = 0; i < N; i++) {
			sumArr[i] = length[i] / max;
			margin[i] = length[i] % max;	// 현재 sum과 K의 차이 구하기
			pointer = margin[pointer] < margin[i] ? i : pointer;		//차이가 가장 클때 구하기
			sum += sumArr[i];				
		}

		if (sum == K)
			break;		
		
		max = length[pointer] / ++sumArr[pointer];
		pointer = 0;
	}

	printf("%d\n", max);
	   
	return 0;
}