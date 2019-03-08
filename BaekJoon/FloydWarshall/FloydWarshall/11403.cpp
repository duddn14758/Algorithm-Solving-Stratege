#include <iostream>

// 경로찾기
using namespace std;

bool edges[101][101];
int n;

void floyd() {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (edges[i][k] && edges[k][j])	edges[i][j] = 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> edges[i][j];
	floyd();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << edges[i][j] << " ";
		cout << "\n";
	}

	return 0;
}