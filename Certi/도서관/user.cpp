#include <stdio.h>

#define MAX_N			5
#define MAX_NAME_LEN	7
#define MAX_TAG_LEN		4

#define MAX_ADD 50000
#define MAX_TYPE 500
#define MAX_SEC 100

#define ull unsigned long long

void mstrcpy(char dst[], const char src[]) {
	int c = 0;
	while ((dst[c] = src[c]) != '\0') ++c;
}

int mstrcmp(const char str1[], const char str2[]) {
	int c = 0;
	while (str1[c] != '\0' && str1[c] == str2[c]) ++c;
	return str1[c] - str2[c];
}

typedef struct book {
	ull title;
	int typeNum;		// del typeNum = 0
	int types[5];
}Book;

typedef struct type {
	bool used;
	char typeName[4];
}Type;

struct node {
	int next, prev;
}nodePool[MAX_ADD];
int nodeCnt = 0;

struct LinkedList {
	int node;
	int count;

	void clear() {
		node = -1;
		count = 0;
	}

	void add() {
		int now = nodeCnt++;
		nodePool[now].next = node;
		
	}
	
}TypeBookList[MAX_TYPE];

Book hashBook[MAX_ADD];	// ADD 된 책들을 수용할 배열
Type hashType[MAX_TYPE];
int secCount[MAX_SEC + 1];

ull getHashTitle(char title[]) {
	ull tNum = 0;
	for (int i = 0; i < MAX_NAME_LEN && title[i] != '\0'; i++) {
		tNum = tNum << 6 + title[i];
	}
	return tNum;
}

void init(int M)
{
	for (int i = 1; i <= M; i++) {
		secCount[i] = 0;
	}
	for (int i = 0; i < MAX_ADD; i++) {
		hashBook[i].typeNum = 0;
	}
}

void add(char mName[MAX_NAME_LEN], int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	// hashpool에 추가
	// linked tag에 추가(max 5개)
	int nameHash = 0;
	for (int i = 0; i < MAX_NAME_LEN && mName[i]!='\0'; i++) {
		nameHash *= 10;
		nameHash += mName[i]-'A';
		nameHash %= MAX_ADD;
	}

	while (hashBook[nameHash].typeNum == 0) {
		nameHash = (nameHash + 1) % MAX_ADD;
	}
	hashBook[nameHash].typeNum = mTypeNum;
	
	for (int i = 0; i < mTypeNum; i++) {
		int typeHash = 0;
		bool dupFlag = 0;
		for (int j = 0; j < MAX_TAG_LEN && mTypes[i][j] != '\0'; j++) {
			typeHash *= 10;
			typeHash += mTypes[i][j];
			typeHash %= MAX_TYPE;
		}

		while (hashType[typeHash].used) {
			if (getHashTitle(mName) == getHashTitle(hashType[typeHash].typeName)) {
				dupFlag = 1;
				break;
			}
			typeHash = (typeHash + 1) % MAX_TYPE;
		}
		hashBook[nameHash].types[i] = typeHash;
		if (dupFlag) {
			break;
		}
		mstrcpy(hashType[typeHash].typeName, mTypes[i]);
		hashType[typeHash].used = 1;
	}
	hashSec[mSection][secCount[mSection]++] = &hashBook[nameHash];
}

int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo)
{
	int typeHash = 0;
	for (int i = 0; i < MAX_TAG_LEN && mType[i] != '\0'; i++) {
		typeHash *= 10;
		typeHash += mType[i];
		typeHash %= MAX_TYPE;
	}
	while (mstrcmp(mType, hashType[typeHash].typeName) != 0) {
		typeHash = (typeHash + 1) % MAX_TYPE;
	}


	return 0;
}

void moveName(char mName[MAX_NAME_LEN], int mSection)
{

}

void deleteName(char mName[MAX_NAME_LEN])
{

}

int countBook(int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	return 0;
}