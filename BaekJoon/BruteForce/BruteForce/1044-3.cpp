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
int half;

int getNextPointDif(int leader, int pt) {
	int org;
	if (leader) {
		while (pt < N && visited[t1[pt].pos]) {
			pt++;
		}

		org = t1[pt].price;
		while (pt<N&&visited[t1[++pt].pos]);
		return org - t1[pt].price;			
	}
	else {
		while (pt < N && visited[t2[pt].pos]) {
			pt++;
		}
		org = t2[pt].price;
		while (pt<N&&visited[t2[++pt].pos]);
		return org - t2[pt].price;
	}
}

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

void Print() {
	for (int i = 0; i < N; i++)
		printf("%d ", visited[i]);
	puts("");
}

void solve() {
	long long total1 = 0, total2 = 0;
	int pt1 = 0, pt2 = 0;
	int size1 = 0, size2 = 0;
	bool nowt = 0;
	bool arr[36];
	while (1) {
		if (!nowt) {
			while (visited[t1[pt1].pos]) {
				pt1++;
			}
			team NextPoint = t1[pt1];

			if (getNextPointDif(!nowt, pt1) < getNextPointDif(nowt, pt2)) {
				NextPoint = t2[pt2++];
			}
			else pt1++;
			printf("%dteam select %d\n", nowt + 1, NextPoint.pos);
			arr[NextPoint.pos] = nowt;
			total1 += NextPoint.price;
			visited[NextPoint.pos] = 1;
			size1++;
		}
		else {
			while (visited[t2[pt2].pos]) {
				pt2++;
			}

			team NextPoint = t2[pt2];

			if (getNextPointDif(!nowt, pt2) < getNextPointDif(nowt, pt1)) {
				NextPoint = t1[pt1++];
			}
			else pt2++;
			printf("%dteam select %d\n", nowt + 1, NextPoint.pos);

			arr[NextPoint.pos] = nowt;
			total2 += NextPoint.price;
			visited[NextPoint.pos] = 1;
			size2++;
		}

		if (total1 > total2) nowt = 1;
		else nowt = 0;
		if (size1 >= N / 2) nowt = 1;
		else if (size2 >= N / 2) nowt = 0;

		if (size1 + size2 >= N) {
			break;
		}
		Print();
	}
	long long dif1 = total1 - total2;

	for (int i = 0; i < N; i++) {
		ansArr[i] = arr[i];
		visited[i] = 0;
		printf("%d ", arr[i]);
		arr[i] = 0;
	}
	puts("");
	if (dif1 == 0) return;
	else if (dif1 < 0) dif1 *= -1;
	printf("now dif : %lld\n", dif1);
	
	nowt = 1;
	total1 = 0;
	total2 = 0;
	pt1 = 0;
	pt2 = 0;
	size1 = 0;
	size2 = 0;
	printf("2nd\n");
	while (1) {
		if (!nowt) {
			while (visited[t1[pt1].pos]) {
				pt1++;
			}
			team NextPoint = t1[pt1];

			if (getNextPointDif(!nowt, pt1) < getNextPointDif(nowt, pt2)) {
				NextPoint = t2[pt2++];
			}
			else pt1++;
			printf("%dteam select %d\n", nowt + 1, NextPoint.pos);
			arr[NextPoint.pos] = nowt;
			total1 += NextPoint.price;
			visited[NextPoint.pos] = 1;
			size1++;
		}
		else {
			while (visited[t2[pt2].pos]) {
				pt2++;
			}

			team NextPoint = t2[pt2];

			if (getNextPointDif(!nowt, pt2) < getNextPointDif(nowt, pt1)) {
				NextPoint = t1[pt1++];
			}
			else pt2++;
			printf("%dteam select %d\n", nowt + 1, NextPoint.pos);

			arr[NextPoint.pos] = nowt;
			total2 += NextPoint.price;
			visited[NextPoint.pos] = 1;
			size2++;

		}

		if (total1 > total2) nowt = 1;
		else nowt = 0;
		if (size1 >= N / 2) nowt = 1;
		else if (size2 >= N / 2) nowt = 0;

		if (size1 + size2 >= N) {
			break;
		}
		Print();
	}
	long long dif2 = total1 - total2;
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}
	puts("");
	if (dif2 < 0) dif2 *= -1;

	printf("now dif : %lld\n", dif2);

	if (dif1 <= dif2) return;
	else
		for (int i = 0; i < N; i++)
			ansArr[i] = arr[i];
}

int main() {
	scanf("%d", &N);
	half = N / 2;

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
		printf("%d ", ansArr[i] + 1);

	return 0;
}