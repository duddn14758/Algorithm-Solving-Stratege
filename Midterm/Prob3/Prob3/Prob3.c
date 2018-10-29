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
int n;
int limit;
int max_reduct=0;


int main() {
	FILE *fp = fopen("input3.txt", "r");
	int T, M;			// T:케이스 갯수, M:클래스 갯수

	fscanf(fp, "%d", &T);

	while (T--) {
		fscanf(fp, "%d", &M);
		arr = (MAP**)malloc(sizeof(MAP*)*M);
		num = (int*)malloc(sizeof(int)*M);
		for (int i = 0; i < M; i++) {
			fscanf(fp, "%d", &n);
			arr[i] = (MAP*)malloc(sizeof(MAP)*n);
			num[i] = n;
			printf("size = %d\n", num[i]);
			for (int j = 0; j < n; j++) {
				fscanf(fp, "%d", &arr[i][j].price);
				fscanf(fp, "%d", &arr[i][j].reduct);
				printf("%d %d\n", arr[i][j].price,arr[i][j].reduct);
			}
			printf("\n");
		}
		fscanf(fp, "%d", &limit);
		calculate(0,0,0);
		printf("최대 감소값 : %d\n", max_reduct);
	}

	return 0;
}

void calculate(int start,int price,int reduct) {
	//printf("calculate -- start : %d, price : %d, reduct : %d\n", start, price, reduct);

	for (int i = start; i < n; i++) {
		findLow(i, price, reduct);
	}
}

void findLow(int ecm,int price,int reduct) {
	if (price > limit||ecm>=n)
		return;
	
	printf("ecm : %d, price : %d, reduct : %d\n", ecm, price, reduct);

	max_reduct = reduct < max_reduct ? max_reduct : reduct;
	for (int j = 1; j < n; j++) {
		for (int i = 0; i < num[ecm]; i++) {
			findLow(ecm + j, price + arr[ecm][i].price, reduct + arr[ecm][i].reduct);
		}
	}
	return;
}