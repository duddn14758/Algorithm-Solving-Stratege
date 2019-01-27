#include <iostream>

int com(int a, int b);

int dp[31];

int main() {
	int c,l,r;
	std::cin >> c;

	while (c-- > 0) {
		std::cin >> l >> r;
		dp[l] = 1;
		for (int i = l+1; i <= r; i++) {
			int sum = 0;
			for (int j = 0; j < i - l; j++) {
				sum+= com(i - l + 1, i-j);
			}
			dp[i] = dp[i - 1] + sum;
			//dp[i] = dp[i - 1] + com(i - l+1, i);
			//std::cout << "dp = " << dp[i] << std::endl;
		}
		std::cout << dp[r] << std::endl;
	}

	return 0;
}

int com(int b, int a) {
	int fac = 1;
	for (int i = 0; i < b;i++) {
		fac *= a - i;
	}
	for (int i = 1; i <= b; i++) {
		fac /= i;
	}
	//std::cout << "return " << fac << std::endl;
	return fac;
}