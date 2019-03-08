#include <iostream>
#define INF 98765432

// 플로이드
using namespace std;

int city[101];
int bus[101][101];
int n, m;

void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i == j || j == k || k == i) continue;
				else if (bus[i][j] > bus[i][k] + bus[k][j]) bus[i][j] = bus[i][k] + bus[k][j];
}

int main() {
	int start, dest, c;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i == j) continue;
			else bus[i][j] = INF;
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> dest >> c;
		bus[start][dest] = c < bus[start][dest] ? c : bus[start][dest];
	}	
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (bus[i][j] == INF) cout << 0 << " ";
			else cout << bus[i][j] << " ";
		cout << endl;
	}

	return 0;
}