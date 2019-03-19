#include <stdio.h>

void getUP(long long num);
void getDown(long long num);
int two = 0, five = 0;

int main() {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long n1 = 1, n2 = 1;
	long long answer = 0;

	while (n1 <= a) {
		n1 *= 2;
		two += a / n1;
	}

	while (n2 <= a) {
		n2 *= 5;
		five += a / n2;
	}
	n1 = 1;
	n2 = 1;
	while (n1 <= b) {
		n1 *= 2;
		two -= b / n1;
	}
	while (n2 <= b) {
		n2 *= 5;
		five -= b / n2;
	}
	n1 = 1;
	n2 = 1;
	while (n1 <= a - b) {
		n1 *= 2;
		two -= (a - b) / n1;
	}
	while (n2 <= a - b) {
		n2 *= 5;
		five -= (a - b) / n2;
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