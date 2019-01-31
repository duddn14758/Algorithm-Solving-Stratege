#include <iostream>

char name[500002];

int main() {
	long long num;
	std::cin >> name>>num;
	long long cur = 1, pointer = 0;	
	
	while (name[cur] >= 'a'&&name[cur] <= 'z') {
		if (name[cur] == name[pointer]) pointer++;
		else {
			pointer = 0;
			if (name[cur] == name[pointer]) pointer++;
		}
		cur++;
	}
	std::cout << cur + (cur - pointer)*(num - 1);

	return 0;
}