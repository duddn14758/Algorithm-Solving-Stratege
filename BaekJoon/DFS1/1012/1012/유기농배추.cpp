#include <stdio.h>

int getNum();
void dfs(int x, int y);
void Init();

bool visited[52][52];
bool farm[52][52];
int width, height;

int main() {
	int c;
	int x,y,total;
	scanf("%d", &c);

	while (c-- > 0) {
		Init();
		scanf("%d %d %d", &width, &height,&total);

		for (int i = 0; i < total; i++) {
			scanf("%d %d", &x, &y);
			farm[x][y] = 1;
		}
		printf("%d\n", getNum());
	}

	return 0;
}

int getNum() {
	int count = 0;
	for(int i=0;i<width;i++)
		for (int j = 0; j < height; j++) {
			if (!visited[i][j] && farm[i][j]) {
				count++;
				dfs(i, j);
			}
		}
	return count;
}

void dfs(int x, int y) {
	if (x<0 || y<0 || x>width - 1 || y>height || visited[x][y]||!farm[x][y])
		return;
	visited[x][y] = 1;
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

void Init() {
	for(int i=0;i<=50;i++)
		for (int j = 0; j <= 50; j++) {
			visited[i][j] = 0;
			farm[i][j] = 0;
		}
}