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

	// ���ڸ��� ����ִ���

	for (int i = 0; i < 9; i++)			// �Է� �� ���� �ʱ�ȭ
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
	// row, col �߿� vari�� �˻��ؼ� varicount�� 2 �ΰ��� �ִٸ� 1�ιٲٰ� �ٷ� set
	// ���ٸ� varicount-- �ϰ� �迭 �ϳ��� �δ�

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


bool setNum(int row, int col) {			// ���ڰ� �����Ǹ� true ���� �ƴϸ� false ����
	int rcount = 0;		//��
	int ccount = 0;		//��
	int scount = 0;		//�ֺ�
	int numcount1[9] = { 0 };	//r
	int numcount2[9] = { 0 };	//c
	int numcount3[9] = { 0 };	//s
	int num_list[9] = { 0 };	// �ߺ��Ǵ� ���ڵ��� �ӽ������� ������ ���ڿ�
	int pointer = 0;			// ���ڿ��� �����ϱ����� ���� ������
	int num;



	for (int i = 0; i < 9; i++) {		//���μ��� ���� �˻�
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


	// �ֺ� �˻�
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

	// count�� 1�̸� �ٷ� set �ƴϸ� stack �� ���� 
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