#include <stdio.h>
#include <string.h>

// �迭 ������ 1

int arr[301][301];
int tmp[301][301];
int n, m, r;

// 0,0 -> 1,0
// 1,0 -> 2,0
// 0,1 -> 0,0
// 0,2 -> 0,1
// 1,1 -> 2,1
// ���������� �ƴ���? x,y==0 or n-1,m-1
// �ι�°�� x,y==1 n-2,m-2

void rotate() {
	// ���� a��° �� - �����̵�
	for(int a=0;a<1;a++)
	for (int i = a; i < n; i++) {
		if (i == n - a - 1) tmp[i][a + 1] = arr[i][a];
		else tmp[i+1][a] = arr[i][a];
		if (i == a) tmp[i][n - a - 2] = arr[i][n - a - 1];
		else tmp[i-1][n - a - 1] == arr[i][n-a-1];
	}
	// ���� b��° �� - �����̵�
	for(int b=0;b<1;b++)
	for (int i = b; i < m; i++) {
		if (i == m - b - 1) tmp[b-1][i] = arr[b][i];
		else tmp[b][i+1] = arr[b][i];
		if (i == b) tmp[n-b-2][i] = arr[n-b-1][i];
		else tmp[m-b-1][i + 1] == arr[m-b-1][i];
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