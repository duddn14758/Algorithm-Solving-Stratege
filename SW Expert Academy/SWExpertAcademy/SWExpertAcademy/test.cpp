#include <stdio.h>
#define MAX 100

int cArr[MAX];
int pArr[MAX];
bool visited[MAX];

void init() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = 0;
		cArr[i] = 0;
		pArr[i] = 0;
	}
}

int cDFS(int n) {
	int cnt = 0;
	int org = n;
	while (n) {
		if (visited[n] || !n) break;
		visited[n] = 1;
		n = cArr[n];
		cnt++;
	}
	org = pArr[org];
	while (org) {
		if (visited[org] || !org) break;
		visited[org] = 1;
		org = pArr[org];
		cnt++;
	}
	return cnt;
}

int findParents(int n) {
	while (pArr[n]) {
		n = pArr[n];
	}
	return n;
}

void print(int n) {
	while (cArr[n]) {
		printf("%d %d ", n, cArr[n]);
		n = cArr[n];
	}
}

int main() {
	int tc, n, p, c;
	scanf("%d", &tc);
	for (int k = 1; k <= tc; k++) {
		init();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p, &c);
			pArr[c] = p;
			cArr[p] = c;
		}

		int max = 0;
		int max_p = 0;
		for (int i = 1; i < MAX; i++) {
			if ((cArr[i] || pArr[i]) && !visited[i]) {
				int buf = cDFS(i);
				if (max < buf) {
					max = buf;
					max_p = i;
				}
			}
		}
		printf("#%d ", k);
		print(findParents(max_p));
		puts("");

		// 체인별로 갯수 구함(시작점이 어디든 상관X)
		// 갯수가 맥스인 체인일때 시작점을 구함
		// 시작점으로부터 순서대로 순회
	}

	return 0;
}