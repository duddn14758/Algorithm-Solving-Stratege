#include <iostream>
#include <cstring>

// ��ȭ��ȣ��� by trie
using namespace std;

struct node {
	struct node *next[12];
	int end;
	node() : next(), end(0) {};
};

node *make_new_node() {
	node *new_node = (node*)malloc(sizeof(node));
	for (int i = 0; i < 10; i++)
		new_node->next[i] = 0;
	new_node->end = 0;
	return new_node;
}

bool push(node **origin, char *arr) {
	int len = strlen(arr);
	node* tmp = *origin;
	for (int i = 0; i < len; i++) {
		if (!tmp->next[arr[i] - '0']) {
			if (tmp->end) return false;		// end�� true���(���̶��)
			tmp->next[arr[i] - '0'] = make_new_node();
		}
		tmp = tmp->next[arr[i] - '0'];
	}
	tmp->end = 1;	// ����� ���������� ���������� ���� ���� �ܸ�
	for (int i = 0; i < 10; i++) {
		if (tmp->next[i]) return false;
	}
	return true;
}

void delete_node(node *origin) {
	node *pre = origin;
	for (int i = 0; i < 10; i++) {
		if (pre->next[i])
			delete_node(pre->next[i]);
		delete pre;
		return;
	}	
}

int main() {
	int t, n;
	char arr[10001][11];
	cin >> t;

	while (t-- ) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> arr[i];

		bool check = 1;
		node *origin = make_new_node();
		for (int i = 0; i < n; i++) {
			check = push(&origin, arr[i]);
			if (!check) break;
		}

		if (check)cout << "YES" << endl;
		else cout << "NO" << endl;
		delete(origin);
	}

	return 0;
}