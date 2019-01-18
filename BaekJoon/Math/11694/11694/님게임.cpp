#include <stdio.h>

bool win[102][102];
long long arr[102];

int main() {
	int num;
	long long count;
	int a = 0, b = 0;

		scanf("%d", &num);
		for (int i = 0; i < num; i++) {
			scanf("%lld", &arr[i]);
			/*if (count == 1)
				a++;
			else
				b++;*/
		}

		int result = 0;
		bool flag = false;
		for (int i = 0; i < num; i++) {
			if (arr[i] == 1)flag = true;
			result ^= arr[i];
		}
		if (flag)result--;
		if (result == 0)
			printf("cubelover");
		else
			printf("koosaga");


		/*
		win[1][0] = false;		// 먼저하는사람이 이길때 true
		win[0][1] = true;
		win[2][0] = true;
		win[1][1] = true;
		win[0][2] = false;
		win[1][3] = true;

		for (int i = 0; i <= 100; i++) {		//j=1개 i=2개이상
			for (int j = 0; j <= 100; j++) {
				if (i == 0 && j == 0)
					continue;
				if (i == 0) {
					win[j][i] = j % 2 == 0;
				}
				else if (i == 1) {
					win[j][i] = true;
				}
				else {
					if (j == 0) {
						win[j][i] = !win[j][i - 1] || !win[j + 1][i - 1];
					}					
					else
						win[j][i] = !win[j - 1][i] || !win[j][i - 1] || !win[j + 1][i - 1];
				}
			}
		}

		for (int i = 0; i <= 20; i++) {
			for (int j = 0; j <= 20; j++)
				printf("%d ", win[i][j]);
			printf("\n");
		}

		if (!win[a][b])
			printf("cubelover");
		else
			printf("koosaga");

			*/

	

	return 0;
}