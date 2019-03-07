#include <iostream>
#include <vector>
#include <queue>
#define INF 98765432

// ±Ã±ÝÇÑ ¹ÎÈ£
using namespace std;

int arr[21][21];
int dist[21];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			dist[j] = INF;
		}
	

	return 0;
}