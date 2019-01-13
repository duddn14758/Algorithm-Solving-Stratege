#include <stdio.h>

int main() {
	unsigned long long min,max;
	unsigned long long count = 0;
	bool prime[1000001];
	bool nono;

	scanf("%lld %lld", &min, &max);

	for (int i = 2; i < 1000001; i++) {
		if (!prime[i]) 
			continue;
		else {
			for (int j = i + i; j < 1000001; j +=i) {
				/*if ((j>=min&&j<=max)||(j*j >= min && j*j <= max))
					count++;*/
				prime[j] = false;
			}
		}
	}

	//printf("%lld\n", max - min - count);

	for (unsigned long long i = min; i <= max; i++) {
		nono = true;
		for (unsigned long long j = 2; j < 1000001; j++) {
			if (!prime[j])
				continue;
			else {
				if (i % (j*j) == 0) {
					nono = false;
					break;
				}
			}
		}
		if (nono) {
			count++;
		}
	}

	printf("%lld\n", count);

	return 0;
}