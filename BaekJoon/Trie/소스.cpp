#include <stdio.h>
#include <stdlib.h>

typedef struct child {
	char c;
	child* lchild;
	child* rchild;
};

bool noChild(child* pt) {
	return pt == NULL || pt->c == '.';
}

void insert(child* pt, char lc, char rc) {
	pt->lchild = (child*)malloc(sizeof(child));
	pt->rchild = (child*)malloc(sizeof(child));
	pt->lchild->c = lc;
	pt->rchild->c = rc;
	pt->lchild->lchild = NULL;
	pt->lchild->rchild = NULL;
	pt->rchild->lchild = NULL;
	pt->rchild->rchild = NULL;
}

child* search(child* pt, char c) {
	if (c == pt->c) {
		return pt;
	}
	child* lc, * rc;
	if (pt->lchild != NULL) {
		lc = search(pt->lchild, c);
		if (lc != NULL) return lc;
	}
	if (pt->rchild != NULL) {
		rc = search(pt->rchild, c);
		if (rc != NULL) return rc;
	}
	return NULL;
}

void front_search(child* pt) {
	if (noChild(pt->lchild) && noChild(pt->rchild)) {
		printf("%c", pt->c);
		return;
	}
	printf("%c", pt->c);
	if (!noChild(pt->lchild)) {
		front_search(pt->lchild);
	}
	if (!noChild(pt->rchild)) {
		front_search(pt->rchild);
	}
}

void middle_search(child* pt) {
	if (noChild(pt->lchild) && noChild(pt->rchild)) {
		printf("%c", pt->c);
		return;
	}
	if (!noChild(pt->lchild)) {
		middle_search(pt->lchild);
	}
	printf("%c", pt->c);
	if (!noChild(pt->rchild)) {
		middle_search(pt->rchild);
	}
}

void back_search(child* pt) {
	if (noChild(pt->lchild) && noChild(pt->rchild)) {
		printf("%c", pt->c);
		return;
	}
	if (!noChild(pt->lchild)) {
		back_search(pt->lchild);
	}
	if (!noChild(pt->rchild)) {
		back_search(pt->rchild);
	}
	printf("%c", pt->c);
}


int main() {
	int n;
	char r, lc, rc;
	child* root = NULL;
	root = (child*)malloc(sizeof(child));
	scanf("%d ", &n);
	scanf("%c %c %c", &r, &lc, &rc);
	root->c = r;
	insert(root, lc, rc);
	for (int i = 0; i < n - 1; i++) {
		scanf(" %c %c %c", &r, &lc, &rc);
		insert(search(root, r), lc, rc);
	}
	front_search(root);
	puts("");
	middle_search(root);
	puts("");
	back_search(root);

	return 0;
}