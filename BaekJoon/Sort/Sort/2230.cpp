#include<cstdio>
#include<algorithm>

// 수고르기 - 풀필요없는문제(정답이 존재함에도 불구하고 실제정답은 틀려지며 
// 설명과는 맞지않는 배열을선언해도 정답이뜬다)
using namespace std;
int n, m, a[100000], r = 2e9;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	sort(a, a + n);
	int i = 0, j = 0;
	while (j < n) {
		if (a[j] - a[i] < m) j++;
		else r = min(r, a[j] - a[i++]);
	}
	printf("%d", r);
	return 0;
}