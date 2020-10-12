#include <stdio.h>
#define uint8_t unsigned char
#define MAX_SIZE 4097

class stack {	// '[', ']' 포인터 위치를 저장해놨다가 리턴하는 스택
private:
	int top = 0;
	int arr[MAX_SIZE];

public:
	int pop() {
		return arr[--top];
	}
	void push(int pos) {
		arr[top++] = pos;
	}
};

uint8_t arr[100001];	// 문자열 데이터
uint8_t buffer[100001]; // 문자열 buffer(입력)
char command[MAX_SIZE];		// 명령 데이터
int mTable[MAX_SIZE];
stack s;

void init(int sm, int n) {
	for (int i = 0; i < sm; i++) {
		arr[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		mTable[i] = 0;
		switch (command[i]) {
		case '[':
			s.push(i);
			break;
		case ']':
			mTable[i] = s.pop();
			mTable[mTable[i]] = i;
			break;
		}
	}
}

int main() {
	int t;
	int sm, sc, si;
	bool err;
	scanf("%d", &t);
	while (t-- > 0) {
		scanf("%d %d %d", &sm, &sc, &si);
		scanf("%s", command);	
		scanf("%s", buffer);
		int arr_pos = 0;		// 배열의 포인터
		int com_pos = 0;		// 명령어 포인터
		int buf_pos = 0;
		int try_num = 0;
		int start = 0, end = 0;
		int max_oper = 0;
		err = false;
		init(sm, sc);
		while (com_pos < sc) {
			//if (t == 0)
				//printf("arr : %d(%d), command : %c(%d)\n", a[arr_pos], arr_pos, command[com_pos], com_pos);
			switch (command[com_pos]) {
			case '-':
				arr[arr_pos]--;
				break;
			case '+':
				arr[arr_pos]++;
				break;
			case '<':
				if (--arr_pos < 0) {
					arr_pos = sm - 1;
				}
				break;
			case '>':
				if (++arr_pos >= sm) {
					arr_pos = 0;
				}
				break;
			case '[':
				if (arr[arr_pos] == 0) {
					com_pos = mTable[com_pos];
				}
				break;
			case ']':
				if (arr[arr_pos] != 0) {
					com_pos = mTable[com_pos];
				}
				break;
			case '.':
				break;
			case ',':
				if (buf_pos == si) {
					arr[arr_pos] = 255;
				}
				else {
					arr[arr_pos] = buffer[buf_pos++];
				}
				break;
			}
			com_pos++;
			max_oper = max_oper > com_pos ? max_oper : com_pos;
			if (++try_num >= 50000000) {
				err = true;
				break;
			}
		}
		if (err) {
			printf("Loops %d %d\n", mTable[max_oper], max_oper);
		}
		else {
			printf("Terminates\n");
		}
	}

	return 0;
}