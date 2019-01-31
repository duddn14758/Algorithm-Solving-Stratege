#include <iostream>

int main() {
	char name[500002];
	long long num;
	std::cin >> name>>num;
	long long cur=1,pointer = 0;

	while (name[cur] >= 'a'&&name[cur] <= 'z') {
		if (name[cur] == name[pointer]) pointer++;
		else {		
			pointer = 0;
			if (name[cur] == name[pointer]) pointer++;
		}
		cur++;
	}	
	//std::cout << cur*num-(num-1)*pointer;
	std::cout << cur+(cur-pointer)*(num-1);

	return 0;
}