#include <iostream>

int pan[51][51];
int min = 0;

void getMin(int x, int y) {
	int w = 0, b = 0;
	int draw = 0;
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2 == 0 && pan[i][j] == 'W') w++;
			if ((i + j) % 2 == 1 && pan[i][j] == 'B') b++;
		}
	}
	draw = w + b;
	draw = draw < 64 - draw ? draw : 64 - draw;
	min = draw < min ? draw : min;	
}


int main() {
	int m, n;
	char buf[51];
	std::cin >> m >> n;
	min = m * n;

	for (int i = 0; i < m; i++) {
		std::cin >> buf;
		for (int j = 0; j < n; j++) {
			pan[i][j] = buf[j];
		}
	}
	
	for (int i = 0; i <= m - 8; i++)
		for (int j = 0; j <= n - 8; j++)
			getMin(i, j);

	std::cout << min << std::endl;

	return 0;
}