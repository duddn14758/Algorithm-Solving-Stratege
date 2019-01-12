#include <stdio.h>

bool check(char *c);

int main() {
	int a;
	char buffer[102];
	int count = 0;

	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		scanf("%s", &buffer);
		if (check(buffer))
			count++;
	}
	printf("%d\n", count);

	return 0;
}

bool check(char *c) {
	bool arr[26];
	for (int i = 0; i < 26; i++)
		arr[i] = true;
	int i = 0;
	arr[c[i++] - 'a'] = false;
	while (c[i] >= 'a'&&c[i] <= 'z') {
		if (c[i] != c[i - 1]){
			if (!arr[c[i] - 'a']) {
				return false;
			}
			else {
				arr[c[i] - 'a'] = false;
			}
		}
		i++;
	}
	return true;
}