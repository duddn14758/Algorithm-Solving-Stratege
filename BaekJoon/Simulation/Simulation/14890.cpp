#include <stdio.h>

int map[100][100];
int L, N;

bool inBoundary(int x, int y) {
	if (x > N - 1 || y > N - 1 || x < 0 || y < 0) return 0;
	return 1;
}

bool chkRoad(int dir, int n) {
	int std;
	int upFlag = 1;
	if (dir == 0) {		// down
		std = map[0][n];
		//printf("\n- Start at (%d, %d)\n", 0, n);
		for (int pos = 1; pos < N; pos++) {
			//printf("  - now pos (%d, %d), upcnt : %d\n", pos, n, upFlag);
			if (std == map[pos][n]) {
				upFlag++;
				continue;
			}
			else if (std - 1 == map[pos][n]) {	// ³·À»°æ¿ì
				int Ladder = L;
				std--;
				while (--Ladder > 0) {
					//printf("    - for down pos (%d, %d)\n", pos, n);
					if (!inBoundary(++pos,n) || map[pos][n] != std) {
						return 0;
					}
				}
				//printf("    make ladder\n");
				upFlag = 0;
			}
			else if (std + 1 == map[pos][n]) {
				if (upFlag < L)
					return 0;
				std++;
				upFlag = 1;
				//printf("    make ladder to upstare at (%d,%d)\n",pos,n);
			}
			else
				return 0;
		}
		//printf(" ====== Can go Row Road %d\n", n);
		return 1;
	}
	else {				// right
		std = map[n][0];
		//printf("\n- Start at (%d, %d)\n", n, 0);
		for (int pos = 1; pos < N; pos++) {
			//printf("  - now pos (%d, %d), upcnt : %d\n", n, pos,upFlag);
			if (std == map[n][pos]) {
				upFlag++;
				continue;
			}
			else if (std - 1 == map[n][pos]) {	// ³·À»°æ¿ì
				int Ladder = L;
				std--;
				while (--Ladder > 0) {
					//printf("    - for down pos (%d, %d)\n", n, pos);
					if (!inBoundary(n, ++pos) || map[n][pos] != std) {
						return 0;
					}
				}
				//printf("    make ladder\n");
				upFlag = 0;
			}
			else if (std + 1 == map[n][pos]) {
				if (upFlag < L)
					return 0;
				std++;
				upFlag = 1;
				//printf("    make ladder to upstare at (%d,%d)\n",n,pos);
			}
			else
				return 0;
		}
		//printf(" ====== Can go Col Road %d\n", n);
		return 1;

	}
	return 1;
}

int main() {
	int ans = 0;
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			ans += chkRoad(j, i);
		}
	}
	printf("%d", ans);
	return 0;
}