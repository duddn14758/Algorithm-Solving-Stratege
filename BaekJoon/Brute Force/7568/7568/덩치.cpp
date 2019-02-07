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

		while (!pq.empty()&&(weight < pq.top().second&&height>pq.top().first)) {	//같은순서의 것들을 큐에 push
			//height = pq.top().first;
			//weight = pq.top().second;
			q.push(pair<int, int>(pq.top().first, pq.top().second));
			pq.pop();
		}
		int tmp = soon;
		while (!q.empty()) {		// 큐에 있는것들에 번호매겨준다			
			for (int i = 0; i < num; i++) {
				if (grade[i][0] == q.front().first&&grade[i][1] == q.front().second) {
					grade[i][2] = soon;
				}
			}
			q.pop();
			tmp++;
		}
		soon = tmp;				// pop 된만큼 plus 되있을것이다!
	}		

	for (int i = 0; i < num; i++) {
		cout << grade[i][2] << " ";
	}

	return 0;
}