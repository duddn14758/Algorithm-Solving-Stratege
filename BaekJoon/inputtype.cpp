#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, a, b;
	//ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//cin >> n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
		//cin >> a >> b;
		//cout << a + b << "\n";
	}
	return 0;
}