#include <iostream>
#include <vector>

// 로고
using namespace std;

bool visited_row[1005][1005];	// 가로
bool visited_col[1005][1005];	// 세로

vector<int> row[1005];
vector<int> col[1005];

int main() {
	int n;
	cin >> n;
	int lx, ly, rx, ry;
	for (int i = 0; i < n; i++) {
		cin >> lx >> ly >> rx >> ry;
		lx += 500;
		rx += 500;
		ly += 500;
		ry += 500;

		for (int j = lx; j < rx; j++) {
			row[j].push_back(ly);
			row[j].push_back(ry);
		}
		for (int j = ly; j < ry; j++) {
			col[lx].push_back(j);
			col[ly].push_back(j);
		}
	}

	return 0;
}