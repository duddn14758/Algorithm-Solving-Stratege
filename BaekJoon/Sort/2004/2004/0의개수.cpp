#include <stdio.h>

void getUP(long long num);
void getDown(long long num);
int two = 0, five = 0;

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long answer = 0;

	for (long long i = 0; i < b; i++) {
		getUP(a--);
		getDown(i + 1);
	}
		
	answer = two > five ? five : two;
	printf("%lld\n", answer);

	return 0;
}

void getUP(long long num) {
	while (num % 2 == 0) {
		num /= 2;
		two++;
	}
	while (num % 5 == 0) {
		num /= 5;
		five++;
	}
}

void getDown(long long num) {
	while (num % 2 == 0) {
		num /= 2;
		two--;
	}
	while (num % 5 == 0) {
		num /= 5;
		five--;
	}
}