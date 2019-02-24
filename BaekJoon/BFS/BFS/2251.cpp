#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Data {
	int a;
	int b;
	int c;
};

int bottle[3];
priority_queue <int, vector<int>, greater<int>> pq;
bool chk[202][202], ans[202];

void BFS() {
	queue <Data> q;
	// 1. a->b,  2. a->c,  3. b->c,  4. b->a  5. c->a  6. c->b

	q.push({ 0, 0, bottle[2] });

	while (!q.empty()) {
		Data now = q.front();
		q.pop();
		//cout << now.a << " " << now.b << " " << now.c << endl;
		if (chk[now.a][now.b]) continue;
		chk[now.a][now.b] = true;

		if (now.a == 0 && !ans[now.c]) {
			pq.push(now.c);
			ans[now.c] = true;
		}

		if (now.a + now.b > bottle[1])	//a,b에 든 양이 b의 그릇보다 클때
			q.push({ now.a + now.b - bottle[1],bottle[1],now.c });
		else
			q.push({ 0,now.a + now.b,now.c });

		if (now.a + now.c > bottle[2])	//a,c에 든 양이 c의 그릇보다 클때
			q.push({ now.a + now.c - bottle[2],now.b,bottle[2] });
		else
			q.push({ 0,now.b,now.a + now.c });

		if (now.b + now.c > bottle[2])	//b,c에 든 양이 c의 그릇보다 클때
			q.push({ now.a,now.b + now.c - bottle[2],bottle[2] });
		else
			q.push({ now.a,0,now.b + now.c });


		if (now.a + now.b > bottle[0])	//a,b에 든 양이 a의 그릇보다 클때
			q.push({ bottle[0],now.a + now.b - bottle[0],now.c });
		else
			q.push({ now.a + now.b,0,now.c });

		if (now.a + now.c > bottle[0])	//a,c에 든 양이 a의 그릇보다 클때
			q.push({ bottle[0],now.b,now.a + now.c - bottle[0] });
		else
			q.push({ now.a + now.c,now.b,0 });

		if (now.b + now.c > bottle[1])	//b,c에 든 양이 b의 그릇보다 클때
			q.push({ now.a, bottle[1],now.b + now.c - bottle[1] });
		else
			q.push({ now.a,now.b + now.c,0 });
	}
}

int main() {
	cin >> bottle[0] >> bottle[1] >> bottle[2];
	BFS();

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	return 0;
}