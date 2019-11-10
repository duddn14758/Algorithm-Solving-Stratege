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

// 크기가 같은경우는 먹을수는 없고 지나갈수는 있다.

int dx[] = { -1,0,0,1 };	// 위, 왼쪽, 오른, 아래 순서
int dy[] = { 0,-1,1,0 };
int visited[21][21];
int N;
int map[21][21];
Shark shk;

void Init() {
	shk.size = 2;	// 상어 크기
	shk.cap = 0;	// 상어가 먹은 수
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

//issue : 가장 위엣거를 고르지않고 다른걸 고른다.
Pt find(int x,int y,int pt) {	// 가까운 먹이 찾기
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
			if (map[nextX][nextY] > 0&&shk.size>map[nextX][nextY]) {	// 클때만 먹을 수 있다.
				// 여기서 큐를 다 비워준다.	-> 여기서 비우면 같은 거리에 있는 다음걸 확인 X
				visited[nextX][nextY] = pt;
				dist = cnt;		// 존재하는 최단거리 찾음
				minDist.push({ nextX,nextY,cnt});
				// 답이 될 수 있는 거리에 있는 point들을 minDist에 push		
			}
			else if (shk.size>=map[nextX][nextY]) {	// 크기가 같거나 작을때만 지나갈 수 있다.
				visited[nextX][nextY] = pt;
				q.push({ nextX,nextY,cnt+1 });
			}
		}
	}
	if (minDist.empty()) return { -1,-1,-1 };

	Pt next = minDist.front();
	minDist.pop();
	//printf("동일 이동거리에 담긴 point : \n");
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
		//printf("현재위치 : (%d, %d)\n", pos.first, pos.second);
		//printf("아기상어 크기 : %d\n먹은양 : %d\n", shk.size, shk.cap);		
		//printf("이동거리 : %d\n\n", cnt);
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