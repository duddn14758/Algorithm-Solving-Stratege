#include <iostream>

// 연산자 끼워넣기
int n, total;
int numArr[12], opArr[11], op[4];
int max = 0, min = 0;
bool first = true;

int cal(int a, int b, int oper) {
	switch (oper) {
	case 0:
		return a + b;
	case 1:
		return a - b;
	case 2:
		return a * b;
	case 3:
		return a / b;
	}
}

void DFS(int cnt, int oper) {
	opArr[cnt++] = oper;
	op[oper]--;
	if (total == cnt) {
		int sum = numArr[0];

		for (int i = 0; i < cnt; i++) {
			sum = cal(sum, numArr[i + 1], opArr[i]);
		}

		if (first) {
			min = sum;
			max = sum;
			first = false;
		}
		else {
			min = sum < min ? sum : min;
			max = sum > max ? sum : max;
		}
		sum = 0;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			DFS(cnt, i);
		}
	}
	op[oper]++;
}

int main() {
	std::cin >> n;
	total = n - 1;
	for (int i = 0; i < n; i++)
		std::cin >> numArr[i];

	for (int i = 0; i < 4; i++)
		std::cin >> op[i];

	for (int i = 0; i < 4; i++)
		if (op[i] > 0)
			DFS(0, i);
	std::cout << max << std::endl << min;

	return 0;
}