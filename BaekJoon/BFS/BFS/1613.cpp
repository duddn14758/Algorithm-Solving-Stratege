#include <stdio.h>
#include <vector>
#define MAX 402

bool visited[402];
int n, k;
std::vector<int> ft[402];
std::vector<int> ag[402];

template <typename T>
class Queue {
private:
	int queue[MAX];
	int head = 0, tail = 0;
public:
	bool empty() {
		return head == tail;
	}
	void push(T n) {
		queue[tail++] = n;
	}
	int pop() {
		return queue[head++];
	}
	int peek() {
		return queue[head];
	}
};

void init() {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}
}

bool goFuture(int s, int d) {
	Queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int now = q.pop();
		for (int i = 0; i < ft[now].size(); i++) {
			if (ft[now][i] == d) return 1;
			if (!visited[ft[now][i]]) {
				q.push(ft[now][i]);
				visited[ft[now][i]] = 1;
			}
		}
	}
	return 0;
}

bool goPrev(int s, int d) {
	Queue<int> q;
	q.push(s);
	visited[s] = 1;
	while (!q.empty()) {
		int now = q.pop();
		for (int i = 0; i < ag[now].size(); i++) {
			if (ag[now][i] == d) return 1;
			if (!visited[ag[now][i]]) {
				q.push(ag[now][i]);
				visited[ag[now][i]] = 1;
			}
		}
	}
	return 0;
}

int solve(int h1,int h2) {
	if (goFuture(h1, h2)) return -1;
	init();
	if (goPrev(h1, h2)) return 1;
	else return 0;	
}


int main() {
	int f, g, TC;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &f, &g);
		ft[f].push_back(g);
		ag[g].push_back(f);
	}
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%d %d", &f, &g);
		printf("%d\n", solve(f,g));
		init();
	}

	return 0;
}