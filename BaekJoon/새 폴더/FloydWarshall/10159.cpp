#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Àú¿ï
using namespace std;

bool edges[101][101];

void floyd(int n) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j || j == k || k == i) continue;
				else if (edges[i][k] && edges[k][j]) edges[i][j] = 1;
				else if (edges[j][k] && edges[k][i]) edges[j][i] = 1;
}

int main() {
	int n, m,light,heavy;
	cin >> n >> m;

	while (m--) {
		cin >> light >> heavy;
		edges[light][heavy] = 1;
	}
	floyd(n);
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (edges[i][j]||edges[j][i]) cnt++;
		}
		cout << n-cnt-1 << endl;
	}
	
	return 0;
}