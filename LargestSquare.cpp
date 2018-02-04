#include <stdio.h>
#define MAX 1001
unsigned long dp[MAX][MAX];

int main(int argc, char *argv[])
{
	freopen("input.txt", "r", stdin);
	int x, y;
	scanf("%d %d", &x, &y);
	
	dp[0][0] = dp[0][1] = 1;
	for(int i=1 ; i<= x ; i++){
		for(int j=0 ; j<= i ; j++){
			if (j==0 || j==x)
				dp[i][j] = 1;
			else{
				dp[i][j] = dp[i-1][j-1]  + dp[i-1][j] ;
			}
		}
	}
	printf("%d", dp[x-1][y] % 10007);
	return 0;
}
