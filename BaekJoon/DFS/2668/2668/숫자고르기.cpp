#include <stdio.h>
#include <stdlib.h>

bool getMax(int start, int cur);

int num;
int node[101];
bool visited[101];
bool cycle[101];
int max = 0;

int main() {
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &node[i]);
	}

	for (int i = 0; i < num; i++) {
		getMax(i, i);
	}

	printf("%d\n", max);
	for (int i = 0; i < num; i++)
		if (cycle[i])
			printf("%d\n", i + 1);
	return 0;
}

bool getMax(int start,int cur) {
	if (visited[cur] == 1)
		return false;

	visited[cur] = true;
		
	if (start == node[cur] - 1) {
		cycle[cur] = true;
		max++;
		return true;
	}
	else {
		cycle[cur] = getMax(start, node[cur] - 1);
		if (cycle[cur]) {
			max++;
		}
		else
			visited[cur] = false;
		return cycle[cur];
	}
}