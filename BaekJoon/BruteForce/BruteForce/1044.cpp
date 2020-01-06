#include <stdio.h>

long long t1Price[36], t2Price[36];
int N;
long long total1 = 0, total2 = 0, buffer;
long long ansdif = 9999999999;
bool arr[36];
bool ansArr[36];
long long sum1 = 0, sum2 = 0;

void solve(int now, int cnt,int max) {
	if (cnt >= max) {		
		total2 = sum2-buffer;
		long long nowdif = total1 - total2;
		if (nowdif < 0) nowdif *= -1;		

		if (nowdif < ansdif) {
			for (int i = 0; i < N; i++) {
				ansArr[i] = arr[i];
			}
			ansdif = nowdif;
		}
		return;
	}

	for (int i = now; i < N; i++) {
		arr[i] = 1;
		total1 += t1Price[i];
		buffer += t2Price[i];
		solve(i+1, cnt + 1,max);
		arr[i] = 0;
		total1 -= t1Price[i];
		buffer -= t2Price[i];
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &t1Price[i]);
		sum1 += t1Price[i];
	}
	for (int i = 0; i < N; i++) {
		scanf("%lld", &t2Price[i]);
		sum2 += t2Price[i];
	}
	solve(0,0,N/2);

	for (int i = 0; i < N; i++)
		if (ansArr[i]) printf("1 ");
		else printf("2 ");

	return 0;
}