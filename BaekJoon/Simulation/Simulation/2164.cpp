#include <stdio.h>
#define MAX 500000

template <typename T>
class Queue{
private:
    T arr[500000];
    int head = 0;
    int tail = 0;
    int size = 0;
public:
    bool emtpy(){
        return size-1;
    }
    void push(T a){
        arr[tail] = a;
        size++;
        tail = (tail+1)%MAX;        
    }
    T pop(){
        int ret = arr[head];
        size--;
        head = (head+1)%MAX;
        return ret;
    }
    void InitQ(int a){
        size = a;
        tail = a;        
        for(int i=0;i<a;i++){
            arr[i]=i+1;
        }
    }
};

int main(){
    int N;
    Queue<int> q;
    scanf("%d",&N);    
    q.InitQ(N);
    while(q.emtpy()){
        q.pop();
        q.push(q.pop());
    }
    printf("%d",q.pop());

    return 0;
}