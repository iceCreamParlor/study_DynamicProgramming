#include <stdio.h>
#include <algorithm>
#define MAX 1010

using namespace std;
int map[MAX][MAX], dp[MAX][MAX];
int main()
{
	int row, col;
	scanf("%d %d", &row, &col);
	for(int i=1; i<= row; i++)
		for(int j=1; j<= col; j++)
			scanf("%d", &map[i][j] );
    
	for( int i=1; i<= row; i++ )
		dp[i][1] = dp[i-1][1] + map[i][1];
    
	for( int i=1; i<= col; i++ )
		dp[1][i] = dp[1][i-1] +map[1][i];
    
	for( int i=2; i<= row; i++ )
		for( int j=2; j<= col; j++ )
			dp[i][j] = max( dp[i-1][j] + map[i][j], dp[i][j-1] + map[i][j] );
		
	printf("%d", dp[row][col]);
	return 0;
}
