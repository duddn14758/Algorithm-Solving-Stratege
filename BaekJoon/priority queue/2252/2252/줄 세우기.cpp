#include <stdio.h>

void Print(int num);

int stack[32001][2];
int visited[32001];
bool isRoot[32001];

int main() {
	int n, m;
	int small, tall;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &small, &tall);

		if (stack[tall][0] != small) {
			stack[stack[tall][0]][1] = small;
			stack[tall][0] = small;
		}

		if (stack[small][1] != tall) {
			stack[stack[small][1]][0] = tall;
			stack[small][1] = tall;
		}

		stack[small][1] = tall;
		stack[tall][0] = small;
		visited[tall] = false;
		visited[small] = false;
	}

	for (int i = 1; i <= 5; i++) {
		printf("%d ", visited[i]);
	}
	
	for (int i = 1; i <= 32000; i++) {
		if (visited[i]&&stack[i][0] == 0) {
			printf("%d\n", i);
			//Print(i);
		}
	}
	
	return 0;
}

void Print(int num) {
	while (1){
		printf("%d ", num);
		visited[num++] = true;
		if (stack[num][1] != 0)
			return;
	}
}