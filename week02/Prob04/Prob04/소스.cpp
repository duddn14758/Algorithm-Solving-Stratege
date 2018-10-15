#include <stdio.h>
#include <stdlib.h>

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