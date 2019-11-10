#include <stdio.h>

typedef struct trip {
	int area;
	int pid;
	int price;
}Trip;

typedef struct node {
	Trip t;
	node* next;
}TN;

TN* hash_chain[10000];

void addNode(int area, int pid, int price) {
	int hs = pid % 10000;
	TN *node = new TN();
	node->t.area = area;
	node->t.pid = pid;
	node->t.price = price;
	node->next = hash_chain[hs];
	hash_chain[hs] = node;
	printf("addNode %d %d %d\n", area, pid, price);
}

void PrintNode(int hs) {
	TN* node = hash_chain[hs];
	printf("hash값 : %d\n", hs);
	if (node == NULL) printf("해당 값은 존재하지 않습니다\n");
	else
	while (node != NULL) {
		printf("%d %d %d\n", node->t.area, node->t.pid, node->t.price);
		node = node->next;
	}
	printf("\n");
}

int main() {
	int area, pid, price;
	addNode(1, 1, 1000);
	addNode(2, 2, 2000);
	addNode(3, 3, 3000);
	addNode(4, 10001, 4000);
	addNode(5, 100000001, 5000);
	PrintNode(1);
	PrintNode(2);
	PrintNode(6);

	return 0;
}