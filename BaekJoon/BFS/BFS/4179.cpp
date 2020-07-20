#include <stdio.h>
#define MAX 10000

int R,C;
char map[1000][1000];
bool Jvisited[1000][1000];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

template <typename T>
class Queue{
private:
    T queue[MAX];
    int head = 0;
    int tail = 0;
public:
    bool empty(){
        return head==tail;
    }
    void push(T a){
        queue[tail] = a;
        tail=(tail+1)%MAX;
    }
    T front(){
        return queue[head];
    }
    T pop(){
        T ret = queue[head];
        head=(head+1)%MAX;
        return ret;
    }
};

typedef struct position{
    int x, y;
}pos;

typedef struct inputq{
    int x, y, cnt;
}inq;

bool inBoundary(int x,int y){
    if(x>R-1 || y>C-1 || x<0 || y<0) return 0;
    return 1;
}

void Print(){
    printf("J movement\n");
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            printf("%d ",Jvisited[i][j]);
        }
        puts("");
    }
    puts("");

    printf("Fire movement\n");
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            printf("%c ",map[i][j]);
        }
        puts("");
    }
    puts("");
}

int bfs(inq J,pos F[],int size){
    Queue<inq> q;
    Queue<inq> fq;
    //printf("Ingress bfs %d %d %d\n",J.x,J.y,J.cnt);
    int cnt=-1;
    q.push(J);
    Jvisited[J.x][J.y]=1;
    for(int i=0;i<size;i++){
        fq.push({F[i].x,F[i].y,0});
        //printf("push (%d, %d)\n",F[i].x,F[i].y);
    }
    //printf("After Input Fire Queue\n");
    while(!q.empty()){
        int fcnt = fq.front().cnt;
        if(fcnt != cnt){
            // spread
            cnt++;
           // printf("Spread front.cnt : %d, cnt : %d\n",fq.front().cnt, cnt);
            while(!fq.empty() && fcnt==fq.front().cnt){
                inq fnow=fq.pop();
                //printf("(%d, %d), now.cnt : %d, fcnt : %d\n",fnow.x,fnow.y,fnow.cnt,fcnt);
                for(int i=0;i<4;i++){
                    int nextX=fnow.x+dx[i];
                    int nextY=fnow.y+dy[i];
                    if(inBoundary(nextX,nextY) && (map[nextX][nextY] == '.' || map[nextX][nextY] == 'J')){
                        map[nextX][nextY] = 'F';
                        fq.push({nextX,nextY,fnow.cnt+1});
                    }
                }
            }
        }
        //Print();
        
        inq now = q.pop();
        //printf("now : %d %d %d\n",now.x,now.y,now.cnt);
        //max=max>now.cnt?max:now.cnt;
        for(int i=0;i<4;i++){
            int nextX=now.x+dx[i];
            int nextY=now.y+dy[i];
            if(!inBoundary(nextX,nextY)){
                return now.cnt+1;
            }
            if(!Jvisited[nextX][nextY] && map[nextX][nextY] == '.'){
                Jvisited[nextX][nextY] = 1;
                q.push({nextX,nextY,now.cnt+1});
                //map[nextX][nextY]='J';
            }
        }
        //Print();
    }
    return -1;
}


int main(){
    char buf[1000];
    int size = 0;
    inq J;
    pos F[10000];

    scanf("%d %d",&R, &C);
    for(int i=0;i<R;i++){
        scanf("%s",buf);
        for(int j=0;j<C;j++){
            map[i][j]=buf[j];
            if(map[i][j]=='J'){
                J.x=i;
                J.y=j;
                J.cnt=0;
            }
            else if(map[i][j]=='F'){
                F[size].x=i;
                F[size].y=j;
                size++;
            }
        }
    }
    int ret = bfs(J,F,size);
    if(ret == -1){
        printf("IMPOSSIBLE\n");
    }
    else
        printf("%d\n",ret);

    return 0;
}