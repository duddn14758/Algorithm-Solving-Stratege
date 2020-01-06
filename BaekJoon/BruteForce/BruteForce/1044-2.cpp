#include <stdio.h>
#define SWAP(a,b) {team t=a; a=b; b=t;}

struct team {
	long long price;
	int pos;
};

team t1[36], t2[36];
int N;
bool visited[36];
bool ansArr[36];

void sort() {
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if ((t1[i].price < t1[j].price)
				|| (t1[i].price == t1[j].price && t1[i].pos < t1[j].pos)) SWAP(t1[i], t1[j]);
			if ((t2[i].price < t2[j].price)
				|| (t2[i].price == t2[j].price && t2[i].pos < t2[j].pos)) SWAP(t2[i], t2[j]);
		}
	}
}

void solve() {
	long long total1=0, total2=0;
	int pt1 = 0, pt2 = 0;
	int size1 = 0, size2 = 0;
	bool nowt = 0;
	bool arr[36];
	while (1) {
		if (!nowt) {
			while (visited[t1[pt1].pos]) {
				pt1++;
			}
			arr[t1[pt1].pos] = nowt;
			total1 += t1[pt1].price;
			visited[t1[pt1++].pos] = 1;
			size1++;
		}
		else {
			while (visited[t2[pt2].pos]) {
				pt2++;
			}
			arr[t2[pt2].pos] = nowt;
			total2 += t2[pt2].price;
			visited[t2[pt2++].pos] = 1;
			size2++;
		}

		if (total1 > total2) nowt = 1;
		else nowt = 0;
		if (size1 >= N / 2) nowt = 1;
		else if (size2 >= N / 2) nowt = 0;

		if (size1+size2 >= N) {
			break;
		}
	}
	long long dif1 = total1 - total2;
	
	for (int i = 0; i < N; i++) {
		ansArr[i] = arr[i];
		visited[i] = 0;
		arr[i] = 0;
	}
	if (dif1 == 0) return;
	else if (dif1 < 0) dif1 *= -1;

	nowt = 1;
	total1 = 0;
	total2 = 0;
	pt1 = 0;
	pt2 = 0;
	size1 = 0;
	size2 = 0;
	while (1) {
		if (!nowt) {
			while (visited[t1[pt1].pos]) {
				pt1++;
			}
			arr[t1[pt1].pos] = nowt;
			total1 += t1[pt1].price;
			visited[t1[pt1++].pos] = 1;
			size1++;
		}
		else {
			while (visited[t2[pt2].pos]) {
				pt2++;
			}
			arr[t2[pt2].pos] = nowt;
			total2 += t2[pt2].price;
			visited[t2[pt2++].pos] = 1;
			size2++;
		}

		if (total1 > total2) nowt = 1;
		else nowt = 0;
		if (size1 >= N / 2) nowt = 1;
		else if (size2 >= N / 2) nowt = 0;
		if (size1+size2 >= N) {
			break;
		}
	}
	long long dif2 = total1 - total2;
	if (dif2 < 0) dif2 *= -1;
	if (dif1 <= dif2) return;
	else
		for (int i = 0; i < N; i++)
			ansArr[i] = arr[i];
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%lld", &t1[i].price);
		t1[i].pos = i;
	}
	for (int i = 0; i < N; i++) {
		scanf("%lld", &t2[i].price);
		t2[i].pos = i;
	}
	sort();
	solve();
	for (int i = 0; i < N; i++)
		printf("%d ", ansArr[i]+1);

	return 0;
}