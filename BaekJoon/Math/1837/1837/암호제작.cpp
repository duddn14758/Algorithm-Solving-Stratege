#include <stdio.h>

bool chk(char *s, int p);

bool prime[2000000];

int main() {
	char pwd[110];
	int K, i;
	
	scanf("%s %d", &pwd, &K);
	
	for (i = 2; i < 2000000; i++) {
		if (prime[i]) continue;
		for (int j = i + i; j < 2000000; j+=i)
			prime[j] = true;
	}

	for (i = 2; i < K; i++) {
		if (prime[i]) continue;
		if (chk(pwd, i)) {
			break;
		}
	}

	if (i == K)
		printf("GOOD\n");
	else
		printf("BAD %d\n", i);

	return 0;
}

bool chk(char *s, int p) {
	int num = 0;
	for (int i = 0; s[i]; i++) {
		num *= 10;
		num += s[i]-'0';
		num %= p;
	}
	if (num%p==0)
		return true;
	else
		return false;
}