#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct cmp {
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main() {
	int n,old;
	//priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
	priority_queue<pair<int, string>,vector<pair<int,string>>,cmp> pq;
	queue<string> q[201];
	string name;
	cin >> n;
	while (n-- > 0) {
		cin >> old>>name;
		pq.push(make_pair(old,name));
		//q[old].push(name);
	}
	/*for(int i=1;i<=200;i++){
		if (q[i].empty()) continue;
		while (!q[i].empty()) {
			cout << i << " " << q[i].front() << endl;
			q[i].pop();
		}	
	}*/
	return 0;
}