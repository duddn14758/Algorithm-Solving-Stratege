#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int grade[51][3];

int main() {
	priority_queue<pair<int,int>> pq;
	queue<pair<int, int>> q;
	int num, soon=1;
	int height, weight;
	int i = 0;

	cin >> num;

	for (int i = 0; i < num; i++) {
		cin >> height >> weight;
		grade[i][0] = height;
		grade[i][1] = weight;
		pq.push(pair<int,int>(height,weight));
	}

	while (!pq.empty()) {
		//cout << pq.top().first << " " << pq.top().second << endl;
		height = pq.top().first;
		weight = pq.top().second;
		pq.pop();
		q.push(pair<int, int>(height, weight));

		while (!pq.empty()&&(weight < pq.top().second&&height>pq.top().first)) {	//���������� �͵��� ť�� push
			//height = pq.top().first;
			//weight = pq.top().second;
			q.push(pair<int, int>(pq.top().first, pq.top().second));
			pq.pop();
		}
		int tmp = soon;
		while (!q.empty()) {		// ť�� �ִ°͵鿡 ��ȣ�Ű��ش�			
			for (int i = 0; i < num; i++) {
				if (grade[i][0] == q.front().first&&grade[i][1] == q.front().second) {
					grade[i][2] = soon;
				}
			}
			q.pop();
			tmp++;
		}
		soon = tmp;				// pop �ȸ�ŭ plus ���������̴�!
	}		

	for (int i = 0; i < num; i++) {
		cout << grade[i][2] << " ";
	}

	return 0;
}