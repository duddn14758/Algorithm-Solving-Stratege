#include <stdio.h>
#define MAX 23

int map[20][20];
bool track[MAX];
int max = 0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int R,C;

void dfs(int x,int y, int cnt){
    track[map[x][y]]=1;
    cnt++;
    max = max > cnt ? max : cnt;
    for(int i=0;i<4;i++){
        int nextX=x+dx[i];
        int nextY=y+dy[i];
        if(nextX<R && nextY<C && nextX>=0 && nextY>=0 && !track[map[nextX][nextY]])
            dfs(nextX,nextY, cnt);
    }
    track[map[x][y]]=0;
    cnt--;
}

int main(){
    char buf[20];
    scanf("%d %d",&R,&C);
    for(int i=0;i<R;i++){
        scanf("%s",buf);
        for(int j=0;j<C;j++){
            map[i][j]=buf[j]-'A';
        }
    }
    dfs(0,0,0);
    printf("%d\n",max);    

    return 0;
}