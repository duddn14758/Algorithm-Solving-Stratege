#pragma warning (disable:4996)
#include <stdio.h>

struct node {
	bool exNext;
	node* next[10];
};

node* node_list[10];
// 두개이상 연결되있을시에는 false

bool addNode(int num[], int len) {
	int next = num[0];
	bool build = false;		// 만들고들어왔는지 아니면 타고들어왔는지 여부확인

	if (node_list[next] == NULL) {
		node* head = new node();
		node_list[next] = head;
		build = true;
		//printf("%d build\n",next);
	}	// head가 없다면 하나 만들고
	// 있던없던 now는 node_list의 첫번째를 가리킨다.
	node* now = node_list[next];

	// 만들어져있는걸 타고들어왔는데 다음이 없다면 fail
	for (int i = 1; i < len; i++) {
		next = num[i];

		if (now->exNext == false) {		// 없을때만 만드는게 아니고
			//build
			// 다음이 없는데 build모드가 아닐시 false리턴
			// 다음이 없고 build모드라면 새로 만듬
			//printf("다음이 없을때 : %d\n", next);
			if (build == false) {
				//printf("%d\n", next);
				return false;
			}
			node* nd = new node();
			nd->exNext = false;
			now->next[next] = nd;
			now->exNext = true;
			build = true;
			//printf("%d build\n",next);
		}
		else {	// 있을때도 만들어야한다. -> next가 다를 수 있잖아
			if (now->next[next] == NULL) {
				// build
				node* nd = new node();
				nd->exNext = false;
				now->next[next] = nd;
				build = true;
				//printf("%d build\n", next);
			}
			else {
				// build모드 바꾼다. 타고들어간다.
				build = false;
			}
		}
		now = now->next[next];
	}
	return 1;
}

void Init() {
	for (int i = 0; i < 10; i++)
		node_list[i] = NULL;
}

int main() {
	int TC, k;
	int num[11];
	bool press;

	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%d", &k);
		char buf[11];
		press = true;
		Init();
		for (int j = 0; j < k; j++) {
			scanf("%s", buf);
			int len = 0;
			while (buf[len] != 0) {
				num[len] = buf[len++] - '0';
			}
			if (!addNode(num, len)) {
				press = false;
				break;
			}
		}
		if (press) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}