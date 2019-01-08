#include <stdio.h>

int chart[301][21];
int dp[301];
int invest[21];
int N, M;

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j <= M; j++)
			scanf("%d", &chart[i][j]);

	for (int i = 0; i < N; i++)
		getDP(i);


	return 0;
}

void getDP(int count) {
	if (count == 0)
		for (int i = 1; i <= M; i++)
			dp[count] = dp[count] > chart[count][i] ? dp[count] : chart[count][i];
	else
		for (int i = 0; i < M; i++) {

		}

}