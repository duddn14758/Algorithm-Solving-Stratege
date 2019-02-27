#include <iostream>
#include <string.h>

// NBA³ó±¸
using namespace std;

int main() {
	int gt, hour, minute, goal, prevMin, bufMin, ATime = 0, BTime = 0, score1 = 0, score2 = 0;
	char time[10];
	char *str;

	cin >> gt >> goal >> time;
	prevMin = atoi(strtok(time, ":")) * 60;
	prevMin += atoi(strtok(NULL, " "));
	if (goal == 1) score1++;
	else score2++;
	for (int i = 0; i < gt-1; i++) {
		cin >> goal >> time;
		
		bufMin = atoi(strtok(time, ":"))*60;
		bufMin += atoi(strtok(NULL, " "));
		if (score1 > score2) ATime += bufMin-prevMin;
		else if (score1 < score2) BTime += bufMin-prevMin;
		prevMin = bufMin;
		if (goal == 1) score1++;
		else score2++;
	}
	if (score1 > score2) ATime += 60*48 - prevMin;
	else if (score1 < score2) BTime += 60*48 - prevMin;

	hour = ATime / 60;
	if (hour < 10) cout << "0";
	cout << hour << ":";
	minute = ATime % 60;
	if (minute < 10) cout << "0";
	cout << minute << endl;
	hour = BTime / 60;
	if (hour < 10) cout << "0";
	cout << hour << ":";
	minute = BTime % 60;
	if (minute < 10) cout << "0";
	cout << minute;

	return 0;
}