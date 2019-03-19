#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// 국영수
using namespace std;

class Grade {
public:
	string name;
	int kor;
	int eng;
	int mth;
	Grade(string name, int kor, int eng, int mth) {
		this->name = name;
		this->kor = kor;
		this->eng = eng;
		this->mth = mth;
	}
};

bool cmp(const Grade &a, const Grade &b) {	// 앞에게 기준, 뒤엣게 비교 인듯
	if (a.kor < b.kor) return 0;			// 내림차순으로 - 앞에게 작을때 거짓 리턴
	else if (a.kor > b.kor) return 1;
	else {
		if (a.eng < b.eng) return 1;
		else if (a.eng > b.eng) return 0;
		else {
			if (a.mth < b.mth) return 0;
			else if (a.mth > b.mth) return 1;
			else {
				if (a.name < b.name) return 1;
				else if (a.name >= b.name) return 0;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	string name;
	int k, e, m;
	vector<Grade> v;
	for (int i = 0; i < n; i++) {
		cin >> name >> k >> e >> m;
		v.push_back(Grade(name, k, e, m));
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
		cout << v[i].name<<"\n";

	return 0;
}