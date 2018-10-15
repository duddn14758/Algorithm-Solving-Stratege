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
	sumArr = (int*)malloc(sizeof(int)*N);		// ���� ������ ��ŷ�� �ű��

	for (int i = 0; i < N; i++) {
		scanf("%d", &length[i]);
		sum += length[i];		// ��� sum�� ��ü������
	}

	max = sum / K;

	sum = 0;

	while (sum!=K) {		//��� sum�� �� ������
		sum = 0;
		for (int i = 0; i < N; i++) {
			sumArr[i] = length[i] / max;
			margin[i] = length[i] % max;	// ���� sum�� K�� ���� ���ϱ�
			pointer = margin[pointer] < margin[i] ? i : pointer;		//���̰� ���� Ŭ�� ���ϱ�
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