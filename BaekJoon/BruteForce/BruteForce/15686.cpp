#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

// ġŲ ���
using namespace std;

int city[51][51];
int n, m, min_length=98765432;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> house;		// �����ִ� ��ġ��
vector<pair<int, int>> chicken;		// ġŲ���� �մ� ��ġ��
pair<int,int> live_chicken[14];		// ����� ġŲ���� ��ġ��

int getLengthFromChicken(int x, int y) {		// �� ������ ġŲ�Ÿ����
	int minlen = 98765432;
	for (int i = 0; i < m; i++) {
		minlen = minlen < abs(x - live_chicken[i].first) + abs(y - live_chicken[i].second) ?
			minlen : abs(x - live_chicken[i].first) + abs(y - live_chicken[i].second);
	}
	return minlen;
}

void getMinLength() {		// ����� ���迡�� �� ġŲ�Ÿ� ���
	int total_length=0;
	for (int i = 0; i < house.size(); i++) {
		total_length += getLengthFromChicken(house[i].first, house[i].second);
	}
	min_length = total_length < min_length ? total_length : min_length;
}

void Print() {
	for (int i = 0; i < m; i++) {
		cout << live_chicken[i].first<<live_chicken[i].second << " ";
	}
	cout << endl;
}

void setLiveManage(int now, int cnt) {		// ����� ���� ����
	live_chicken[cnt] = chicken[now];
	if (++cnt == m) {
		getMinLength();
	}
	for (int i = now + 1; i < chicken.size(); i++) {
		setLiveManage(i, cnt);
	}
}

int main() {	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) house.push_back({ i,j });
			else if (city[i][j] == 2) chicken.push_back({ i,j });
		}
	for (int i = 0; i < chicken.size(); i++)
		setLiveManage(i, 0);
	cout << min_length;

	return 0;
}