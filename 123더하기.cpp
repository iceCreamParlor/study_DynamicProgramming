#include <stdio.h>
#define MAX 12
int dp[MAX], num;
int main()
{
	freopen("input.txt", "r", stdin);
	dp[1]= 1; dp[2]= 2; dp[3]= 4;
	for( int i=4; i<= MAX; i++ )
		dp[i]= dp[i-1]+ dp[i-2]+ dp[i-3];
	scanf("%d", &num);
	for( int i=0; i<num; i++ ){
		int inp; scanf("%d", &inp);
		printf("%d\n", dp[inp] );
	}
	return 0;
}
