#include <stdio.h>

int pack[10001];
int max[10001];

int main() {
	int num;
	scanf("%d", &num);
	max[0] = 0;

	for (int i = 1; i <= num; i++) {
		scanf("%d", &pack[i]);
		max[i] = 0;		
		
		for (int j = 1; j <= i; j++)
			max[i] = max[i] > max[i - j] + pack[j] ? max[i] : max[i - j] + pack[j];
	}
	printf("%d", max[num]);
		
	return 0;
}