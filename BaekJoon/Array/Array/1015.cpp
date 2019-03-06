#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 수열 정렬
using namespace std;

int arr[51];
vector <pair<int,int>> v;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back({ arr[i],i });
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		arr[v[i].second] = i;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}