#include <stdio.h>
#define maxNum 10000
#define swap(a,b) TN *tmp=a; a=b; b=tmp;

typedef struct user {	// user 구조체
	int area;
	int uid;
}User;

typedef struct trip {	// trip 구조체
	int area;
	int price;
	int pid;
}Trip;

typedef struct Tnode {	// trip node
	Trip t;
	Tnode* next;
}TN;

typedef struct heaptype {
	Tnode *package[maxNum];	// heap구조로 정렬됨 -> 값 만이 아닌 애초에 노드형식으로 저장한다면 상관X -> 주소가 저장
	int heap_size;
}HeapType;

HeapType ht[11];		// area 갯수만큼

int friend_list[1000][21];	// first seg : num of frd, second~last : frd
TN* hash_chain[100000];	// addr of trip nodes head -> 노드가 저장
Trip reserve_list[1000];

void popHeapByPid(int pid) {


}

void pushHeap(TN *tnode) {		// 최소 heap	-> 그냥 t값이 아닌 node값으로 받는다.
	int area = tnode->t.area;
	int i = ++ht[area].heap_size;	// haep 크기 증가
	//heapify
	while (i != 1 && ht[area].package[i / 2]->t.price > tnode->t.price) {
		ht[area].package[i] = ht[area].package[i / 2];
		i /= 2;
	}
	ht[area].package[i] = tnode;
}

int popHeap(int area) {		// 지역에 의한 popHeap -> pid에 의한 popHeap도 필요
	//printf("%d\n",ht.heap[1]);
	int pid = ht[area].package[1]->t.pid;
	ht[area].package[1] = ht[area].package[ht[area].heap_size];
	ht[area].package[ht[area].heap_size--]->t.pid = 0;

	int parent = 1;
	int child = 2;
	//heapify
	while (child <= ht[area].heap_size) {
		if ((child + 1 <= ht[area].heap_size) && ht[area].package[child]->t.price > ht[area].package[child + 1]->t.price) {
			child++;
		}
		if (ht[area].package[child]->t.price > ht[area].package[parent]->t.price) {
			break;
		}
		swap(ht[area].package[parent], ht[area].package[child]);
		parent = child;
		child *= 2;
	}
	return pid;
}

void init(int N, int M) {
	for (int i = 1; i <= N; i++) {
		friend_list[i][0] = 0;
	}
	for (int i = 0; i < 100000; i++) {
		hash_chain[i] = NULL;
	}
}

void befriend(int uid1, int uid2) {
	friend_list[uid1][++friend_list[uid1][0]] = uid2;
	friend_list[uid2][++friend_list[uid2][0]] = uid1;
}

void add(int pid, int area, int price) {
	int hs = pid % 100000;
	TN* node = new TN();
	node->t.pid = pid;
	node->t.area = area;
	node->t.price = price;
	node->next = hash_chain[hs];
	hash_chain[hs] = node;
	pushHeap(node);		//node 주소 자체를 push
}

void reserve(int uid, int pid) {
	printf("%d의 %d reserve\n", uid, pid);
	//pid 에 해당하는 값 찾기
	int hs = pid % 100000;
	TN* node = hash_chain[hs];
	if (node->t.pid == pid) {
		hash_chain[hs] = node->next;
		//reserve_list[uid]=node->t;
	}
	else {
		while (node->next->t.pid != pid) {
			node = node->next;
		}
		reserve_list[uid] = node->next->t;
		node->next = node->next->next;
	}
	reserve_list[uid] = node->t;

}

int recommend(int uid) {
	// 1. 많이 예약한 지역
	// 2. 그중 가장 저렴한곳
	// 3. 그중 pid가 가장 작은곳
//	printf("recommend\n");
	int numArea[11] = { 0, };
	int maxArea[11];

	printf("%d의 친구 : ", uid);
	for (int i = 1; i <= friend_list[uid][0]; i++) {	// 친구들이 여행간 지역 count
		printf("%d ", friend_list[uid][i]);
		numArea[reserve_list[friend_list[uid][i]].area]++;
	}
	printf("\n");

	int max = 0;
	for (int i = 1; i <= 10; i++) {		// 여행횟수 max 구함
		if (numArea[i] > max) {
			max = numArea[i];
		}
	}

	//printf("여행횟수max:%d\n",max);
	int maxAreaNum = 0;
	for (int i = 1; i <= 10; i++) {		// 여행횟수가 max인 Area들 구함
		//printf("heap size : %d\n",ht[i].heap_size);
		if (numArea[i] == max) {
			maxArea[maxAreaNum++] = i;
			//printf("maxArea : %d\n",maxArea[maxAreaNum-1]);
		}
		//printf("%d Area Cnt : %d\n",i,numArea[i]);
	}
	//printf("max area\n");

	TN *bestPackage;		// bestPackage설정 시 node 자체를 설정
	int i;
	for (i = 0; i < maxAreaNum; i++) {
		if (ht[maxArea[i]].heap_size > 0) {
			printf("기준 trip pid : %d, price : %d\n", ht[maxArea[i]].package[1]->t.pid, ht[maxArea[i]].package[1]->t.price);
			bestPackage = ht[maxArea[i]].package[1];
			break;
		}
	}
	//Trip bestPackage=ht[maxArea[0]].package[1];		// 해당 area의 heap중 1번
	// 가격만 비교해볼까? -- ㄴㄴ 가격이랑 pid도 알아야됨
	for (; i < maxAreaNum; i++) {
		printf("비교 trip pid : %d, price : %d\n", ht[maxArea[i]].package[1]->t.pid, ht[maxArea[i]].package[1]->t.price);
		if (ht[maxArea[i]].heap_size > 0 && ht[maxArea[i]].package[1]->t.price < bestPackage->t.price) {
			bestPackage = ht[maxArea[i]].package[1];
		}
	}
	//printf("pop전까지\n");
	printf("선정된 bestPackage trip pid : %d, price : %d\n", bestPackage->t.pid, bestPackage->t.price);

	return popHeap(bestPackage->t.area);
}
// issue : ht에는 젤위에 price로 들어갈뿐 pid로 찾을때는 찾기가 힘들다.
//(reserve할때 pid로 찾아서 heap에서 제거 및 hashchain에서 삭제해야된다.)
// heapType을 애초에 node로 만들어버리면?