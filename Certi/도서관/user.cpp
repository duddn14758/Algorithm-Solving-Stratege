#define MAX_N			5
#define MAX_NAME_LEN	7
#define MAX_TAG_LEN		4

#define MAX_ADD 60007
#define MAX_TYPE 507
#define MAX_SEC 100

#define ull unsigned long long

typedef struct book {
	ull title;
	int typeNum;			// del typeNum = 0
	int section;
	int nowCnt;
	int del;				// del�Ǿ��� ��ġ�� �ٽ� ���� ���� ��� --> ���� ��ġ������
}Book;

typedef struct type {
	ull typeName;
	Book *hash[MAX_ADD];	// ���� book�� �ּ�
	int bookNum;
}Type;

Book hashBook[MAX_ADD];		// ADD �� å���� ������ �迭 -> trie�Ⱦ��� hash�ᵵ ��
Type hashType[MAX_TYPE];	// hash�� type���� �߰��� �迭
int gidx;

ull getHashTitle(char title[]) {
	ull tNum = 0;
	for (int i = 0; i < MAX_NAME_LEN && title[i] != '\0'; i++) {
		if (title[i] >= 'A' && title[i] <= 'Z') {
			tNum = (tNum << 7) + title[i] - 'A' + 1;
		}
		else {
			tNum = (tNum << 7) + title[i] - 'a' + 28;
		}
	}
	return tNum;
}

ull getHashType(char type[]) {
	ull tNum = 0;
	for (int i = 0; i < MAX_TAG_LEN && type[i] != '\0'; i++) {
		if (type[i] >= 'A' && type[i] <= 'Z') {
			tNum = (tNum << 7) + type[i] - 'A' + 1;
		}
		else {
			tNum = (tNum << 7) + type[i] - 'a' + 28;
		}
	}
	return tNum;
}

void init(int M)
{
	for (int i = 0; i < MAX_ADD; i++) {
		hashBook[i].title = 0;
		hashBook[i].typeNum = 0;
		hashBook[i].section = 0;
		hashBook[i].nowCnt = 0;
	}
	for (int i = 0; i < MAX_TYPE; i++) {
		hashType[i].typeName = 0;
		hashType[i].bookNum = 0;
	}
	gidx = 1;
}

void add(char mName[MAX_NAME_LEN], int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	// hashtitle���ؼ� book �迭�� add
	// hashtype���ٰ� �迭�� �߰��� book�� �ּҸ� �־��ش�.
	ull bid = getHashTitle(mName);
	int nameHash = bid % MAX_ADD;
	while (hashBook[nameHash].typeNum > 0 || hashBook[nameHash].del == 1) {
		nameHash = (nameHash + 1) % MAX_ADD;
	}
	hashBook[nameHash].title = bid;
	hashBook[nameHash].typeNum = mTypeNum;
	hashBook[nameHash].section = mSection;

	/* type�� ã�� �ִٸ� pass ���ٸ� tag�� �߰�*/
	for (int i = 0; i < mTypeNum; i++) {
		ull typeName = getHashType(mTypes[i]);
		int typeHash = typeName % MAX_TYPE;

		// �ش�ĭ�� tag�� �����ϴ���, �����Ѵٸ� ����������
		while (hashType[typeHash].bookNum > 0 && typeName != hashType[typeHash].typeName) {
			typeHash = (typeHash + 1) % MAX_TYPE;
		}
		if (typeName != hashType[typeHash].typeName) {		// �ٸ��� tag hash�� �߰�, typename != 0
			hashType[typeHash].typeName = typeName;
		}
		hashType[typeHash].hash[hashType[typeHash].bookNum] = &hashBook[nameHash];
		hashType[typeHash].bookNum++;
	}
}

int moveType(char mType[MAX_TAG_LEN], int mFrom, int mTo)
{
	int count = 0;
	ull typeName = getHashType(mType);
	int typeHash = typeName % MAX_TYPE;
	while (typeName != hashType[typeHash].typeName) {
		typeHash = (typeHash + 1) % MAX_TYPE;
	}
	for (int i = 0; i < hashType[typeHash].bookNum; i++) {
		Book* book = hashType[typeHash].hash[i];
		if (book->del != 1 && book->section == mFrom) {
			book->section = mTo;
			count++;
		}
	}
	
	return count;
}

// --> del �Ȱ��� �ٽ� ������, tag�ȿ� �ִ� book�迭�� move�Ҷ� ������ ���� --> del�� ����ߵȴ�
// --> del�Ȱ��� �ٽ� �����ϸ� �ȵ�!
void moveName(char mName[MAX_NAME_LEN], int mSection)
{
	ull titleName = getHashTitle(mName);
	int titleHash = titleName % MAX_ADD;
	while (titleName != hashBook[titleHash].title) {
		titleHash = (titleHash + 1) % MAX_ADD;
	}
	hashBook[titleHash].section = mSection;
}

void deleteName(char mName[MAX_NAME_LEN])
{
	ull titleName = getHashTitle(mName);
	int titleHash = titleName % MAX_ADD;
	while (titleName != hashBook[titleHash].title) {
		titleHash = (titleHash + 1) % MAX_ADD;
	}
	hashBook[titleHash].typeNum = 0;
	hashBook[titleHash].title = 0;
	hashBook[titleHash].section = 0;
	hashBook[titleHash].del = 1;
}

int countBook(int mTypeNum, char mTypes[MAX_N][MAX_TAG_LEN], int mSection)
{
	int count = 0;
	int typeName;
	ull typeHash;
	ull typeHashOrg;
	bool existFlag = true;
	for (int i = 0; i < mTypeNum; i++) {
		typeName = getHashType(mTypes[i]);
		typeHash = typeName % MAX_TYPE;
		typeHashOrg = typeHash;
		existFlag = true;
		while (typeName != hashType[typeHash].typeName) {
			typeHash = (typeHash + 1) % MAX_TYPE;
			if (typeHashOrg == typeHash) {
				existFlag = false;
				break;
			}
		}
		if (!existFlag) {
			continue;
		}
		for (int j = 0; j < hashType[typeHash].bookNum; j++) {
			Book* buf = hashType[typeHash].hash[j];
			if (buf->section == mSection && buf->del != 1 &&buf->nowCnt != gidx) {
				buf->nowCnt = gidx;
				count++;
			}
		}
	}
	gidx++;

	return count;
}