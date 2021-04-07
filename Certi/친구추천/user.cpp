#include <stdio.h>

#define MAXL	5
#define MAXF	10
#define MAX_USER 10000
#define MAX_ADD 250000

typedef struct Heap {
	int id;
	int num;
}ht;

typedef struct Node {
	int id;
	int prev, next;
}Node;

struct LinkedList {
	int frdNum;
	int head, tail;
}userList[MAX_USER + 1];

ht heap[MAX_USER];
Node nodePool[MAX_ADD];
int nodeCnt;

void init(int N)
{
	nodeCnt = 0;
	for (int i = 1; i <= MAX_USER; i++) {
		userList[i].frdNum = 0;
		userList[i].head = 0;
		userList[i].tail = 0;
	}
}

void add(int id, int F, int ids[MAXF])
{
	for (int i = 0; i < F; i++) {		
		if (userList[id].frdNum == 0) {
			userList[id].head = nodeCnt;
		}
		else {
			nodePool[userList[id].tail].next = nodeCnt;
			nodePool[nodeCnt].prev = userList[id].tail;
		}
		nodePool[nodeCnt].id = ids[i];
		userList[id].tail = nodeCnt;
		userList[id].frdNum++;
		nodeCnt++;

		if (userList[ids[i]].frdNum == 0) {
			userList[ids[i]].head = nodeCnt;
		}
		else {
			nodePool[userList[ids[i]].tail].next = nodeCnt;
			nodePool[nodeCnt].prev = userList[ids[i]].tail;
		}
		nodePool[nodeCnt].id = id;
		userList[ids[i]].tail = nodeCnt;
		userList[ids[i]].frdNum++;
		nodeCnt++;
	}
}

void del(int id1, int id2)
{
	Node* now = &nodePool[userList[id1].head];
	for (int i = 0; i < userList[id1].frdNum; i++) {
		if (now->id == id2) {
			if (userList[id1].frdNum == i - 1) {		// 마지막꺼 지울때는 next의 prev를 건드리지 않는다.
				nodePool[now->prev].next = 0;
				userList[id1].tail = now->prev;
			}
			else {
				nodePool[now->prev].next = now->next;
				nodePool[now->next].prev = now->prev;
			}
			now->id = 0;
			userList[id1].frdNum--;
			break;
		}
		now = &nodePool[now->next];
	}

	now = &nodePool[userList[id2].head];
	for (int i = 0; i < userList[id2].frdNum; i++) {
		if (now->id == id1) {
			if (userList[id2].frdNum == i - 1) {		// 마지막꺼 지울때는 next의 prev를 건드리지 않는다.
				nodePool[now->prev].next = 0;
				userList[id2].tail = now->prev;
			}
			else {
				nodePool[now->prev].next = now->next;
				nodePool[now->next].prev = now->prev;
			}
			now->id = 0;
			userList[id2].frdNum--;
			break;
		}
		now = &nodePool[now->next];
	}
}

bool oper(ht a, ht b) {
	if (a.num > b.num) {
		return true;
	}
	else if (a.num == b.num && a.id < b.id) {
		return true;
	}
	return false;
}

int recommend(int id, int list[MAXL])
{
	int arr[MAX_USER + 1] = { 0, };
	// id 와 친구가 아니여야됨

	Node* now = &nodePool[userList[id].head];	// id의 친구
	for (int i = 0; i < userList[id].frdNum; i++) {
		Node* fnow = &nodePool[userList[now->id].head];		// id의 친구의 친구 head
		for (int j = 0; j < userList[now->id].frdNum; j++) {
			arr[fnow->id]++;
			fnow = &nodePool[fnow->next];
		}
		now = &nodePool[now->next];
	}

	// id 와 친구인 애들 지움
	now = &nodePool[userList[id].head];
	for (int i = 0; i < userList[id].frdNum; i++) {
		arr[now->id] = 0;
		now = &nodePool[now->next];
	}
	// id 지움
	arr[id] = 0;

	// arr heapsort	
	int size = 0;
	int cur;
	for (int i = 1; i <= MAX_USER; i++) {
		if (arr[i] == 0 || i == id) continue;

		heap[size].id = i;
		heap[size].num = arr[i];
		cur = size;
		while (cur > 0 && oper(heap[cur], heap[(cur - 1) / 2])) {
			ht tmp = heap[cur];
			heap[cur] = heap[(cur - 1) / 2];
			heap[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
		size++;
	}

	int idx = 0;
	while (size > 0) {
		if (idx >= 5) break;
		list[idx++] = heap[0].id;
		//printf("num : %d, id : %d\n", heap[0].num, heap[0].id);
		size--;
		heap[0] = heap[size];

		cur = 0;
		while (cur * 2 + 1 < size) {
			int child;
			if (cur * 2 + 2 == size) {
				child = cur * 2 + 1;
			}
			else {
				child = oper(heap[cur * 2 + 1], heap[cur * 2 + 2]) ? cur * 2 + 1 : cur * 2 + 2;
			}

			if (oper(heap[cur], heap[child])) {
				break;
			}

			ht tmp = heap[cur];
			heap[cur] = heap[child];
			heap[child] = tmp;

			cur = child;
		}
	}

	return idx;
}