#include <stdio.h>
#include <string.h>

// �迭 ������ 1

int arr[301][301];
int tmp[301][301];
int n, m, r;

// 0, m-1 �����̵�
// 1, m-2
// a, m-a-1
// ~ m/2����
// 0, n-1 �����̵�
// b, n-b-1

void rotate() {
	int a = 0, b = 0;
	for (int a = 0; a < m / 2; a++) {	// �����̵�
		printf("a : %d\n", a);
	}

	for (int b = 0; b < n / 2; b++) {	// �����̵�
		printf("b : %d\n", b);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &r);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	rotate();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", tmp[i][j]);
		}
		printf("\n");
	}
	

	return 0;
}