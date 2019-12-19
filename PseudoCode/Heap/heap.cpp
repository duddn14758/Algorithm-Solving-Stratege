#include <stdio.h>
#define MAX 10000

struct node {
	char name[20];
	int phone;
	int age;
	char area[10];
};

typedef struct heaptype {
	node *heap[MAX];
	int heapsize;
}ht;

ht h;

void heapify() {
	int parent, child;
	node* item, *temp;
	item = h.heap[1];
	temp = h.heap[h.heapsize--];
	parent = 1;
	child = 2;
}

void pushHeap(node *nd) {
	h.heap[h.heapsize++] = nd;

	int i = ++(h.heapsize);

	while (i != 1 && h.heap[i / 2]) {

	}

	//heapify


}

node popHeap() {
	int parent, child;
	node *item, *temp;
	item = h.heap[1];
	temp = h.heap[h.heapsize--];
	parent = 1;
	child = 2;
}

int main() {
	node* nd1 = new node({ "young",1001,26,"Busan" });

	pushHeap(nd1);

	return 0;
}