#include <stdio.h>
#define MAX 1000
// �⼮��

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
	ST *heap[MAX];		// heap���� student�� �ּҸ� �־�д�.
	int heap_size = 0;
}HeapType;

HeapType ht;			// min_heap���� ���� - ���� �������� root��

void pushHeap(ST *std) {	// �Ʒ��� ���� �ö󰡴� ���
	int i = ++ht.heap_size;
	while (i != 1 && ht.heap[i/2]->age>std->age) {	// ������ �� �������� ��� heap[i]�� ������.	
		ht.heap[i] = ht.heap[i / 2];				// -> �̷����ϸ� swap�ʿ����
		i /= 2;
	}
	ht.heap[i] = std;	// ������ i��ġ�� ã�Ƽ� �ֱ⸸�ϸ��
}

ST *popHeap() {		// �����Ÿ� ���� ���������� �������� ���
	ST* min = ht.heap[1];
	ST* tmp = ht.heap[ht.heap_size--];	// ht.heap[1]�� ���� �ٲ��� �ʾƵ� ���X
	int parent = 1, child = 2;			// heap[parent]�� �������ʰ� ����(tmp)�� ���ϱ� ����

	while (child <= ht.heap_size) {	// child�� ������ ����� �ʴ� ����
		if (child+1<=ht.heap_size&&ht.heap[child]->age > ht.heap[child + 1]->age)		// �ڽĵ� ���� �� ������ ���� ����
			child++;
		if (tmp->age < ht.heap[child]->age) {	// tmp�� ���۴ٸ� parent�ڸ��� �´��ڸ�
			break;
		}
		ht.heap[parent] = ht.heap[child];		// parent�� �� ũ�� parent�� child�����ϰ�
		parent = child;							// ������ ������
		child *= 2;
	}	
	ht.heap[parent] = tmp;		// ���ڸ��� parent�ڸ�
	return min;
}

int main() {
	ST* std1 = new ST({ "�迵��",170,26 });
	ST* std2 = new ST({ "������",174,28 });
	ST* std3 = new ST({ "���¿�",176,18 });
	ST* std4 = new ST({ "�ڼ���",165,22 });

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