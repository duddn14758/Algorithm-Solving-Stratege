#include <stdio.h>

typedef struct point {
	int x;
	int y;
}Point;

Point pt[81] = { 0,0 };
int arr[9][9];
int vari[9][9][9];
int varic[9][9];
bool setNum(int row, int col);
void setRCS(int row, int col, int number);
int count = 0;
int pointer = 0;
bool chk_row[9];
bool chk_col[9];
bool chk_round[3][3];


int main() {

	// 몇자리가 비어있는지

	for (int i = 0; i < 9; i++)			// 입력 및 스택 초기화
		for (int j = 0; j < 9; j++) {
			scanf("%d", &arr[i][j]);
			varic[i][j] = 0;
			if (arr[i][j] == 0) {
				pt[pointer].x = i;
				pt[pointer++].y = j;
				chk_row[i] = true;
				chk_col[j] = true;
				chk_round[i / 3][j / 3] = true;
				//printf("%d %d %d\n", pt->x, pt->y, pointer);
				count++;
				for (int k = 0; k < 9; k++)
					vari[i][j][k] = 0;
			}
			else {
				chk_row[i] = false;
				chk_col[j] = false;
				chk_round[i / 3][j / 3] = false;
			}			
		}

	while (count > 0) {
		for (int i = 0; i < pointer; i++) {
			if (setNum(pt[i].x, pt[i].y)) {
				count--;
				//setRCS(pt[i].x, pt[i].y, arr[pt[i].x][pt[i].y]);
			}			
		}

		/*for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (arr[i][j] == 0)
					if (setNum(i, j)) {
						count--;
						setRCS(i, j, arr[i][j]);
					}
			}
		}*/
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void setRCS(int row, int col, int number) {
	// row, col 중에 vari를 검사해서 varicount가 2 인것이 있다면 1로바꾸고 바로 set
	// 없다면 varicount-- 하고 배열 하나씩 민다

	int rcount = 0;
	int ccount = 0;
	int scount = 0;
	
	int rstand = row-row%3;
	int cstand = col-col%3;

	if(chk_row[row]||chk_col[col]||chk_round[row/3][col/3])
	for (int i = 0; i < 9; i++) {
		if (varic[row][i] == 2) {
			count--;
			varic[row][i]--;
			for (int j = 0; j < 9; j++) {
				if (vari[row][i][j] != number && vari[row][i][j] != 0) {
					arr[row][i] = vari[row][i][j];
					setRCS(row, i, arr[row][i]);
					return;
				}
			}
		}

		if (varic[i][col] == 2) {
			count--;
			varic[i][col]--;
			for (int j = 0; j < 9; j++) {
				if (vari[i][col][j] != number && vari[i][col][j] != 0) {
					arr[i][col] = vari[i][col][j];
					setRCS(i, col, arr[i][col]);
					return;
				}
			}
		}

	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (varic[i + rstand][j + cstand] == 2) {
				count--;
				varic[i + rstand][j + cstand]--;
				for (int k = 0; k < 9; k++) {
					if (vari[i + rstand][j + cstand][k] != number && vari[i + rstand][j + cstand][k] != 0) {
						arr[i + rstand][j + cstand] = vari[i + rstand][j + cstand][k];
						setRCS(i + rstand, j + cstand, arr[i + rstand][j + cstand]);
						return;
					}
				}
			}
		}
	}


	return;
}


bool setNum(int row, int col) {			// 숫자가 단정되면 true 리턴 아니면 false 리턴
	int rcount = 0;		//행
	int ccount = 0;		//열
	int scount = 0;		//주변
	int numcount1[9] = { 0 };	//r
	int numcount2[9] = { 0 };	//c
	int numcount3[9] = { 0 };	//s
	int num_list[9] = { 0 };	// 중복되는 문자들을 임시적으로 보관할 문자열
	int pointer = 0;			// 문자열을 보관하기위해 사용될 포인터
	int num;



	for (int i = 0; i < 9; i++) {		//가로세로 먼저 검사
		if (arr[row][i] == 0) {
			rcount++;
		}
		else {
			numcount1[arr[row][i] - 1]++;
		}


		if (arr[i][col] == 0) {
			ccount++;
		}
		else {
			numcount2[arr[i][col] - 1]++;
		}
	}


	// 주변 검사
	int rstand = row - (row % 3);
	int cstand = col - (col % 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			if (arr[rstand + i][cstand + j] == 0) {
				scount++;
			}
			else {
				numcount3[arr[rstand + i][cstand + j] - 1]++;
			}

		}
	}

	// count가 1이면 바로 set 아니면 stack 에 넣음 
	if (rcount == 1) {
		for (int i = 0; i < 9; i++) {
			if (numcount1[i] == 0) {
				arr[row][col] = i + 1;
				return true;
			}
		}
	}

	if (ccount == 1) {
		for (int i = 0; i < 9; i++) {
			if (numcount2[i] == 0) {
				arr[row][col] = i + 1;
				return true;
			}
		}
	}

	if (scount == 1) {
		for (int i = 0; i < 9; i++) {
			if (numcount3[i] == 0) {
				arr[row][col] = i + 1;
				return true;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (numcount1[i] == 0 && numcount2[i] == 0 && numcount3[i] == 0)
			vari[row][col][pointer++] = i + 1;
	}

	return false;

}