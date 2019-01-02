#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float toGrade(char *buf);

int main()
{
	char buf[50];
	int count;
	int grade;
	int tgrade = 0;
	float total = 0;	

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf("%s", buf);
		scanf("%d", &grade);
		tgrade += grade;
		scanf("%s", buf);
		total += grade*toGrade(buf);
	}

	printf("%.2f", total / tgrade);
	return 0;
}

float toGrade(char *buf) {
	if (strcmp(buf, "A+") == 0) return 4.3;
	else if (strcmp(buf, "A0") == 0) return 4.0;
	else if (strcmp(buf, "A-") == 0) return 3.7;
	else if (strcmp(buf, "B+") == 0) return 3.3;
	else if (strcmp(buf, "B0") == 0) return 3.0;
	else if (strcmp(buf, "B-") == 0) return 2.7;
	else if (strcmp(buf, "C+") == 0) return 2.3;
	else if (strcmp(buf, "C0") == 0) return 2.0;
	else if (strcmp(buf, "C-") == 0) return 1.7;
	else if (strcmp(buf, "D+") == 0) return 1.3;
	else if (strcmp(buf, "D0") == 0) return 1.0;
	else if (strcmp(buf, "D-") == 0) return 0.7;
	else if (strcmp(buf, "F") == 0) return 0;
}