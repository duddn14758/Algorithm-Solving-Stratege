#include <stdio.h>
#pragma warning(disable:4996)
#define ll long long

int main(void)
{
	int test_case;
	int T;
	ll cnt = 0;
	ll a, b;
	
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%lld %lld", &a, &b);
		while (a != b) {
			if (a == 1) {
				cnt += b - 1;
				break;
			}
			else if (b == 1) {
				cnt += a - 1;
				break;
			}
			if (a > b) {
				a = a - b;
				cnt++;
			}
			else if (a < b) {
				b = b - a;
				cnt++;
			}
			else break;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}