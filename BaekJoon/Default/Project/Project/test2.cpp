#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main() {
	int arr[] = { -1,-1,0,5,2,3 };
	sort(arr, arr + 6);

	for (int i = 0; i < sizeof(arr); i++)
		cout << arr[i] << " ";

	return 0;
}