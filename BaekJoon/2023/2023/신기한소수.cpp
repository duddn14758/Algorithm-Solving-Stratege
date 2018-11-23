#include <stdio.h>
#include <math.h>

bool isPrime(int num);
void backtracking(int num, int count);

int numArr[] = { 1,3,7,9 };
int size;


int main() {
	int *arr;
	int first[] = { 2,3,5,7 };

	scanf("%d", &size);

	for (int i = 0; i < 4; i++) {
		backtracking(first[i],1);
	}

	return 0;
}

void backtracking(int num,int count) {

	if (isPrime(num)) {
		if (count == size)
			printf("%d\n", num);
		else
			for (int i = 0; i < 4; i++) {
				backtracking(num*10+numArr[i], count + 1);
			}
	}
}

bool isPrime(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num%i == 0)
			return false;
	}
	return true;
}