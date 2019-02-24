#include <iostream>

// 동철이의 프로그래밍 대회
using namespace std;

int main() {
	int t,n,m,correct=0,max_correct=0,winner=0;
	bool buf;
	cin >> t;
	for(int k=0;k<t;k++){
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> buf;
				if (buf) correct++;
			}
			if (max_correct < correct) {
				winner = 1;
				max_correct = correct;
			}
			else if (max_correct==correct){
				winner++;
			}
			correct = 0;
		}
		cout << "#" << k + 1 << " " << winner << " " << max_correct << endl;	
		winner = 0;
		max_correct = 0;
	}

	return 0;
}