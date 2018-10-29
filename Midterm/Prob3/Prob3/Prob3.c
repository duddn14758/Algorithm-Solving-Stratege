#include <stdio.h>
#include <stdlib.h>

void findLow(int ecm, int price, int reduct);
void calculate(int start);

typedef struct mapping {
	int price;
	int reduct;
}MAP;

MAP **arr;
int *num;
int n, M;
int limit;
int max_reduct = 0;


int main() {
	FILE *fp = fopen("input3.txt", "r");
	int T;

	fscanf(fp, "%d", &T);

	while (T--) {
		fscanf(fp, "%d", &M);
		arr = (MAP**)malloc(sizeof(MAP*)*M);
		num = (int*)malloc(sizeof(int)*M);
		for (int i = 0; i < M; i++) {
			fscanf(fp, "%d", &n);
			arr[i] = (MAP*)malloc(sizeof(MAP)*n);
			num[i] = n;
			for (int j = 0; j < n; j++) {
				fscanf(fp, "%d", &arr[i][j].price);
				fscanf(fp, "%d", &arr[i][j].reduct);
			}
		}
		fscanf(fp, "%d", &limit);
		calculate(0, 0, 0);
		printf("최대 절감량 : %d\n", max_reduct);
	}

	return 0;
}

void calculate(int start, int price, int reduct) {
	for (int i = start; i < M; i++) {
		findLow(i, price, reduct);
	}
}

void findLow(int ecm, int price, int reduct) {
	if (price > limit || ecm >= M)
		return;

	max_reduct = reduct < max_reduct ? max_reduct : reduct;
	for (int i = 0; i < num[ecm]; i++) {
		calculate(ecm + 1, price + arr[ecm][i].price, reduct + arr[ecm][i].reduct);
	}

	return;
}