#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int arr[50001];
int max_num = 0;

struct tree {
	int x;
	tree *l;
	tree *r;
};

void dfs(tree *T, int cnt) {
	if (arr[T->x] == 0) cnt++;
	arr[T->x]++;

	if (T->l != NULL)
		dfs(T->l, cnt);
	if (T->r != NULL)
		dfs(T->r, cnt);
	if (T->l == NULL && T->r == NULL)
		max(max_num, cnt);
	arr[T->x]--;
}

int solution(tree * T) {
	cout << "asdfs";
	memset(arr, 0, sizeof(arr));
	dfs(T, 0);
	return max_num;
}

int main() {
	tree *a[10];
	a[0]->x = 4;
	a[1]->x = 5;
	a[2]->x = 6;
	a[3]->x = 4;
	a[4]->x = 1;
	a[5]->x = 6;
	a[6]->x = 5;
	a[0]->l = a[1];
	a[0]->r = a[2];
	a[1]->l = a[3];
	a[2]->l = a[4];
	a[2]->r = a[5];
	a[3]->l = a[6];

	cout << solution(a[0]);

	return 0;
}