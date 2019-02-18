#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[1001];
bool visited[1001];

bool BFS(int n) {
	if (visited[n]) return 1;
	visited[n] = 1;
	
	queue <int> q;

}

int main() {
	int n, m, buf1,buf2;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> buf1 >> buf2;
		v[buf1].push_back(buf2);
	}

	
	return 0;
}