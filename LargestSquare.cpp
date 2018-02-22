#include <stdio.h>
#include <algorithm>
#define MAX 1001

int dp[MAX][MAX];
int map[MAX][MAX];
int main(int argc, char *argv[])
{
	freopen("input.txt", "r" ,stdin);
	
	int x, y;
	scanf("%d %d", &x, &y);

	for( int i=0 ; i< y ; i++ ){
		for( int j = 0 ; j< x; j++ ){
			scanf("%1d", &map[i][j] );	
		}
	}

	for (int i=0 ; i<y ; i++ )
	{
		dp[i][0] = map[i][0];
	}
	for (int i=0 ; i< x ; i++ )
	{
		dp[0][x] = map[0][i];
	}

	return 0;
}
