#include <stdio.h>

bool arr[1000000];
int way[23];

int main() {
	long long n;
	int num;
	int buffer=0;
	int pointer=0;
	int count = 0;
	scanf("%lld", &n);
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &way[num]);
		arr[way[num]] = true;
	}
	buffer = num;

	while (pointer != num) {
		bool a = true;
		for (int i = 0; i < num; i++) {
			if (buffer - way[i] < 0)
				break;
			if (!arr[buffer - way[i]]) {
				a = false;
				break;
			}
		}
		arr[buffer] = a;

		if (arr[pointer] == arr[buffer])
			pointer++;
		else
			pointer = 0;

		buffer++;

		printf("%d\n", pointer);
	}

	for (long long i = 0; i < n; i++)
		if (arr[n%pointer])
			count++;

	printf("%d", count);
	
	return 0;
}
