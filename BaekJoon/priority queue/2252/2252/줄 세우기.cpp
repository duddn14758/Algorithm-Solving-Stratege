#include <stdio.h>
#include <queue>

using namespace std;

int degree[32001];		// �������� ���
vector<int> v[32001];	// i��° ������ ���ϴ� ��ǥ������ ���

int main() {		// vector�� �̿��� ���� ���� �˰���
	int n, m;
	int small, tall;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &small, &tall);
		degree[tall]++;				// �������� ī����
		v[small].push_back(tall);			// small������ ���� ���� tall�� �߰�
	}

	queue<int> now;					// ���������� 0�� �������� �����ϱ����� ť
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) now.push(i);
	}

	while (!now.empty()) {
		int i = now.front(); now.pop();
		printf("%d ", i);
		for (int j = 0; j < v[i].size(); j++) {	// i ��° ������ ���ϴ� ������ �������� ������Ʈ
			if (--degree[v[i][j]] == 0)			// ������Ʈ ���Ŀ� ���������� 0�� �ȴٸ�
				now.push(v[i][j]);				// queue�� push
		}
	}

	return 0;
}