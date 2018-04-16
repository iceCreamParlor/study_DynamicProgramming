#include <cstdio>
#include <algorithm>
#define MAX 501

using namespace std;
int a[4] = { 1, 0, -1, 0 };
int b[4] = { 0, 1, 0, -1 };
int map[MAX][MAX];
int dp[MAX][MAX];

int dfs(int x, int y, n, m)
{
    if (dp[x][y] != -1) return dp[x][y]; //값이 이미 있는경우 또계산하지말고 있는값 리턴
    if (x < 0 || x >= n || y < 0 || y >= m) return 0; //범위 벗어난 경우는 불가능하므로 0리턴
    if (x == 0 && y == 0) return 1; //기저사례
 
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + a[i];
        int nextY = y + b[i]; //상하좌우 모두 이동가능하므로.
        
        if (map[nextX][nextY]>map[x][y])
            dp[x][y] += dfs(nextX, nextY, n, m);
    }
 
    return dp[x][y];
}



int main(){
	freopen("input.txt", "r", stdin);
	int x, y;
	scanf("%d %d", &y, &x);
	for(int j=0 ; j< y ; ++j){
		for(int i=0 ; i< x ; ++i){
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", dfs(x-1, y-1, x, y));
	return 0;
}