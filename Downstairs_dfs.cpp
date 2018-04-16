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
    if (dp[x][y] != -1) return dp[x][y]; //���� �̹� �ִ°�� �ǰ���������� �ִ°� ����
    if (x < 0 || x >= n || y < 0 || y >= m) return 0; //���� ��� ���� �Ұ����ϹǷ� 0����
    if (x == 0 && y == 0) return 1; //�������
 
    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + a[i];
        int nextY = y + b[i]; //�����¿� ��� �̵������ϹǷ�.
        
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