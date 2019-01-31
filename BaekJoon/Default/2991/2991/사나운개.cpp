#include <iostream>

int main() {
	int a1, a2, r1, r2, p, n, m;
	bool dog1[1000], dog2[1000];

	std::cin >> a1 >> r1 >> a2 >> r2;

	for (int i = 1; i < 1000; i++) {
		if ((i-1) % (a1 + r1) < a1) dog1[i] = 1;
		else dog1[i] = 0;
		if ((i-1) % (a2 + r2) < a2) dog2[i] = 1;
		else dog2[i] = 0;
	}
	std::cin >> p >> m >> n;

	std::cout << dog1[p] + dog2[p] << std::endl << dog1[m] + dog2[m] << std::endl << dog1[n] + dog2[n] << std::endl;

	return 0;
}