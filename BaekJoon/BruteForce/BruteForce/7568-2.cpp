#include <iostream>

// non queue
using namespace std;

int main() {
	int grade[51][3];
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> grade[i][0] >> grade[i][1];
		grade[i][2] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (grade[i][0] < grade[j][0] && grade[i][1] < grade[j][1]) grade[i][2]++;
		}
		cout << grade[i][2] << " ";
	}
	return 0;
}