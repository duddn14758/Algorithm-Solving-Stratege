#include <stdio.h>

int min = 0;
int N;
int color[1001][3];

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &color[i][j]);
	
	
	

	return 0;
}

void draw(int prev, int count,int price) {
	if (count == N) {
		if (min == 0||price<min)
			min = price;		
	}
	else
		for (int i = 0; i < 3; i++) {
			if (i != prev)
				draw(i, count + 1, price + color[count][i]);
		}
}