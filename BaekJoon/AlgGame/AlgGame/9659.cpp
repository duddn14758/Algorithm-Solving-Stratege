#include <stdio.h>

// 돌게임 5

bool arr[10000];
int way[25];

int main() {
	long long n;
	int num;
	bool isOne = true;
	long long buffer = 0;
	long long pointer = 1;
	long long cur = 0;
	long long count = 0;
	scanf("%lld", &n);
	scanf("%d", &num);
	arr[0] = false;

	for (int i = 0; i < num; i++) {
		scanf("%d", &way[i]);
		arr[way[i]] = true;
		if (i == 0) {
			if (way[i] != 1)
				isOne = false;

			for (int j = 1; j < way[i]; j++)
				arr[j] = false;
		}
		else {
			if (way[i] - way[i - 1] > 2) {		//1,4,5의 경우에 2,3을 정의할 수단
				//printf("%d %d 사이를 구한다\n", way[i-1], way[i]);
				for (int j = way[i - 1] + 1; j < way[i]; j++) {	//way[i-1]과 way[i]사이를 채워넣는다
					//printf("%d검사 ", j);
					bool a = false;
					for (int k = 0; k < i; k++) {
						if (!arr[j - way[k]])
							a = true;
					}
					if (a) {
						//	printf("true!\n");
						arr[j] = true;
					}
					else {
						//printf("false!\n");
						arr[j] = false;
					}
				}
			}
			else {
				for (int j = way[i - 1] + 1; j < way[i]; j++)
					arr[j] = false;
			}
		}
	}
	if (isOne) {
		cur = way[num - 1] + 1;
		buffer = n;

		while (cur <= n || (pointer <= buffer)) {
			bool isTrue = false;
			for (int i = 0; i < num; i++) {
				if (!arr[cur - way[i]]) {
					isTrue = true;
					break;
				}
			}
			if (isTrue)
				arr[cur] = true;
			//printf("%d\n", arr[cur]);

			if (cur > 600) {
				if (arr[cur] == arr[pointer])
					pointer++;
				else {
					buffer = cur;
					pointer = 1;
				}
			}
			//printf("current : %lld, arr[%lld] : %d\n", cur,cur,arr[cur]);
			cur++;
		}
		if (cur > n) {
			for (int i = 1; i <= n; i++) {
				//printf("%d %lld\n", i, count);
				if (!arr[i])
					count++;
			}
		}
		else {
			/*for (int i = 1; i <= buffer; i++) {
				printf("%d\n", arr[i]);
				if (!arr[i])
					count++;
			}*/

			for (int i = 1; i <= buffer; i++) {
				//printf("%d\n", arr[i]);
				if (!arr[i])
					count++;
			}

			count = count * (n / buffer);
			n %= buffer;

			for (int i = 1; i <= n; i++) {
				//printf("%d\n", arr[i]);
				if (!arr[i])
					count++;
			}
		}
	}
	else
		count = 0;

	//printf("%d\n", buffer);	
	//for (int i = 1; i <= (int)buffer; i++)
		//printf("%d\n", arr[i]);

	printf("%lld", count);

	return 0;
}
