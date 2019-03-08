#include <iostream>
#include <vector>
#include <queue>
#define INF 98765432

// 궁금한 민호
using namespace std;

int arr[21][21];
bool road[21][21];
int n;
int result = 0;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	
	// 플로이드 와샬 알고리즘
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i == j || j == k || k == i)
					continue;
				else if (arr[i][j] > arr[i][k] + arr[k][j]) {
					result = -1;
					break;
				}
				else if (arr[i][j] == arr[i][k] + arr[k][j])
					road[i][j] = true;

	if (result != -1)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (!road[i][j])
					result += arr[i][j];

	if (result == -1)
		cout << result;
	else
		cout << result/2;

	return 0;
}