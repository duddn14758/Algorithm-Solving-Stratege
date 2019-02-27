#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char buf[1000001];

int main() {
	int n = 0;
	cin.getline(buf,1000001);
	char *c = strtok(buf, " ");
	while (c != NULL) {
		n++;
		c=strtok(NULL, " ");
	}	
	cout << n;

	return 0;
}