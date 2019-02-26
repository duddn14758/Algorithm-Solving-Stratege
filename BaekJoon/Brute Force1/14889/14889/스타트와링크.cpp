#include <iostream>
#include <math.h>

void DFS(int t, int cnt);

int pan[21][21];
int team[21];
int team2[21];
int num;
int min=-1;

int main() {
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			std::cin >> pan[i][j];
		}
	}
	DFS(0, 0);

	std::cout << min;

	return 0;
}

void DFS(int t, int cnt) {
	if (t >= num)
		return;
	team[cnt++] = t;
	
	if (cnt == num / 2) {
		int s = 0, l = 0;
		int p1 = 0, p2 = 0;
		for (int i = 0; i < num; i++) {
			if (i == team[p1]) {
				p1++;
			}
			else {
				team2[p2++] = i;
			}
		}

		for (int i = 0; i < num/2; i++) {
			for (int j = 0; j < num / 2; j++) {
				s += pan[team[i]][team[j]];
				l += pan[team2[i]][team2[j]];
			}
		}
		if (min == -1) min = abs(s - l);
		else min = min < abs(s - l) ? min : abs(s - l);
		return;
	}

	for (int i = t+1; i < num; i++) {
		DFS(i, cnt);
	}
}