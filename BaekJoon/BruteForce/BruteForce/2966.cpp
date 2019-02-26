#include <iostream>

// Âï±â

int main() {
	int n, sc = 0, cc = 0, hc = 0, max = 0;
	char buf[101];
	char s[] = { "ABC" };
	char c[] = { "BABC" };
	char h[] = { "CCAABB" };

	std::cin >> n;
	std::cin >> buf;
	for (int i = 0; i < n; i++) {
		if (buf[i] == s[i % 3]) sc++;
		if (buf[i] == c[i % 4]) cc++;
		if (buf[i] == h[i % 6]) hc++;
	}

	max = sc > cc ? sc : cc;
	max = max > hc ? max : hc;
	std::cout << max << std::endl;

	if (sc >= cc && sc >= hc)
		std::cout << "Adrian" << std::endl;
	if (cc >= sc && cc >= hc)
		std::cout << "Bruno" << std::endl;
	if (hc >= sc && hc >= cc)
		std::cout << "Goran" << std::endl;

	return 0;
}