#include <stdio.h>

#define MAX_N			5
#define MAX_NAME_LEN	7
#define MAX_TAG_LEN		4

#define MAX_ADD 50000
#define MAX_TYPE 500
#define MAX_SEC 100

#define ull unsigned long long

typedef struct book {
	ull title;
	int typeNum;		// del typeNum = 0
	int types[5];
	int section;
}Book;

typedef struct type {
	ull title;
	int typeName;
}Type;

Book hashBook[MAX_ADD];		// ADD 된 책들을 수용할 배열 -> trie안쓰고 hash써도 됨
int bookCnt;
Type hashType[MAX_TYPE];	// hash된 type들을 추가할 배열

typedef struct node {
	ull bid;
	int prev, next;
}node;
node nodePool[MAX_ADD * 5];
int nodeCnt;

struct LinkedList {
	int node;	// 마지막 노드 pool idx
	int count;	// node 갯수
	int head;	// 첫번째 노드

	void add(ull bid) {
		int newNode = nodeCnt++;
		nodePool[newNode].bid = bid;
		nodePool[newNode].next = newNode;
		nodePool[newNode].prev = -1;
		if (nodePool[node].prev != -1) nodePool[newNode].prev = node;
		count++;
	}

	void clear() {
		node = 0;
		head = -1;
		count = 0;
	}

	void remove(ull uid) {
		int now = nodePool[node].prev;
		while (now != -1) {
			if (nodePool[now].bid == uid) {
				nodePool[nodePool[now].prev].next = nodePool[now].next;
				nodePool[nodePool[now].next].prev = nodePool[now].prev;
				return;
			}
			now = nodePool[now].prev;
		}
	}
	
}Book2[MAX_SEC + 1][MAX_TYPE];


ull getHashTitle(char title[]) {
	ull tNum = 0;
	for (int i = 0; i < MAX_NAME_LEN && title[i] != '\0'; i++) {
		tNum = tNum << 6 + title[i];
	}
	return tNum;
}

int getHashType(char type[]) {
	int tNum = 0;
	for (int i = 0; i < MAX_TAG_LEN && type[i] != '\0'; i++) {
		tNum << 6 + type[i];
	}
	return tNum;
}

void init(int M)
{
	for (int i = 0; i < MAX_ADD; i++) {
		hashBook[i].typeNum = 0;
	}
	for (int i = 0; i <= MAX_SEC; i++) {
		for (int j = 0; j < MAX_TYPE; j++) {
			if (Book2[i][j].count != 0) {
				Book2[i][j].clear();
			}
		}
	}
}

void add(char mName[MAX_NAME_LEN], int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	// hashpool에 추가
	// linked tag에 추가(max 5개)
	ull nid = getHashTitle(mName);
	int nameHash = nid % MAX_ADD;

	while (hashBook[nameHash].typeNum == 0) {
		nameHash = (nameHash + 1) % MAX_ADD;
	}
	hashBook[nameHash].typeNum = mTypeNum;

	/* type을 찾고 있다면 pass 없다면 pool에 등록 */
	for (int i = 0; i < mTypeNum; i++) {
		int typeName = getHashType(mTypes[i]);
		int typeHash = typeName % MAX_TYPE;

		while (typeName != hashType[typeHash].typeName) {
			typeHash = (typeHash + 1) % MAX_TYPE;
		}
		if (typeName == hashType[typeHash].typeName) {
			return;
		}
		hashType[typeHash].typeName = typeHash;
		Book2[mSection][typeHash].add(nid);
	}
}

int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo)
{
	int typeHash = getHashType(mType) % MAX_TYPE;
	int count = 0;
	
	if (Book2[mFrom][typeHash].count > 0) {
		Book2[mTo][typeHash].node = Book2[mFrom][typeHash].node;
		Book2[mTo][typeHash].count += Book2[mFrom][typeHash].count;
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