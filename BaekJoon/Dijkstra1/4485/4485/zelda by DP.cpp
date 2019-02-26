#include <iostream>

int pan[126][126];
int minC[126][126];
int n;

void update(int x, int y, int count) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1||minC[x][y]<count+pan[x][y])
		return;
	minC[x][y] = minC[x][y] < count + pan[x][y] ? minC[x][y] : count + pan[x][y];

	update(x + 1, y, minC[x][y]);
	update(x - 1, y, minC[x][y]);
	update(x, y + 1, minC[x][y]);
	update(x, y - 1, minC[x][y]);
}

bool check(int x, int y) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1)
		return false;
}

void getCourse(int x, int y, int count) {
	if (x<0 || y<0 || x>n - 1 || y>n - 1)
		return;

	if (check(x + 1, y)) minC[x][y] = minC[x][y] < minC[x + 1][y] + pan[x][y] ? minC[x][y] : minC[x + 1][y] + pan[x][y];
	if (check(x - 1, y)) minC[x][y] = minC[x][y] < minC[x - 1][y] + pan[x][y] ? minC[x][y] : minC[x - 1][y] + pan[x][y];
	if (check(x, y + 1)) minC[x][y] = minC[x][y] < minC[x][y + 1] + pan[x][y] ? minC[x][y] : minC[x][y + 1] + pan[x][y];
	if (check(x, y - 1)) minC[x][y] = minC[x][y] < minC[x][y - 1] + pan[x][y] ? minC[x][y] : minC[x][y - 1] + pan[x][y];

	update(x + 1, y, minC[x][y]);
	update(x - 1, y, minC[x][y]);
	update(x, y + 1, minC[x][y]);
	update(x, y - 1, minC[x][y]);
}

int main() {
	std::cin >> n;
	int c = 1;

	while (n != 0) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				std::cin>>pan[i][j];
				minC[i][j] = 200;
			}
		minC[0][0] = pan[0][0];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (i == 0 && j == 0) continue;
				getCourse(i, j, pan[i][j]);
			}

		std::cout << "Problem "<<c++<<": "<<minC[n-1][n-1] << std::endl;

		std::cin >> n;
	}

	return 0;
}