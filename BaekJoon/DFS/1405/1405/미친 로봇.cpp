#include <iostream>

using namespace std;

bool visited[35][35];
double arr[4];
int N;
double simple=0;

void DFS(int x, int y, double per,int cnt) {
	if (visited[x][y]) return;
	if (cnt++ == N) {
		simple += per;
		return;
	}
	visited[x][y] = true;

	DFS(x + 1, y, per*arr[0], cnt);
	DFS(x, y - 1, per*arr[1], cnt);
	DFS(x - 1, y, per*arr[2], cnt);
	DFS(x, y + 1, per*arr[3], cnt);
	visited[x][y] = false;
}

int main() {
	cin >> N >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	
	for (int i = 0; i < 4; i++)
		arr[i] *= 0.01;

	DFS(16, 16, 1.00, 0);

	cout << simple;

	return 0;
}