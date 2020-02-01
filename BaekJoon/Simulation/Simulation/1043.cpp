#include <stdio.h>

int N, M, tnum;
int truth[51];


template <typename T>
class vector {
private:
	T arr[52];
	int party_size = 0;
	bool tell = 0;		// 0이 거짓을 말할 수 있는 party
public:
	int size() {
		return party_size;
	}
	void push(T a) {
		arr[party_size++] = a;
	}
	bool isTruth() {
		return tell;
	}
	void setTruth() {
		tell = 1;
		for (int i = 0; i < party_size; i++) {
			truth[arr[i]] = 1;
		}
	}
	bool search() {
		for (int i = 0; i < party_size; i++) {
			if (truth[arr[i]]) return 1;
		}
		return 0;
	}
};

vector<int> party_list[51];

void Print() {
	for (int i = 0; i < N; i++) {
		printf("%d ", truth[i + 1]);
	}
	puts("");
}

bool spread() {	
	bool change = 0;
	for (int i = 0; i < M; i++) {
		if (!party_list[i].isTruth()) {		// 거짓말 할 수 있는 파티에서
			if (party_list[i].search()) {	// 하나라도 진실을 아는 사람이 나오면				
				party_list[i].setTruth();
				change = 1;
			}
		}
	}
	return change;
}

int main() {
	scanf("%d %d", &N, &M);
	scanf("%d", &tnum);
	int frnd;
	for (int i = 0; i < tnum; i++) {
		scanf("%d", &frnd);
		truth[frnd] = 1;
	}
	int cnt = 0;
	int frd_num;
	for (int k = 0; k < M; k++) {
		scanf("%d", &frd_num);
		bool ptruth = 0;
		for (register int i = 0; i < frd_num; i++) {
			scanf("%d", &frnd);
			party_list[k].push(frnd);
			if (truth[frnd]) ptruth = 1;
		}	
		if (ptruth) party_list[k].setTruth();
	}
	while (spread());
	for (int i = 0; i < M; i++) {
		if (!party_list[i].isTruth()) cnt++;
	}

	printf("%d", cnt);

	return 0;
}