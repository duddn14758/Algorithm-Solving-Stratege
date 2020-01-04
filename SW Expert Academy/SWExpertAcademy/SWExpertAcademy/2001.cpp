#include <stdio.h>
#define MAXP 30

int binarr[MAXP+1];
void makeArr() {
	int n = 1;
	for (int i = 0; i <= MAXP; i++) {
		binarr[i] = n;
		n *= 2;
	}
}

int main() {
	int TC, N, M;
	char binary[MAXP + 1];
	makeArr();
	scanf("%d", &TC);
	for (int k = 1; k <= TC; k++) {
		scanf("%d %d", &N, &M);
		int pt = 0;
		bool ONOF = true;
		for (int j = MAXP; j >= 0; j--) {
			if (binarr[j] <= M) {
				binary[pt++] = 1;
				M -= binarr[j];
			}
			else 
				binary[pt++] = 0;
		}
		for (int j = MAXP; j > MAXP - N; j--) {
			if (!binary[j]) {
				ONOF = false;
				break;
			}
		}
		
		if (ONOF) printf("#%d ON\n",k);
		else printf("#%d OFF\n",k);
	}

	return 0;
}