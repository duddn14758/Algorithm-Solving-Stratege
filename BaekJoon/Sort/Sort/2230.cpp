#include<cstdio>
#include<algorithm>

// ������ - Ǯ�ʿ���¹���(������ �����Կ��� �ұ��ϰ� ���������� Ʋ������ 
// ������� �����ʴ� �迭�������ص� �����̶��)
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