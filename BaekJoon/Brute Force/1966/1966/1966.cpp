#include <iostream>

int main() {
	int c,num,point,buf,pointer=0;
	int q[101];
	int soon = 0;
	bool first = false;
	bool dif = false;
	std::cin >> c;

	while (c-- > 0) {
		std::cin >> num>>point;
		soon = 1;
		buf = 0;
		first = false;
		dif = false;
		for (int i = 0; i < num; i++) {
			std::cin >> q[i];					
		}
		for (int i = 0; i < num; i++) {
			if (i == point) continue;
			else if (q[i] >= q[point]) {
				if (i>point&&!first&&q[i] > q[point]) {
					buf = i-point-1;
					first = true;
				}				
				soon++;				
			}
			if (q[i] != q[point])
				dif = true;
		}
		if (!dif) buf = num-point -1;
		std::cout << soon - buf<<std::endl;
	}

	return 0;
}