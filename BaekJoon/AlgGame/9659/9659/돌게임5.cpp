#include <stdio.h>

bool arr[1000000];
int way[23];

int main() {
	long long n;
	int num;
	int buffer=0;
	int pointer=1;
	int cur = 0;
	int count = 0;
	scanf("%lld", &n);
	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%d", &way[i]);
		arr[way[i]] = true;
		if (i == 0) {
			for (int j = 1; j < way[i]; j++)
				arr[j] = false;
		}
		else {
			if (way[i] - way[i - 1]>2) {		//1,4,5�� ��쿡 2,3�� ������ ����
				//printf("%d %d ���̸� ���Ѵ�\n", way[i-1], way[i]);
				for (int j = way[i-1]+1; j < way[i]; j++) {	//way[i-1]�� way[i]���̸� ä���ִ´�
					//printf("%d�˻� ", j);
					bool a = false;
					for (int k = 0; k < i; k++) {
						if (!arr[j - way[k]])
							a=true;
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
	cur = way[num-1]+1;
	buffer = cur;

	while (pointer>buffer) {
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

		if (arr[cur] == arr[pointer])
			pointer++;
		else {
			buffer = cur - 1;
			pointer = 1;
		}
		cur++;
	}
	

	for (int i = 1; i <= buffer; i++)
		printf("%d\n", arr[i]);

	//printf("%d", count);
	
	return 0;
}
