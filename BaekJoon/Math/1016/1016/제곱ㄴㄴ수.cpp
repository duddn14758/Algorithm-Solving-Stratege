#include <stdio.h>

int main() {
	long long min, max;
	int count = 0;
	bool nono[1000001];

	scanf("%lld %lld", &min, &max);

	for (int i = 0; i <= 1000000; i++)
		nono[i] = false;
		
	for (long long i = 2; i*i <= max; i++) {
		long long start = min / (i*i);
		if (start*i*i != min)start++;
		for (long long j = start; i*i*j<=max;j++) {
			nono[i*i*j - min] = true;
		}		
	}

	for (int i = 0; i <= max - min; i++)
		if(!nono[i])
			count++;
	
	printf("%d\n", count);

	return 0;
}