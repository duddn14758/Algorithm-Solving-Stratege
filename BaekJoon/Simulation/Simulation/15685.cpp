#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 드래곤 커브
using namespace std;

int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };

vector<pair<int, int>> v;
vector<int> s[201];

void simulation(int x, int y, int dir, int dnum) {
	vector<int> dr;
	dr.push_back(dir);
	v.push_back({ x,y });

	for (int i = 0; i < dnum; i++) {
		int size = dr.size();
		for (int j = size - 1; j >= 0; j--) {
			dr.push_back((dr[j] + 1) % 4);
		}
	}
	for (int i = 0; i < dr.size(); i++) {
		x += dx[dr[i]];
		y += dy[dr[i]];
		v.push_back({ x,y });
	}
}

int main() {
	int n, x, y, dir, dnum, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> dir >> dnum;
		simulation(y, x, dir, dnum);	// x,y 를 문제와 반대로 잡았기 때문에 반대로 넣어준다
	}
	sort(v.begin(), v.end());	// 중복제거하기위해 배열 정렬
	v.erase(unique(v.begin(), v.end()), v.end());	//중복제거
	for (int i = 0; i < v.size(); i++)
		s[v[i].first].push_back(v[i].second);

	for (int i = 0; i < v.size(); i++) {
		bool r = 0, l = 0, b = 0;
		for (int j = 0; j < s[v[i].first].size(); j++) {
			if (v[i].second + 1 == s[v[i].first][j]) r = 1;
		}
		for (int j = 0; j < s[v[i].first + 1].size(); j++) {
			if (v[i].second == s[v[i].first + 1][j]) l = 1;
			if (v[i].second + 1 == s[v[i].first + 1][j]) b = 1;
		}
		if (r&l&b)cnt++;
	}
	cout << cnt;

	return 0;
}