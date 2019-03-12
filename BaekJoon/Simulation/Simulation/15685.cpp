#include <iostream>

// µå·¡°ï Ä¿ºê
using namespace std;

int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
int dr[] = { -1,-1,1,1 };
int curv_x[] = { 0,-1,0,-1,0,1,0,-1 };
int curv_y[] = { 1,0,-1,0,-1,0,-1,0 };

int main() {
	int n, x, y,dir,dnum;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> dir >> dnum;
	}
	/*0,1,-1
	-1,0,-1
	0,-1,1
	1,0,1
int curv_x[]={0,-1,0,-1,0,1,0,-1};
int curv_y[]={1,0,-1,0,-1,0,-1,0};

	0,1
	-1,0
	0,-1
	-1,0
	0,-1
	1,0
	0,-1
	-1,0
	
	*/

	return 0;
}