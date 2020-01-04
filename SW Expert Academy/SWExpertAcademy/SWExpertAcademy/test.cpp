#include <stdio.h>

char num[][8] = { "0001101","0011001","0010011","0111101","0100011","0110001","0101111","0111011","0110111","0001011" };

int isCrypt(int arr[]) {
	if (((arr[0] + arr[2] + arr[4] + arr[6]) * 3 + arr[1] + arr[3] + arr[5] + arr[7]) % 10) return 0;
	return arr[0] + arr[1] + arr[2] + arr[3] + arr[4] + arr[5] + arr[6] + arr[7];
}

int chk(char arr[], int pt) {
	int i;
	int Crypto[10];
	for (int k = 7; k >= 0; k--) {
		for (int j = 0; j < 10; j++) {
			for (i = 0; i < 7; i++) {
				if (num[j][6 - i] != arr[pt - i]) break;
			}
			if (i == 7) {
				pt -= i;
				Crypto[k] = j;
				break;
			}
		}
	}
	//for (int j = 0; j < 8; j++)
		//printf("%d", Crypto[j]);
	return isCrypt(Crypto);
}

int main() {
	int tc, r, c, flag = 0;
	char buf[101];
	scanf("%d", &tc);
	for (int k = 1; k <= tc; k++) {
		scanf("%d %d", &r, &c);
		for (int i = 0; i < r; i++) {
			scanf("%s", buf);
			//printf("%d\n", i);
			if (!flag) {
				for (int j = c; j >= 0; j--) {
					if (buf[j] == '1') {
						//printf("%d %d\n", i, j);
						flag = chk(buf, j);
						break;
					}
				}
			}
		}
		printf("#%d %d\n", k, flag);
		flag = 0;
	}

	return 0;
}