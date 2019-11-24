#include <stdio.h>
#define MAX 1000
// 출석부

template <typename T>
class Queue {
private:
	T queue[MAX];
	int head, tail;
public:
	Queue() {
		head = 0;
		tail = 0;
	}
	bool empty() {
		return head == tail;
	}
	void push(T arg) {
		queue[tail++] = arg;
	}
	T pop() {
		return queue[head++];
	}
};

typedef struct student {
	char name[11];
	int height;
	int age;
}ST;

typedef struct heaptype {
	ST *heap[MAX];		// heap에는 student의 주소를 넣어둔다.
	int heap_size = 0;
}HeapType;

HeapType ht;			// min_heap으로 정렬 - 가장 작은것이 root로

void pushHeap(ST *std) {	// 아래서 부터 올라가는 방식
	int i = ++ht.heap_size;
	while (i != 1 && ht.heap[i/2]->age>std->age) {	// 기준이 더 작은동안 계속 heap[i]를 내린다.	
		ht.heap[i] = ht.heap[i / 2];				// -> 이렇게하면 swap필요없음
		i /= 2;
	}
	ht.heap[i] = std;	// 적절한 i위치를 찾아서 넣기만하면됨
}

ST *popHeap() {		// 위엣거를 빼고 위에서부터 내려가는 방식
	ST* min = ht.heap[1];
	ST* tmp = ht.heap[ht.heap_size--];	// ht.heap[1]은 굳이 바꾸지 않아도 상관X
	int parent = 1, child = 2;			// heap[parent]와 비교하지않고 기준(tmp)와 비교하기 때문

	while (child <= ht.heap_size) {	// child가 범위를 벗어나지 않는 동안
		if (child+1<=ht.heap_size&&ht.heap[child]->age > ht.heap[child + 1]->age)		// 자식들 둘중 더 작은것 고르는 과정
			child++;
		if (tmp->age < ht.heap[child]->age) {	// tmp가 더작다면 parent자리가 맞는자리
			break;
		}
		ht.heap[parent] = ht.heap[child];		// parent가 더 크면 parent에 child복사하고
		parent = child;							// 밑으로 내려감
		child *= 2;
	}	
	ht.heap[parent] = tmp;		// 제자리는 parent자리
	return min;
}

int main() {
	ST* std1 = new ST({ "김영우",170,26 });
	ST* std2 = new ST({ "엄정하",174,28 });
	ST* std3 = new ST({ "김태용",176,18 });
	ST* std4 = new ST({ "박성민",165,22 });

	pushHeap(std1);
	pushHeap(std2);
	pushHeap(std3);
	pushHeap(std4);

	while (ht.heap_size) {
		ST* s = popHeap();
		printf("%d %s %d\n", s->age, s->name, s->height);
	}

	
	//printf("%s %d %d\n", std1->name, std1->height, std1->age);
	return 0;
}