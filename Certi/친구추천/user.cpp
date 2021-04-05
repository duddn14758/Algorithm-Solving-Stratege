#include <stdio.h>

#define MAXL	5
#define MAXF	10
#define MAX_USER 10000

typedef struct User {
	int id;
	int friendNum;
	int myFrdList[MAX_USER + 1];
}User;

typedef struct Heap {
	int id;
	int num;
}ht;

User userList[MAX_USER + 1];

void init(int N)
{
	for(int i = 1; i <= MAX_USER; i++) {
		userList[i].id = 0;
		userList[i].friendNum = 0;
	}
}

void add(int id, int F, int ids[MAXF])
{
	for (int i = 0; i < F; i++) {
		//printf("add %d to %d\n", ids[i], id);
		userList[id].myFrdList[userList[id].friendNum++] = ids[i];
		userList[ids[i]].myFrdList[userList[ids[i]].friendNum++] = id;
		//printf("%d frd num : %d, %d frd num : %d\n", id, userList[id].friendNum, ids[i], userList[ids[i]].friendNum);
	}
}

void del(int id1, int id2)
{
	for (int i = 0; i < userList[id1].friendNum; i++) {
		if (userList[id1].myFrdList[i] == id2) {
			userList[id1].myFrdList[i] = 0;
			break;
		}
	}
	for (int i = 0; i < userList[id2].friendNum; i++) {
		if (userList[id2].myFrdList[i] == id1) {
			userList[id2].myFrdList[i] = 0;
			break;
		}
	}
}

bool oper(ht a, ht b) {
	if (a.num < b.num) {
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
	ht heap[MAX_USER + 1];
	for (int i = 0; i < userList[id].friendNum; i++) {
		// 내 친구 리스트에 있는 친구들의 친구 리스트를 arr에 더해준다
		int frd = userList[id].myFrdList[i];
		for (int j = 0; j < userList[frd].friendNum; j++) {
			arr[userList[frd].myFrdList[j]]++;
		}
	}
	// arr heapsort
	
	int size = 0;
	int cur;
	for (int i = 1; i <= MAX_USER; i++) {
		if (arr[i] == 0) continue;

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
		list[idx] = heap[0].id;
		size--;
		heap[0] = heap[size];

		cur = 0;
		while (cur * 2 + 1 < size) {
			int child;
			if (cur * 2 + 2 == size) {
				child = cur * 2 + 1;
			}
			else {
				child = heap[cur * 2 + 1].num < heap[cur * 2 + 2].num ? cur * 2 + 1 : cur * 2 + 1;
			}

			if (heap[cur].num < heap[child].num) {
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