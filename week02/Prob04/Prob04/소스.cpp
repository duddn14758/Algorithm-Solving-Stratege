#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)    // �������� �� �Լ� ����
{
	int num1 = *(int *)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int *)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
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
	sumArr = (int*)malloc(sizeof(int)*N);		// ���� ������ ��ŷ�� �ű��

	for (int i = 0; i < N; i++) {
		scanf("%d", &length[i]);
		sum += length[i];		// ��� sum�� ��ü������
	}
	// �ٷ� ���������� �����غ��� �����??
	qsort(length, N, sizeof(int), compare);

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