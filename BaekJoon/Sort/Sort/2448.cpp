#include <iostream>
#include <vector>
#include <queue>
#define Pii pair<int,int>

// º°Âï±â - 11
using namespace std;

bool arr[3100][6200];

void makeTri(int x, int y) {
	arr[x][y] = 1;
	arr[x + 1][y - 1] = 1;
	arr[x + 1][y + 1] = 1;
	for (int i = -2; i <= 2; i++)
		arr[x + 2][y + i] = 1;
}

int main() {
	int n, k=1;
	bool t = true;
	cin >> n;
	queue<Pii> q;
	q.push({ 0,n });

	while (!q.empty()) {
		Pii now = q.front();
		q.pop();
		makeTri(now.first, now.second);

		if (now.first >= n) break;
		for (int i = 2; i <= n/3; i *= 2) {
			if (now.first % (3 * i) == 0) {
				q.push({ now.first + 3 * i / 2 , now.second - 3 * i / 2 });
				q.push({ now.first + 3 * i / 2 , now.second + 3 * i / 2 });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n * 2 + 1; j++) {
			if (arr[i][j]) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}

	return 0;
}