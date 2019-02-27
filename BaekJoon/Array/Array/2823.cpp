#include <iostream>

// ю╞.ео.╫х.╬Н.
using namespace std;

bool country[11][11];
bool visited[11][11];
bool Uturn = true;
int r, c;

bool DFS(int x, int y) {
	if (x<0 || y<0 || x>r - 1 || y>c - 1 || country[x][y]) return 1;
	if (visited[x][y]) return 0;
	visited[x][y] = 1;

	if (DFS(x + 1, y) + DFS(x - 1, y) + DFS(x, y - 1) + DFS(x, y + 1) >= 3) Uturn = false;
	return 0;
}

int main() {
	char buf[11];
	int dcount = 0;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		cin >> buf;
		for (int j = 0; j < c; j++) {
			if (buf[j] == 'X') country[i][j] = 1;
			else {
				dcount++;
				country[i][j] = 0;
			}
		}
	}
	if (dcount == 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (!country[i][j]) {
				DFS(i, j);
				cout << !Uturn;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}