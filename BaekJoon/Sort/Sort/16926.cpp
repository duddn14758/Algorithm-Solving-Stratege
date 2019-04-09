#include <stdio.h>
#include <string.h>

// 배열 돌리기 1

int arr[301][301];
int tmp[301][301];
int n, m, r;

// 0, m-1 세로이동
// 1, m-2
// a, m-a-1
// ~ m/2까지
// 0, n-1 가로이동
// b, n-b-1

void rotate() {
	int a = 0, b = 0;
	for (int a = 0; a < m / 2; a++) {	// 세로이동
		printf("a : %d\n", a);
	}

	for (int b = 0; b < n / 2; b++) {	// 가로이동
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