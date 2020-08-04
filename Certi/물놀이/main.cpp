#pragma warning (disable:4996)
#include <stdio.h>
#define abs(a) (((a) < (0))?-(a):(a))

int dist[1000][1000];
char map[1000][1000];
int N, M;

void init() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist[i][j] = 0;
}

int calc() {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if(map[i][j]=='L')
				ret += dist[i][j];
			//printf("%d ", dist[i][j]);
		}
		//puts("");
	}
	return ret;
}

void setDist(int x, int y) {
	//printf("- set at (%d,%d)\n", x, y);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'W') continue;
			int nDist = abs(x - i) + abs(y - j);
			if (dist[i][j] == 0) dist[i][j] = nDist;
			else dist[i][j] = dist[i][j] < nDist ? dist[i][j] : nDist;
			//printf(" -- %d %d¿¡¼­ dist : %d\n", i,j,dist[i][j]);
		}
	}
}

int main(void)
{
	int test_case;
	int T;
	char buf[1000];
	
	//freopen("input.txt", "r", stdin);
	
	setbuf(stdout, NULL);
	scanf("%d", &T);	

	for (test_case = 1; test_case <= T; ++test_case)
	{
		init();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%s", buf);
			for (int j = 0; j < M; j++) {
				map[i][j] = buf[j];
			}
		}

		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				if (map[i][j] == 'W') 
					setDist(i, j);

		printf("#%d %d\n", test_case, calc());
	}
	return 0;
}