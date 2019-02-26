#include <iostream>

typedef struct Quu {
	int imp;
	int num;
};

int main() {
	int c, num, point, buf;
	Quu q[101];
	std::cin >> c;

	while (c-- > 0) {
		std::cin >> num >> point;
		int start = 0, end = num;
		for (int i = 0; i < num; i++) {
			std::cin >> buf;
			q[i].imp = buf;
			q[i].num = i;
		}
		int pointer = 0;
		int sec = 0;
		int a = 100;
		for (int i = 0; i < num; i++) {
			/*for (int j = sec; j < num; j++) {
				std::cout << q[j].imp << " ";
			}
			std::cout << std::endl << sec << " " << i << std::endl;*/

			pointer = sec + 1;
			while (pointer < num&&q[sec].imp >= q[pointer].imp) {
				//std::cout << "compare " << q[sec].imp << " : " << q[pointer].imp << std::endl;
				pointer++;
			}
			if (pointer == num) {
				if (point == q[sec].num)
					break;
				sec++;
			}
			else {
				for (int j = num; j < num + pointer; j++) {
					q[j] = q[j - num + sec];
				}
				for (int j = sec; j < num; j++) {
					q[j] = q[j + pointer];
				}
			}
			i = sec;
		}
		for (int i = 0; i < num; i++) {
			if (q[i].num == point)
				std::cout << i + 1 << std::endl;
		}

		/*for (int i = 0; i < num; i++)
			std::cout << q[i].imp<<" ";
		std::cout << std::endl;*/
	}

	return 0;
}