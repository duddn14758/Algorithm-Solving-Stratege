#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
#define Pii pair<int,int>

// 소수 경로
using namespace std;
bool s[10001];
bool visited[10001];

int bfs(int st, int des) {
	queue<Pii> q;
	q.push({ st,0 });
	visited[st] = 1;

	while (!q.empty()) {
		Pii now = q.front();
		//cout << now.first << endl;
		q.pop();
		if (now.first == des) return now.second;
		int th, hu, ten, one;
		th = now.first % 1000;
		hu = (now.first / 1000)*1000 + now.first % 100;
		ten = (now.first / 100) * 100 + now.first % 10;
		one = (now.first / 10) * 10;
		for (int i = 0; i < 10; i++) {
			if (i>0&&!s[th + i * 1000]&&!visited[th + i * 1000]) {
				q.push({th + i * 1000,now.second+1});
				visited[th + i * 1000] = 1;
			}
			if (!s[hu + i * 100]&&!visited[hu + i * 100]) {
				q.push({ hu + i * 100,now.second + 1 });
				visited[hu + i * 100] = 1;
			}
			if (!s[ten + i * 10]&&!visited[ten+i*10]) {
				q.push({ ten + i * 10,now.second + 1 });
				visited[ten + i * 10] = 1;
			}
			if (!s[one + i]&&!visited[one+i]) {
				q.push({ one + i,now.second + 1 });
				visited[one + i] = 1;
			}
		}
	}
	return -1;
}

int main() {
	int c, st, des,ans;
	
	cin >> c;
	for (int i = 2; i < 10000; i++) {
		for (int j = i*2; j < 10000; j +=i) {
			s[j] = 1;
		}
	}

	for (int i = 0; i < c; i++) {
		cin >> st >> des;
		memset(visited, 0, sizeof(visited));
		ans = bfs(st, des);
		if (ans == -1) cout << "Impossible" << endl;
		else cout << ans << endl;
	}	

	return 0;
}