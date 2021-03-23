#include <stdio.h>
// area별 가장 좋은 package를 선택해놓은 pq(heap)
#define MAX_HASH 100000
#define MAX_ADD 40000
#define MAX_AREA 10
#define MAX_USER 1000

typedef struct userType {
	int friendNum;
	int friendList[20];
	int rsvByMe[11];
	int rsvByFriend[11];
}userType;

typedef struct package {
	bool reserved;
	int area;
	int price;
	long long pid;
	//long long pidAndPrice;
}package;

typedef struct heapType {
	package* heap[MAX_AREA + 1][MAX_ADD + 1];
	int tail[MAX_AREA + 1];
	void push(int area, package* p) {
		int i;
		for (i = 0; i < tail[area]; i++) {
			/*
			if (heap[area][i]->pidAndPrice > p->pidAndPrice) {
				break;
			}
			*/
			if (heap[area][i]->price > p->price ||
				(heap[area][i]->price == p->price && heap[area][i]->pid > p->pid)) {
				break;
			}
		}
		tail[area]++;
		for (int j = tail[area]; j > i; j--) {
			heap[area][j] = heap[area][j - 1];
		}
		//printf("area %d push at %d(%lld)\n", area,i,p->pidAndPrice);
		heap[area][i] = p;
	}
	package* pop(int area) {
		int idx = 0;
		while (idx < tail[area] && heap[area][idx]->reserved == 1) {
			idx++;
		}
		if (idx == tail[area]) {
			return nullptr;
		}
		else {
			return heap[area][idx];
		}
	}

	void init() {
		for (int i = 1; i <= 10; i++) {
			for (int j = 0; j < tail[i]; j++) {
				heap[i][j]->pid = 0;
				heap[i][j]->reserved = 0;
			}
			tail[i] = 0;
		}
	}
}heapType;

typedef struct Heap {
	package *heap[MAX_AREA + 1][MAX_ADD];
	int heapSize[MAX_AREA + 1];

	bool compare(package* a, package* b) {
		if (a->price < b->price || (a->price == b->price && a->pid < b->pid)) {
			return true;
		}
		return false;
	}

	void push(int area, package* p) {
		heap[area][heapSize[area]] = p;
		int cur = heapSize[area];

		while (cur > 0 && compare(heap[area][cur], heap[area][(cur-1)/2])) {
			package *temp = heap[area][(cur - 1) / 2];
			heap[area][(cur - 1) / 2] = heap[area][cur];
			heap[area][cur] = temp;
			cur = (cur - 1) / 2;
		}
		heapSize[area]++;
	}

	package* pop(int area) {
		for (int i = 0; i < heapSize[area]; i++) {
			if (heap[area][i]->reserved == 0) {
				return heap[area][i];
			}
		}
		return nullptr;
	}

	void init() {
		for (int i = 1; i <= MAX_AREA; i++) {
			heapSize[i] = 0;
		}
	}
}Heap;

//heapType ht;
Heap ht;
userType user[MAX_USER + 1];
package hash[MAX_HASH];

void init(int N, int M) {	
	for (int i = 1; i <= MAX_USER; i++) {
		user[i].friendNum = 0;
		for (int j = 1; j < MAX_AREA + 1; j++) {
			user[i].rsvByFriend[j] = 0;
			user[i].rsvByMe[j] = 0;
		}
	}
	ht.init();
	
	for (int i = 0; i < MAX_HASH; i++) {
		//hash[i].pidAndPrice = 0;
		hash[i].pid = 0;
		hash[i].reserved = 0;
	}	
}

void befriend(int uid1, int uid2) {
	//printf("befriend\n");
	// add rsvByMe/Friend
	user[uid1].friendList[user[uid1].friendNum++] = uid2;
	user[uid2].friendList[user[uid2].friendNum++] = uid1;
	for (int i = 1; i <= 10; i++) {
		user[uid1].rsvByFriend[i] += user[uid2].rsvByMe[i];
		user[uid2].rsvByFriend[i] += user[uid1].rsvByMe[i];
	}
}

void add(int pid, int area, int price) {
	//printf("add\n");
	// add시 MAX_HASH로 hash에 더해준다.
	// pidAndPrice가 0인지 체크'
	int idx = pid % MAX_HASH;
	while (hash[idx].pid != 0) {
		idx = (idx + 1) % MAX_HASH;
	}
	hash[idx].area = area;
	hash[idx].pid = pid;
	hash[idx].price = price;
	//hash[idx].pidAndPrice = hash[idx].pid + hash[idx].price<<16;
	ht.push(area, &hash[idx]);
	//printf("area : %d, pid :%d\n", ht.pop(area)->area, ht.pop(area)->pid);
}

void reserve(int uid, int pid) {
	//printf("reserve\n");
	// hash에 rsv check
	// user에 reserve ++

	int idx = pid % MAX_HASH;
	while (hash[idx].pid != pid) {
		idx = (idx + 1) % MAX_HASH;
	}
	package* p = &hash[idx];
	p->reserved = 1;
	user[uid].rsvByMe[p->area]++;
	for (int i = 0; i < user[uid].friendNum; i++) {
		user[user[uid].friendList[i]].rsvByFriend[p->area]++;
	}
}

int recommend(int uid) {
	//printf("recommend\n");
	// 예약 젤 많이 된 heap에서 첫번째거 빼준다(except reserved)
	int maxArea = 0;
	int maxCount = 0;
	package* p = nullptr;
	for (int i = 1; i <= MAX_AREA; i++) {
		package* now = ht.pop(i);
		if (p == nullptr && now != nullptr) {
			p = now;
			maxCount = user[uid].rsvByMe[i] + user[uid].rsvByFriend[i];
		}
		else {
			int nowCount = user[uid].rsvByMe[i] + user[uid].rsvByFriend[i];
			if (maxCount < nowCount) {
				if (now != nullptr) {
					//printf("change %d->%d\n",maxArea,i);
					maxArea = i;
					maxCount = nowCount;
					p = now;
				}
			}
			else if (maxCount == nowCount && now != nullptr) {
				/*
				if (ht.pop(i) != nullptr && p->pidAndPrice > ht.pop(i)->pidAndPrice) {
					maxArea = i;
					p = ht.pop(i);
				}
				*/
				if (p->price > now->price || (p->price == now->price && p->pid > now->pid)) {
					maxArea = i;
					p = now;
				}
			}
		}
	}
	//printf(" - %d\n", p->area);
	return p->pid;
}