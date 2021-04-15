#define MAX_NAME 21
#define MAX_FAMILY 200 

void mstrcpy(char dest[], const char src[])
{
	int i = 0;
	while (src[i] != '\0') { dest[i] = src[i]; i++; }
	dest[i] = src[i];
}

typedef struct Person {
	char name[MAX_NAME];
	bool sex;		// 0 : male, 1 : female
	int child[MAX_FAMILY];
	int childNum;
	int mother;
	int father;
	int partner;
}Person;

typedef struct Node {
	int fidx;		// 해당노드에 사람이 존재한다면 pool의 idx
	int next[26];	// 다음노드가 존재한다면 
}Node;

typedef struct Trie {
	int root[26];
}Trie;

Node nodePool[MAX_NAME * MAX_FAMILY];
Person familyPool[MAX_FAMILY];
int nodeIdx;
int familyIdx;
Trie tree;

void makeNameTree(char name[]) {
	int idx = 1;
	Node* nd = &nodePool[name[0] - 'a'];
	while (name[idx] != '\0' && idx < MAX_NAME) {
		if (nd->next[name[idx] - 'a'] == -1) {
			nd->next[name[idx] - 'a'] = nodeIdx++;
		}
		nd = &nodePool[nd->next[name[idx] - 'a']];
	}
}

int getNameIdx(char name[]) {
	Node* nd = &nodePool[tree.root[name[0]]];
	int i = 1;
	while (name[i] != '\0') {
		nd = &nodePool[nd->next[name[i] - 'a']];
	}
	return nd->fidx;
}

void init(char initialMemberName[], int initialMemberSex)
{
	nodeIdx = 26;
	familyIdx = 0;
	for (int i = 0; i < nodeIdx; i++) {
		nodePool[i].fidx = -1;
		for (int j = 0; j < 26; j++) {
			nodePool[i].next[j] = -1;
		}
	}
	for (int i = 0; i < familyIdx; i++) {
		familyPool[i].mother = -1;
		familyPool[i].father = -1;
		familyPool[i].childNum = 0;
		familyPool[i].mother = -1;
		// name이랑 sex는 add 할때 반드시 추가됨으로 초기화 할 필요 없다.
	}
	makeNameTree(initialMemberName);
	mstrcpy(familyPool[familyIdx].name, initialMemberName);
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[])
{
	Person *p = &familyPool[getNameIdx(existingMemberName)];
	
	if (relationship == 0) {		// partner
		if (p->sex == newMemberSex || p->partner != -1) {
			return false;
		}

	}
	else if (relationship == 1) {	// parent
		if (newMemberSex) {		// female
			if (p->mother != -1) {
				return false;
			}
			p = &familyPool[nodeIdx];
			
		}
		else {
			if (p->father != -1) {
				return false;
			}
			p = &familyPool[nodeIdx];
		}

	}
	else {							// child

	}
	makeNameTree(newMemberName);
	mstrcpy(familyPool[familyIdx].name, newMemberName);
	familyPool->sex = newMemberSex;

	return false;
}

int getDistance(char nameA[], char nameB[])
{
	return -1;
}

int countMember(char name[], int dist)
{
	return -1;
}
