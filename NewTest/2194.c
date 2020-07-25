#include <stdio.h>

int N,M;
int A,B;
int K;
typedef struct posision{
    int x, y;
}pos;

typedef struct rectangle{
    pos lt,rt,lb,rb;
}rec;

rec *wall = NULL;

int checkPos(pos p){
   if(p.x); 
}

int isIncluded(int x,int y){
    for(int i=0; i<K;i++){
    }
}

int main(){
    scanf("%d %d %d %d %d",&N,&M,&A,&B,&K);
    wall = (rec*)malloc(sizeof(rec)*K);

    for (int i = 0; i < K; i++)
    {
        scanf("%d %d", &wall[i].lt.x, &wall[i].lt.y);
        wall[i].lb.x = wall[i].lt.x + 1;
        wall[i].lb.y = wall[i].lt.y;
        wall[i].rt.x = wall[i].lt.x;
        wall[i].rt.y = wall[i].lt.y + 1;
        wall[i].rb.x = wall[i].lt.x + 1;
        wall[i].rb.x = wall[i].lt.x + 1;
    }

    return 0;
}