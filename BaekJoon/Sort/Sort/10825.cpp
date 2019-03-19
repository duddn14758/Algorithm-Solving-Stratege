#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// ������
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

bool cmp(const Grade &a, const Grade &b) {	// �տ��� ����, �ڿ��� �� �ε�
	if (a.kor < b.kor) return 0;			// ������������ - �տ��� ������ ���� ����
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