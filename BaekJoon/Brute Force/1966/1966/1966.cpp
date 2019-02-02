#include <iostream>

typedef struct Quu {
	int imp;
	int num;
};

int main() {
	int c,num,point,buf;
	Quu q[101];
	std::cin >> c;

	while (c-- > 0) {
		std::cin >> num>>point;
		int start = 0, end = num;
		for (int i = 0; i < num; i++) {
			std::cin >> buf;
			q[i].imp = buf;
			q[i].num = i;
		}
		int pointer = 0;
		int sec = 0;
		int a = 100;
		while (sec<num) {
			for (int i = sec; i <= num; i++) {
				if (i == num) {
					sec++;
					break;
				}
				pointer = sec;
				while (q[i].imp < q[pointer].imp) {
					pointer++;
				}
				if (pointer == num) sec++;
				for (int j = num; j < num + pointer; j++) {
					q[j] = q[j - num];
				}
				for (int j = 0; j < num; j++) {
					q[j] = q[j + pointer];
				}
			}
		}

		for (int i = 0; i < num; i++)
			std::cout << q[i].imp<<" ";
		std::cout << std::endl;
	}

	return 0;
}