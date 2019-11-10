#include <iostream>
#include <vector>
#include <queue>
#define pii pair<int,int>
#define abs(a,b) {a-b>0?a-b:b-a}

using namespace std;

typedef struct shark {
	int size;
	int cap;
}Shark;

typedef struct pt {
	int x, y, cnt;
}Pt;

// ũ�Ⱑ �������� �������� ���� ���������� �ִ�.

int dx[] = { -1,0,0,1 };	// ��, ����, ����, �Ʒ� ����
int dy[] = { 0,-1,1,0 };
int visited[21][21];
int N;
int map[21][21];
Shark shk;

void Init() {
	shk.size = 2;	// ��� ũ��
	shk.cap = 0;	// �� ���� ��
}

void eatFunc(int x, int y) {
	map[x][y] = 0;
	shk.cap++;
	if (shk.size == shk.cap) {
		shk.size++;
		shk.cap = 0;
	}
}

bool inBoundary(int x, int y) {
	if (x > N - 1 || y > N - 1 || x < 0 || y < 0) return 0;
	return 1;
}

void Print() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

//issue : ���� �����Ÿ� �����ʰ� �ٸ��� ����.
Pt find(int x,int y,int pt) {	// ����� ���� ã��
	queue<Pt> q;
	queue<Pt> minDist;
	q.push({ x,y,1 });
	visited[x][y] = pt;
	int dist = 400;
	while (!q.empty()) {
		int nowX = q.front().x;
		int nowY = q.front().y;
		int cnt = q.front().cnt;
		if (cnt > dist) break;
		//Print();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];
			if (!inBoundary(nextX, nextY)||visited[nextX][nextY]==pt) continue;
			if (map[nextX][nextY] > 0&&shk.size>map[nextX][nextY]) {	// Ŭ���� ���� �� �ִ�.
				// ���⼭ ť�� �� ����ش�.	-> ���⼭ ���� ���� �Ÿ��� �ִ� ������ Ȯ�� X
				visited[nextX][nextY] = pt;
				dist = cnt;		// �����ϴ� �ִܰŸ� ã��
				minDist.push({ nextX,nextY,cnt});
				// ���� �� �� �ִ� �Ÿ��� �ִ� point���� minDist�� push		
			}
			else if (shk.size>=map[nextX][nextY]) {	// ũ�Ⱑ ���ų� �������� ������ �� �ִ�.
				visited[nextX][nextY] = pt;
				q.push({ nextX,nextY,cnt+1 });
			}
		}
	}
	if (minDist.empty()) return { -1,-1,-1 };

	Pt next = minDist.front();
	minDist.pop();
	//printf("���� �̵��Ÿ��� ��� point : \n");
	//printf("(%d,%d) ", next.x, next.y);
	while (!minDist.empty()) {
		Pt cmp = minDist.front();
		//printf("(%d,%d) ", cmp.x, cmp.y);
		if (next.x > cmp.x) next = minDist.front();
		else if (next.x == cmp.x) {
			if (next.y > cmp.y) next = minDist.front();
		}		
		minDist.pop();
	}
	//printf("\n");
	return next;
}

int run(int x,int y) {
	pii pos = { x,y };
	map[x][y] = 0;
	int cnt = 0;
	Pt nextS;
	while (1) {
		//printf("������ġ : (%d, %d)\n", pos.first, pos.second);
		//printf("�Ʊ��� ũ�� : %d\n������ : %d\n", shk.size, shk.cap);		
		//printf("�̵��Ÿ� : %d\n\n", cnt);
		//Print();
		nextS = find(pos.first, pos.second,cnt+1);
		if (nextS.x == -1) return cnt;
		eatFunc(nextS.x, nextS.y);
		cnt+=nextS.cnt;
		pos = { nextS.x,nextS.y };
	}
	return cnt;
}

int main() {
	int x, y;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				x = i;
				y = j;
			}
		}
	}
	Init();

	cout << run(x, y);

	return 0;
}