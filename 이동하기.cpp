#include <stdio.h>
#include <algorithm>
#define MAX 1010
// dp 사용할 때에는 예외 처리 하기 귀찮을 때가 있어서 인덱스를 1부터 하는 경우가 많다. (0에는 항상 0이 들어가 있으니까)
using namespace std;
int map[MAX][MAX], dp[MAX][MAX];
int main()
{
	freopen("input.txt","r",stdin);
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
		
	printf("%d\n", dp[row][col]);
	return 0;
}
