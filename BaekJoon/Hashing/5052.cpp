#pragma warning (disable:4996)
#include <stdio.h>

struct node {
	bool exNext;
	node* next[10];
};

node* node_list[10];
// �ΰ��̻� ����������ÿ��� false

bool addNode(int num[], int len) {
	int next = num[0];
	bool build = false;		// �������Դ��� �ƴϸ� Ÿ����Դ��� ����Ȯ��

	if (node_list[next] == NULL) {
		node* head = new node();
		node_list[next] = head;
		build = true;
		//printf("%d build\n",next);
	}	// head�� ���ٸ� �ϳ� �����
	// �ִ����� now�� node_list�� ù��°�� ����Ų��.
	node* now = node_list[next];

	// ��������ִ°� Ÿ����Դµ� ������ ���ٸ� fail
	for (int i = 1; i < len; i++) {
		next = num[i];

		if (now->exNext == false) {		// �������� ����°� �ƴϰ�
			//build
			// ������ ���µ� build��尡 �ƴҽ� false����
			// ������ ���� build����� ���� ����
			//printf("������ ������ : %d\n", next);
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
		else {	// �������� �������Ѵ�. -> next�� �ٸ� �� ���ݾ�
			if (now->next[next] == NULL) {
				// build
				node* nd = new node();
				nd->exNext = false;
				now->next[next] = nd;
				build = true;
				//printf("%d build\n", next);
			}
			else {
				// build��� �ٲ۴�. Ÿ�����.
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