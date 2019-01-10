#include <stdio.h>

void getDP(int count);

int chart[301][22];
int dp[301][21];
int company[301][21][21];	//22 행렬마다 케이스 설정?
int comp[21];
int N, M;

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= M; j++)
			scanf("%d", &chart[i][j]);

	for (int i = 0; i < N; i++)
		getDP(i);

	printf("%d\n", dp[N - 1][M - 1]);
	for (int i = 0; i < M; i++)
		printf("%d ", company[N-1][M-1][i]);

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", company[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}

void getDP(int count) {
	
		for (int i = 1; i <= M; i++) {
			if (i == 1) {
				dp[count][0] = chart[count][1];
				company[count][i - 1][0] = count + 1;
			}
			else {
				if (dp[count][i - 2] <= chart[count][i]) {
					for (int j = 0; j < i-1; j++)
						company[count][i-1][j] = 0;
					company[count][i - 1][i - 1] = count + 1;
				}
				dp[count][i-1] = dp[count][i-2]>chart[count][i]?dp[count][i-2]:chart[count][i];
				for (int j = 0; j < count; j++) {	
					if (dp[count - j - 1][i - 2] + chart[j][i] > dp[count][i - 1]) {
						for (int k = 0; k < i; k++)
							company[count][i - 1][k] = company[j][i - 2][k];
						company[count][i - 1][i - 1] = count - j ;
					}
					dp[count][i - 1] = dp[count - j -1][i - 2] + chart[j][i] > dp[count][i - 1] ? dp[count - j - 1][i - 2] + chart[j][i] : dp[count][i - 1];
				}
			}
		}
}