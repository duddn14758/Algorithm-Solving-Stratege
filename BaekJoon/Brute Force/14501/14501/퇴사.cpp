#include <iostream>

void getPrice(int day, int price);
int buf[16][2];
int max=0;
int num;

int main() {
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		std::cin >> buf[i][0] >> buf[i][1];
	}

	for (int i = 0; i < num; i++)
		getPrice(i,0);

	std::cout << max;

	return 0;
}

void getPrice(int day,int price) {
	int curPrice = buf[day][1];
	day += buf[day][0];
	if (day > num) {
		max = price > max ? price : max;
		return;
	}
	else if (day == num) {
		price += curPrice;
		max = price > max ? price : max;
		return;
	}
	else {
		price += curPrice;
	}
	for (int i = day; i < num; i++) {
		getPrice(i, price);
	}
}