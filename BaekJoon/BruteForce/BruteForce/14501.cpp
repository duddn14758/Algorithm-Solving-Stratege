#include <iostream>

// ���
void getPrice(int day, int price);
int buf[16][2];
int max = 0;
int num;
int dp[16];

int main() {
	std::cin >> num;

	for (int i = 0; i < num; i++) {
		std::cin >> buf[i][0] >> buf[i][1];
	}

	//for (int i = 0; i < num; i++)
		//getPrice(i,0);

	for (int i = num; i >= 1; i--) {
		if (buf[i - 1][0] + i - 1 > num) {		// ���������� �ϳ��� ������ ���ϴ°��
			dp[i] = dp[i + 1];
		}
		else {			// ~�Ϻ��� �������� �󸶸� ������ �ִ����� �Ųٷ� ��� �ذ���
			dp[i] = dp[i + buf[i - 1][0]] + buf[i - 1][1] > dp[i + 1] ? dp[i + buf[i - 1][0]] + buf[i - 1][1] : dp[i + 1];
		}				// �Ϸ羿 �մ��� (�ش� ��¥�� ���� �����³��� ����� dp + �ش� ����) �� ���� dp���� ũ��񱳸� �Ѵ�. 
		//std::cout << dp[i] << std::endl;
	}

	//std::cout << max;		// DFS�� ���
	std::cout << dp[1];

	return 0;
}

void getPrice(int day, int price) {		// DFS
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