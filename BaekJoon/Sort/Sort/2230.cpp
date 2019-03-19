#include <vector>
#include <stdio.h>
#include <algorithm>

// 수 고르기
using namespace std;

vector<int> v;

int main() {
	int n, m, buf;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &buf);
		v.push_back(buf);
	}
	sort(v.begin(), v.end());

	int pt1 = 0, pt2 = 1,min_size=98765432;
	
	while (pt1 < v.size()) {
		if (pt2 == v.size()-1) {
			while (v[pt2]-v[pt1]>=m) {
				min_size = min_size < v[pt2] - v[pt1] ? min_size : v[pt2] - v[pt1];
				pt1++;
			}
			break;
		}

		if (v[pt2] - v[pt1] < m) {
			pt2++;
		}
		else if (v[pt2] - v[pt1] > m) {
			min_size = min_size < v[pt2] - v[pt1] ? min_size : v[pt2] - v[pt1];
			pt1++;
		}
		else {
			min_size = m;
			break;
		}
	}
	printf("%d", min_size);

	return 0;
}