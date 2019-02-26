#include <iostream>

// 퇴사
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
		if (buf[i - 1][0] + i - 1 > num) {		// 마감일전에 하나도 끝내지 못하는경우
			dp[i] = dp[i + 1];
		}
		else {			// ~일부터 일했을때 얼마를 받을수 있는지를 거꾸로 계산 해간다
			dp[i] = dp[i + buf[i - 1][0]] + buf[i - 1][1] > dp[i + 1] ? dp[i + buf[i - 1][0]] + buf[i - 1][1] : dp[i + 1];
		}				// 하루씩 앞당기며 (해당 날짜의 일이 끝나는날에 저장된 dp + 해당 보수) 와 이전 dp와의 크기비교를 한다. 
		//std::cout << dp[i] << std::endl;
	}

	//std::cout << max;		// DFS답 출력
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