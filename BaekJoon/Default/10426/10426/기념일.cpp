#include <iostream>
#include <cstring>
#include <stdlib.h>

bool isY(int year) {
	if (year % 100 == 0&&year%400!=0)
		return false;
	else if (year % 4 == 0)
		return true;
	return false;
}

int main() {
	char day[20];
	int year, month, date, from;

	std::cin >> day >> from;

	year = atoi(strtok(day, "-"));
	month = atoi(strtok(NULL, "-"));
	date = atoi(strtok(NULL, " "));	

	while (--from > 0) {
		date += 1;
		if ((month == 1|| month == 3|| month == 5|| month == 7|| month ==  8||month == 10 || month == 12) && date == 32) {
			if (month == 12) {
				year += 1;
				month = 1;
			}
			else month += 1;
			date = 1;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && date == 31) {
			month += 1;
			date = 1;
		}
		else if (month == 2 && isY(year) && date == 30) {
			month += 1;
			date = 1;
		}
		else if (month == 2 && !isY(year) && date == 29) {
			month += 1;
			date = 1;
		}
	}	
	std::cout<<year<<"-";	
	if (month < 10) std::cout << "0";
	std::cout << month<<"-";
	if (date < 10)std::cout << "0";
	std::cout << date;

	return 0;
}