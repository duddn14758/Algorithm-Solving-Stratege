#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

typedef struct mincount {
	LL number;
	int count;
}MC;

int main() {
	int N, L;
	LL *arr;
	LL buffer;
	MC min;
	int pointer = 0;


	scanf("%d %d", &N, &L);

	arr = (LL*)malloc(sizeof(LL)*L);

	while (--N) {
		scanf("%lld", &buffer);
		printf("%lld\n", buffer);

		if (pointer == 0) {
			min.number = buffer;
			min.count = 0;
		}
		else if(pointer>L){
			if (min.number == arr[pointer]) {
				if (min.count > 0) {
					min.count--;
				}
				else {
					min.number = buffer;
					min.count = 1;
					for (int i = 0; i < L;i++ ) {
						if (min.number > arr[i]) {
							min.number = arr[i];
							min.count = 1;
						}
						else if (min.number == arr[i]) {
							min.count++;
						}
					}
				}
			}
		}

		//ù ��¥ ���鼭 min ���� �ٽ��ؾߵ�
		arr[(pointer++) % L] = buffer;			
		

		if (min.number > buffer) {
			min.number = buffer;
			min.count = 1;
		}
		else if (min.number == buffer) {
			min.count++;
		}
		printf("%lld ", min.number);
	}


	return 0;
}