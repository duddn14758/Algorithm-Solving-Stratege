#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>

using namespace std;

vector<pair<int, int>> v;

bool visited[105];
int n;
bool answer;

bool get_distance(int x1, int y1, int x2, int y2) {
	int diff = abs(x1 - x2) + abs(y1 - y2);
	return (diff <= 1000) ? true : false;
}

void DFS(int prev) {
	if (prev==n+1) {
		answer = true;
		n = 0;
		return;
	}
	visited[prev] = true;

	for (int i = 1; i <= n+1; i++) {
		//if (!visited[i] && abs(v[i].first - v[prev].first) + abs(v[i].second - v[prev].second) <= 1000)
		if(!visited[i]&&get_distance(v[i].first,v[i].second,v[prev].first,v[prev].second))
			DFS(i);		
	}
}

int main() {
	int c ,n1,n2;
	scanf("%d", &c);
	while (c-- > 0) {
		scanf("%d",&n);
		answer = false;
		v.clear();
		for (int i = 0; i <= n+1; i++) {
			scanf("%d %d", &n1,&n2);
			v.push_back({ n1, n2 });
		}
		memset(visited, 0, sizeof(visited));
		DFS(0);
		if (answer)
			printf("happy\n");
		else
			printf("sad\n");
	}

	return 0;
}