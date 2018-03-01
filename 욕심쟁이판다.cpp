
#include  <stdio.h>
int map[501][501];
int visit[501][501];
int N;
int max=0;
int vectX[4] = {0,1,0,-1};
int vectY[4] = {1,0,-1,0};
 
 
void dfsMap(int y, int x){
    int nextX,nextY;
    int value=0;
    for(int i=0;i<4;i++)
    {
        nextX=x+vectX[i];
        nextY=y+vectY[i];
         
        if(nextX>=N || nextX<0 || nextY>=N || nextY<0)
            continue;
        if(map[nextY][nextX] < map[y][x])
        {
            if(visit[nextY][nextX]==0)
                dfsMap(nextY,nextX);
             
            if(value<visit[nextY][nextX])
                value=visit[nextY][nextX];
        }
    }
    visit[y][x] = value+1;
     
    if(max<visit[y][x])
        max=visit[y][x];
}
 
int main(void)
{
    scanf("%d",&N);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",&map[i][j]);
 
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
        {
            if(visit[i][j]==0)
                dfsMap(i,j);
        }
    }
    printf("%d\n",max);
    return 0;
}
