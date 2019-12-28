#include <stdio.h>
#define MAX 1000000001

struct round {
	int topsize, topt;
};

int n, q;
round tower[300001];

int drop() {
	int bottom = n-1;
	int rp;
	bool overflow = false;
	for (int i = 0; i < q; i++) {
		scanf("%d", &rp);
		if (!overflow) {
			while (bottom>=0&&rp > tower[bottom].topsize) {
				bottom = tower[bottom].topt;
			}
			if (bottom < 0) overflow = true;
			bottom--;
		}
	}
	if (overflow) return 0;
	else return bottom+2;
}

int main(){
	int TC;
	scanf("%d", &TC);

	for (int k = 1; k <= TC; k++) {
		scanf("%d %d", &n, &q);
		int width;
		round max = { MAX,0 };
		for (int i = 0; i < n; i++) {
			scanf("%d", &width);
			if (max.topsize >= width) {
				max.topt = i-1;
				max.topsize = width;
			}
			tower[i].topt = max.topt;	// ½ÇÁ¦°ª
			tower[i].topsize = max.topsize;	// pointer
		}		
		printf("#%d %d\n",k,drop());
	}

    return 0;
}