#include <stdio.h>
#define Shark 0

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
int maxCnt = 0;
class fish;

bool inBoundary(int x, int y)
{
    if (x > 3 || y > 3 || x < 0 || y < 0)
        return 0;
    return 1;
}
/*
void swap(fish a, fish b)
{
    fish tmpF = a;
    a = b;
    b = tmpF;
}
*/
void Print(int map[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", map[i][j]);
        }
        puts("");
    }
    puts("");
}

class fish
{
public:
    int x = 0, y = 0, size = 0, dir = 0;

    void setFish(int ix, int iy, int isize, int idir)
    {
        x = ix;
        y = iy;
        size = isize;
        dir = idir;
    }
    /*
    void swap(int nextX, int nextY)
    {
        fish *ptmp = &fishArr[map[nextX][nextY]];
        fish tmp = fishArr[map[nextX][nextY]];
        ptmp->x = x;
        ptmp->y = y;
        ptmp->size = size;
        ptmp->dir = dir;
        x = tmp.x;
        y = tmp.y;
        size = tmp.size;
        dir = tmp.dir;
        map[x][y] = size;
        map[ptmp->x][ptmp->y] = ptmp->size;
    }
*/
    void swap(fish a, fish b, int tmpMap[4][4])
    {
        fish tmp = a;
        a = b;
        b = tmp;
        tmpMap[a.x][a.y] = a.size;
        tmpMap[b.x][b.y] = b.size;
    }

    bool move(int map[4][4])
    {
        int nextX = x + dx[dir];
        int nextY = y + dy[dir];
       
        if (!inBoundary(nextX, nextY)||map[nextX][nextY] == Shark)
        { // next pos is shark
            for(int i=1;i<=8;i++){
                dir = (dir + i) % 8;
                nextX=x+dx[dir];
                nextY=y+dy[dir];
                if(inBoundary(nextX,nextY)&&map[nextY][nextY]!=Shark){
                    map[x][y]=-1;
                    x = nextX;
                    y = nextY;
                    map[x][y] = size;
                    break;
                }
            }
            return 0;
        }
        else if (map[nextX][nextY] == -1)
        { // next pos is empty
            map[x][y] = -1;
            map[nextX][nextY] = size;
            x = nextX;
            y = nextY;
            return 0;
        }
        else
        { // next pos is fish
            return 1;
        }
    }
};

class shark
{
public:
    int x = 0, y = 0, size = 0, dir = 0;

    void init(int map[4][4],fish fishArr[16]){
        x=0;
        y=0;
        dir=fishArr[map[0][0]].dir;
        size=fishArr[map[0][0]].size;
        fishArr[map[0][0]].size = -1;
    }

    void move(int nextX,int nextY, int map[4][4]){
        map[x][y] = -1;
        x=nextX;
        y=nextY;
        size+=map[x][y];
        map[x][y]=0;
        maxCnt = maxCnt > size ? maxCnt : size;
    }
};

void dfs(int map[4][4], fish fishArr[16], shark s)
{
    shark sk = s;
    int nowMap[4][4];
    int moveMap[4][4];
    fish nowFish[16];
    fish moveFish[16];

    // map, fish 배열 복사
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++){
            nowMap[i][j] = map[i][j];
        }
    for (int i = 0; i < 16; i++)
        nowFish[i] = fishArr[i];

    // fish 이동
    for(int i=0;i<16;i++)
        nowFish[i].move(nowMap); 

    // 이동 후의 배열 복사
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++){
            moveMap[i][j] = nowMap[i][j];
        }
    for(int i=0;i<16;i++)
        moveFish[i]=nowFish[i];

    Print(map);

    for (int mv=-4;mv<=4;mv++)
    {
        if (mv == 0)
            continue;
        int nextX = s.x + dx[s.dir]*mv;
        int nextY = s.y + dy[s.dir]*mv;

        if (inBoundary(nextX, nextY) && map[nextX][nextY] > 0)
        {
            s.move(nextX, nextY, nowMap);
            dfs(nowMap, nowFish, s);
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    nowMap[i][j] = moveMap[i][j];
            for (int i = 0; i < 16; i++)
                nowFish[i] = moveFish[i];
        }
    }
}

int main()
{
    int fishSize, fishDir;
    int map[4][4];
    shark s;
    fish fishArr[16];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d %d", &fishSize, &fishDir);
            fishArr[fishSize].setFish(i, j, fishSize, fishDir - 1);
            map[i][j] = fishSize;
        }
    }

    s.init(map,fishArr);
    dfs(map,fishArr,s);

    printf("%d\n", maxCnt);

    return 0;
}