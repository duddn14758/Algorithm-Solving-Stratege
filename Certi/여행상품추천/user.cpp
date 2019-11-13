#include <stdio.h>
#define maxNum 10000
#define swap(a,b) TN *tmp=a; a=b; b=tmp;

typedef struct user {	// user ����ü
	int area;
	int uid;
}User;

typedef struct trip {	// trip ����ü
	int area;
	int price;
	int pid;
}Trip;

typedef struct Tnode {	// trip node
	Trip t;
	Tnode* next;
}TN;

typedef struct heaptype {
	Tnode *package[maxNum];	// heap������ ���ĵ� -> �� ���� �ƴ� ���ʿ� ����������� �����Ѵٸ� ���X -> �ּҰ� ����
	int heap_size;
}HeapType;

HeapType ht[11];		// area ������ŭ

int friend_list[1000][21];	// first seg : num of frd, second~last : frd
TN* hash_chain[100000];	// addr of trip nodes head -> ��尡 ����
Trip reserve_list[1000];

void popHeapByPid(int pid) {


}

void pushHeap(TN *tnode) {		// �ּ� heap	-> �׳� t���� �ƴ� node������ �޴´�.
	int area = tnode->t.area;
	int i = ++ht[area].heap_size;	// haep ũ�� ����
	//heapify
	while (i != 1 && ht[area].package[i / 2]->t.price > tnode->t.price) {
		ht[area].package[i] = ht[area].package[i / 2];
		i /= 2;
	}
	ht[area].package[i] = tnode;
}

int popHeap(int area) {		// ������ ���� popHeap -> pid�� ���� popHeap�� �ʿ�
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
	pushHeap(node);		//node �ּ� ��ü�� push
}

void reserve(int uid, int pid) {
	printf("%d�� %d reserve\n", uid, pid);
	//pid �� �ش��ϴ� �� ã��
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
	// 1. ���� ������ ����
	// 2. ���� ���� �����Ѱ�
	// 3. ���� pid�� ���� ������
//	printf("recommend\n");
	int numArea[11] = { 0, };
	int maxArea[11];

	printf("%d�� ģ�� : ", uid);
	for (int i = 1; i <= friend_list[uid][0]; i++) {	// ģ������ ���ణ ���� count
		printf("%d ", friend_list[uid][i]);
		numArea[reserve_list[friend_list[uid][i]].area]++;
	}
	printf("\n");

	int max = 0;
	for (int i = 1; i <= 10; i++) {		// ����Ƚ�� max ����
		if (numArea[i] > max) {
			max = numArea[i];
		}
	}

	//printf("����Ƚ��max:%d\n",max);
	int maxAreaNum = 0;
	for (int i = 1; i <= 10; i++) {		// ����Ƚ���� max�� Area�� ����
		//printf("heap size : %d\n",ht[i].heap_size);
		if (numArea[i] == max) {
			maxArea[maxAreaNum++] = i;
			//printf("maxArea : %d\n",maxArea[maxAreaNum-1]);
		}
		//printf("%d Area Cnt : %d\n",i,numArea[i]);
	}
	//printf("max area\n");

	TN *bestPackage;		// bestPackage���� �� node ��ü�� ����
	int i;
	for (i = 0; i < maxAreaNum; i++) {
		if (ht[maxArea[i]].heap_size > 0) {
			printf("���� trip pid : %d, price : %d\n", ht[maxArea[i]].package[1]->t.pid, ht[maxArea[i]].package[1]->t.price);
			bestPackage = ht[maxArea[i]].package[1];
			break;
		}
	}
	//Trip bestPackage=ht[maxArea[0]].package[1];		// �ش� area�� heap�� 1��
	// ���ݸ� ���غ���? -- ���� �����̶� pid�� �˾ƾߵ�
	for (; i < maxAreaNum; i++) {
		printf("�� trip pid : %d, price : %d\n", ht[maxArea[i]].package[1]->t.pid, ht[maxArea[i]].package[1]->t.price);
		if (ht[maxArea[i]].heap_size > 0 && ht[maxArea[i]].package[1]->t.price < bestPackage->t.price) {
			bestPackage = ht[maxArea[i]].package[1];
		}
	}
	//printf("pop������\n");
	printf("������ bestPackage trip pid : %d, price : %d\n", bestPackage->t.pid, bestPackage->t.price);

	return popHeap(bestPackage->t.area);
}
// issue : ht���� ������ price�� ���� pid�� ã������ ã�Ⱑ �����.
//(reserve�Ҷ� pid�� ã�Ƽ� heap���� ���� �� hashchain���� �����ؾߵȴ�.)
// heapType�� ���ʿ� node�� ����������?