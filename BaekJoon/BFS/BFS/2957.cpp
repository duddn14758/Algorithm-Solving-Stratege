#include <stdio.h>

int C = 0;

struct node {
	int num;
	node* left;
	node* right;
};

node* root;

void insert(int num,node *now) {
	C++;
	if (num < now->num) {
		if (now->left == NULL) {
			node* nd = new node();
			nd->num = num;
			now->left = nd;
		}
		else {
			insert(num, now->left);
		}
	}
	else {
		if (now->right == NULL) {
			node* nd = new node();
			nd->num = num;
			now->right = nd;
		}
		else {
			insert(num, now->right);
		}
	}
}

int main() {
	int N,num;
	scanf("%d", &N);
	scanf("%d", &num);
	node* nd = new node();
	nd->num = num;
	root = nd;
	printf("0\n");
	for (int i = 1; i < N; i++) {
		scanf("%d", &num);
		insert(num,root);
		printf("%d\n", C);
	}
	return 0;
}