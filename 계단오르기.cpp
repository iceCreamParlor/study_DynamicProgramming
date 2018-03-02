#include <stdio.h>
#include <algorithm>
#define MAX 310
using namespace std;

int stair[MAX], dp[MAX];
/*
	oox
	dp[i] = dp[i-1]  1, 2
	oxo
	dp[i] = dp[i-2] + stair[i]; 1, 3 
	xoo
	dp[i] = dp[i-3] + stair[i-1] + stair[i];  2, 3

	dp[i] : i번째까지 올랐을 때 얻을 수 있는 최고 점수
*/
int main()
{
	freopen("input.txt", "r", stdin);
	int num; scanf("%d", &num);
	
	for( int i=1; i<= num; i++ ){
		int temp; scanf("%d", &temp);
		stair[i] = temp;
	}
	reverse( &stair[1], &stair[num]+1);
	
	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = stair[1] + stair[3];
	for( int i=4; i<= num; i++  ){
		dp[i] = max( dp[i-3] + stair[i-1] + stair[i], max(dp[i-1], dp[i-2] + stair[i]) );
	}
	printf("%d\n", dp[num]);
	
	for(int i=1; i<= num; i++)
		printf("%d ", dp[i]);
	
	return 0;
}
