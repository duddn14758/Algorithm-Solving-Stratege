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
	for (int i = 0; i < MAX_ADD; i++) {
		userList[i].frdNum = 0;
		userList[i].head = -1;
		userList[i].tail = 0;
	}
}

void add(int id, int F, int ids[MAXF])
{
	for (int i = 0; i < F; i++) {
		nodePool[userList[id].tail].next = nodeCnt;
		nodePool[nodeCnt].id = ids[i];
		nodePool[nodeCnt].prev = userList[id].tail;
		nodeCnt++;

		nodePool[userList[ids[i]].tail].next = nodeCnt;
		nodePool[nodeCnt].id = id;
		nodePool[nodeCnt].prev = userList[ids[i]].tail;
		nodeCnt++;
		userList[ids[i]].frdNum++;
	}
	userList[id].frdNum += F;
}

void del(int id1, int id2)
{
	for (int i = 0; i < userList[id1].frdNum; i++) {
		Node now = nodePool[userList[i].head];
		if (now.id == id2) {
			nodePool[now.prev].next = now.next;
			nodePool[now.next].prev = now.prev;
			now.id = 0;
			break;
		}
		now = nodePool[now.next];
	}

	for (int i = 0; i < userList[id2].frdNum; i++) {
		Node now = nodePool[userList[i].head];
		if (now.id == id1) {
			nodePool[now.prev].next = now.next;
			nodePool[now.next].prev = now.prev;
			now.id = 0;
			break;
		}
		now = nodePool[now.next];
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
	// id 客 模备啊 酒聪咯具凳

	int frdIdx = userList[id].head;
	for (int i = 0; i < userList[id].frdNum; i++) {
		Node now = nodePool[frdIdx];		// id 狼 模备
		for (int j = 0; j < userList[now.id].frdNum; j++) {
			Node fFriend = nodePool[userList[now.id].head];		// id狼 模备狼 模备
			arr[fFriend.id]++;
			fFriend = nodePool[fFriend.next];
		}
		now = nodePool[now.next];
	}

	// id 客 模备牢 局甸 瘤框
	Node now = nodePool[userList[id].head];
	for (int i = 0; i < userList[id].frdNum; i++) {
		arr[now.id] = 0;
		now = nodePool[now.next];
	}
	// id 瘤框
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