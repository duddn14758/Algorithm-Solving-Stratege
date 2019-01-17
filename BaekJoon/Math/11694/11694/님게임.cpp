#include <stdio.h>

int main() {
	int num;
	int count;
	int a = 0, b = 0;

	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &count);
		if (count > 1)
			a++;
		else
			b++;
	}
	   
	if (a == 0) {
		if(b%2==0)
			printf("koosaga");
		else
			printf("cubelover");
	}
	else if (b == 0) {
		if (a % 2 == 0)
			printf("cubelover");
		else
			printf("koosaga");
	}
	else {
		a %= 2;
		b %= 2;

		if (a == 1 && b == 0) {
			printf("koosaga");
		}
		else if (a == 0 && b == 1) {
			printf("cubelover");
		}
		else if (a == 1 && b == 1) {
			printf("koosaga");
		}
		else
			printf("koosaga");
	}
	
	return 0;
}