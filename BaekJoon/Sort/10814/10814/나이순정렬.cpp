#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator()(pair<int,string> a, pair<int,string> b) {
		if (a.first > b.first) return true;
		else if (a.first == b.first) return true;
		return false;
	}
};

bool comp(pair<int, string> a, pair<int, string> b) {	
	if (a.first < b.first) return true;
	else if (a.first == b.first) return false;
	return false;
}

int main() {
	int n;
	//priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
	//priority_queue<pair<int,string>,vector<pair<int,string>>,cmp> pq;
	vector<pair<int, string>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int old;
		string name;
		cin >> old >> name;
		v.push_back(make_pair(old, name));
	}

	//while (n-- > 0) {
	//	cin >> old>>name;		
	//	//pq.push(make_pair(old,name));
	//	v.push_back(make_pair(old, name));
	//}	
	stable_sort(v.begin(), v.end(),comp);
	for (int i = 0; i<n; i++)
		cout << v[i].first << " "<< v[i].second << endl;
	
	return 0;
}