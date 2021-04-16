#include <stdio.h>
#define MAX_NAME 21
#define MAX_FAMILY 200 
#define MAX_HASH 50007

typedef struct Dist {
	int idx;
	int dist;
}Dist;

typedef struct Person {
	int name;
	bool sex;		// 0 : male, 1 : female
	int child[MAX_FAMILY];
	int childNum;
	int mother;
	int father;
	int partner;
}Person;

Person familyPool[MAX_FAMILY];
int familyIdx;
const int e = 97;

int getNameHash(char name[]) {
	int ret = 0;
	for (int i = 0; name[i] != '\0'; i++) {
		ret += ((ret * e) + name[i]) % MAX_HASH;
	}
	
	return ret;
}

int getIdx(char name[]) {
	int nameHash = getNameHash(name);
	for (int i = 0; i < familyIdx; i++) {
		if (familyPool[i].name == nameHash) return i;
	}
	printf("@@@@@@@@@@@@@ %d\n",nameHash);
	return -1;
}

void init(char initialMemberName[], int initialMemberSex)
{
	for (int i = 0; i < MAX_FAMILY; i++) {
		familyPool[i].name = 0;
		familyPool[i].mother = -1;
		familyPool[i].father = -1;
		familyPool[i].partner = -1;
		familyPool[i].childNum = 0;
		// name이랑 sex는 add 할때 반드시 추가됨으로 초기화 할 필요 없다.
	}
	familyIdx = 0;

	Person* p = &familyPool[0];
	p->name = getNameHash(initialMemberName);
	p->sex = initialMemberSex;
	//printf("name : %d\n", p->name);
	familyIdx++;
}

void makeChildRel(int child, int parent) {


}

void makeFatherRel(int father, int child) {
	Person* c = &familyPool[child];
	Person* f = &familyPool[father];

	c->father = father;
	//f->child[f->childNum++] = child;
	
	for (int i = 0; i < f->childNum; i++) {
		if (c->mother != -1) {
			f->partner = c->mother;
			familyPool[c->mother].partner = father;
		}

	}

}

void makeMotherRel(int mother, int child) {

}

void makePartnerRel(int me, int partner) {

}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[])
{
	// get hash name으로 name란을 채워준다
	//printf("ADD %s %d %d %s\n",newMemberName,newMemberSex,relationship,existingMemberName);

	int existIdx = getIdx(existingMemberName);
	Person* p = &familyPool[existIdx];

	if (relationship == 0) {		// partner
		if (p->sex == newMemberSex || p->partner != -1) {
			return false;
		}
		p->partner = familyIdx;

		p = &familyPool[familyIdx];
		p->partner = existIdx;
	}
	else if (relationship == 1) {	// parent
		if (newMemberSex) {		// female
			if (p->mother != -1) {
				return false;
			}
			// exist의 부모 등록
			p->mother = familyIdx;
		}
		else {
			if (p->father != -1) {
				return false;
			}
			p->father = familyIdx;
		}
		p = &familyPool[familyIdx];
		p->child[p->childNum++] = existIdx;
	}
	else {							// child
		// exist의 child 등록
		// if exist가 partner 가 있다면 partner<->아이의 관계도 만들어줘야됨
		p->child[p->childNum++] = familyIdx;
		if (p->sex) {		//exist 가 여자이면
			p = &familyPool[familyIdx];
			p->mother = existIdx;
		}
		else {
			p = &familyPool[familyIdx];
			p->father = existIdx;
		}
	}
	p->name = getNameHash(newMemberName);
	p->sex = newMemberSex;
	familyIdx++;
	//printf("name : %d, fIdx : %d\n",p->name, familyIdx);

	return true;
}

int getDistBfs(int start, int end) {	// start end 는 familyIdx로 온다
	int visited[MAX_FAMILY];
	Dist queue[MAX_FAMILY];
	int head = 0, tail = 0;
	int min = 9999;

	queue[tail++] = { start, 0 };
	visited[start] = 1;
	while (head < tail) {
		Dist now = queue[head++];
		Person *p = &familyPool[now.idx];

		if (now.dist > min) continue;
		if (now.idx == end) {
			min = min < now.dist ? min : now.dist;
			continue;
		}

		if (p->father != -1 && visited[p->father] > now.dist+1) {
			queue[tail++] = { p->father,now.dist + 1 };
			visited[p->father] = now.dist+1;
		}
		if (p->mother != -1 && visited[p->mother] > now.dist+1) {
			queue[tail++] = { p->mother,now.dist + 1 };
			visited[p->mother] = now.dist+1;
		}
		if (p->partner != -1 && visited[p->partner]>now.dist) {
			queue[tail++] = { p->partner,now.dist };
			visited[p->partner] = now.dist;
		}
		if (p->childNum > 0) {
			for (int i = 0; i < p->childNum; i++) {
				if (visited[p->child[i]]>now.dist+1) {
					queue[tail++] = { p->child[i],now.dist + 1 };
					visited[p->child[i]] = now.dist+1;
				}
			}
		}
	}
	return min;
}

int getCountBfs(int start, int dist) {
	bool visited[MAX_FAMILY];
	Dist queue[MAX_FAMILY];
	int head = 0, tail = 0;
	int count = 0;

	queue[tail].idx = start;
	queue[tail++].dist = 0;
	visited[start] = 1;
	while (head < tail) {
		Dist now = queue[head++];
		Person* p = &familyPool[now.idx];

		if (now.dist > dist) continue;
		count++;

		if (p->father != -1 && !visited[p->father]) {
			queue[tail++] = { p->father,now.dist + 1 };
			visited[p->father] = 1;
		}
		if (p->mother != -1 && !visited[p->mother]) {
			queue[tail++] = { p->mother,now.dist + 1 };
			visited[p->mother] = 1;
		}
		if (p->partner != -1 && !visited[p->partner]) {
			queue[tail++] = { p->partner,now.dist };
			visited[p->partner] = 1;
		}
		if (p->childNum > 0) {
			for (int i = 0; i < p->childNum; i++) {
				if (!visited[p->child[i]]) {
					queue[tail++] = { p->child[i],now.dist + 1 };
					visited[p->child[i]] = 1;
				}
			}
		}
	}
	return count - 1;
}

int getDistance(char nameA[], char nameB[])
{
	printf("getDist\n");
	return getDistBfs(getIdx(nameA),getIdx(nameB));
}

int countMember(char name[], int dist)
{
	printf("getCount\n");
	return getCountBfs(getIdx(name), dist);
}
