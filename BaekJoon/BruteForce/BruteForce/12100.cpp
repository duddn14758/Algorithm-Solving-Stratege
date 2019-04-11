#include <iostream>
#include <string.h>
#include <algorithm>

// 2048(Easy)
using namespace std;

int arr[21][21];
int n,max_num=0;

void Print(int map[][21]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// i�� �������� i�� 0�϶��� ������ 0�̾ƴ� ���ڵ���� i���� �����
// i�� 0�� �ƴҶ��� j=i+1���� �˻��ؼ� i�� �Ȱ����� Ȯ���ϰ� ���ٸ� ��ġ�� continue, �ٸ��ٸ� ���ڵ��� i+1�� �����

int (*move_right(int map[][21]))[21] {
	for (int i = 0; i < n; i++) {	// �� �����ٺ���
		for (int j = n - 1; j >= 0; j--) {	// �� ������ĭ����
			if (map[i][j] == 0) {	// ù �˻��Ұ��� 0�̶��
				int k = j-1;
				while (k >= 0 && map[i][k] == 0) {
					k--;
				}
				if (k != -1) {
					int l = j;
					while (k >= 0) {
						map[i][l--] = map[i][k];
						map[i][k--] = 0;
					}
				}
			}
			// ù �˻��� ���� 0�� �ƴ϶��(0�̿�� �� �۾��� �����Ѵ�!)
			for (int k = j - 1; k >= 0; k--) {
				if (map[i][k] != 0) {
					if (map[i][k] == map[i][j]) {
						map[i][j] += 1;
						map[i][k] = 0;
					}
					break;
				}
			}			
		}
	}
	return map;
}

int(*move_left(int map[][21]))[21]{
	for (int i = 0; i < n; i++) {	// �� �����ٺ���
		for (int j = 0; j < n; j++) {	// �� ����ĭ����
			if (map[i][j] == 0) {	// ù �˻��Ұ��� 0�̶��
				int k = j + 1;
				while (k < n && map[i][k] == 0) {
					k++;
				}
				int l = j;
				while (k < n) {
					map[i][l++] = map[i][k];
					map[i][k++] = 0;
				}
			}
			// ù �˻��� ���� 0�� �ƴ϶��(0�̿�� �� �۾��� �����Ѵ�!)
			for (int k = j + 1; k < n; k++) {
				if (map[i][k] != 0) {
					if (map[i][k] == map[i][j]) {
						map[i][j] += 1;
						map[i][k] = 0;
					}
					break;
				}
			}
		}
	}
	return map;
}

int(*move_up(int map[][21]))[21]{
	for (int i = 0; i < n; i++) {	// �� ����ĭ����
		for (int j = 0; j < n; j++) {	// �� �����ٺ���
			if (map[j][i] == 0) {	// ù �˻��Ұ��� 0�̶��
				int k = j + 1;
				while (k < n && map[k][i] == 0) {
					k++;
				}
				int l = j;
				while (k < n) {
					map[l++][i] = map[k][i];
					map[k++][i] = 0;
				}
			}
			// ù �˻��� ���� 0�� �ƴ϶��(0�̿�� �� �۾��� �����Ѵ�!)
			for (int k = j + 1; k < n; k++) {
				if (map[k][i] != 0) {
					if (map[k][i] == map[j][i]) {
						map[j][i] += 1;
						map[k][i] = 0;
					}
					break;
				}
			}
		}
	}
	return map;
}

int(*move_down(int map[][21]))[21]{
	for (int i = 0; i < n; i++) {	// �� ����ĭ����
		for (int j = n-1; j >= 0; j--) {	// �� �����ٺ���
			if (map[j][i] == 0) {	// ù �˻��Ұ��� 0�̶��
				int k = j - 1;
				while (k >= 0 && map[k][i] == 0) {
					k--;
				}
				int l = j;
				while (k >=0) {
					map[l--][i] = map[k][i];
					map[k--][i] = 0;
				}
			}
			// ù �˻��� ���� 0�� �ƴ϶��(0�̿�� �� �۾��� �����Ѵ�!)
			for (int k = j - 1; k >= 0; k--) {
				if (map[k][i] != 0) {
					if (map[k][i] == map[j][i]) {
						map[j][i] += 1;
						map[k][i] = 0;
					}
					break;
				}
			}
		}
	}
	return map;
}


int (*move_func(int map[][21],int m))[21] {
	switch (m) {
	case 0:
		return move_right(map);
	case 1:
		return move_left(map);
	case 2:
		return move_up(map);
	case 3:
		return move_down(map);
	}
	return map;
}

int getNum(int n) {
	int i = 0;
	while (n > 1) {
		n /= 2;
		i++;
	}
	return i;
}

int setNum(int n) {
	int num = 1;
	for (int i = 0; i < n; i++)
		num *= 2;
	return num;
}

void DFS(int map[21][21],int cnt) {
	if (cnt > 5) return;
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				max_num = max(max_num, map[i][j]);
			}
	}
	//cout << cnt << endl;
	//if(cnt==2)
	//Print(map);
	
	int tmp1[21][21];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				tmp1[j][k] = map[j][k];
		int (*tmp2)[21] = move_func(tmp1, i);
		DFS(tmp2, cnt+1);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			arr[i][j] = getNum(arr[i][j]);
		}
	DFS(arr, 0);

	cout << setNum(max_num);

	return 0;
}