#include <stdio.h>
#define MAX 1001

int dp[MAX];
int main(int argc, char *argv[])
{
	int num;
	scanf("%d", &num);
	dp[0] = 1;
	dp[1] = 1;

	for( int i=2 ; i<= num ; i++ ){
		dp[i] = (dp[i-1] + dp[i-2]) % 10007;
	}
	printf("%d", dp[num]);

	return 0;
}
