#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>

// 소수 경로
using namespace std;
bool s[10001];
bool visited[10001];

int bfs(int st, int des) {
	queue<int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1000; i < 10000; i++) {
			//if(!s[i])
		}


	}

}

int main() {
	int c, st, des;
	
	cin >> c;
	for (int i = 2; i < 10000; i++) {
		for (int j = i*2; j < 10000; j +=i) {
			s[j] = 1;
		}
	}

	for (int i = 0; i < c; i++) {
		cin >> st >> des;
		memset(visited, 0, sizeof(visited));
		cout << bfs(st, des) << endl;
	}	

	return 0;
}