#include <iostream>
#include <vector>
#include <algorithm>

// ������ ����
using namespace std;

bool ground[501][501];
vector<pair<int, int>> p;
int num[501][2];	// ����, ����
int n, k;

int main() {
	int s, e,cnt=0;
	pair<int, int> p[2];

	for (int i = 0; i < k; i++) {
		cin >> s >> e;
		ground[s][e] = 1;
		if (ground[s][e]) {
			num[s][0]++;
			num[e][1]++;
			cnt++;
		}
	}

	while (!cnt) {
		p[0].first = 1;
		p[0].second = 0;

		for (int i = 1; i <= n; i++) {
			if (p[0].second > num[i][0]) {
				p[0].second = num[i][0];
				p[0].first = i;
			}
			//l = max(l, num[i][1]);
		}
		
	}

	return 0;
}