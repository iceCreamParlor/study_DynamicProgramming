#include <stdio.h>
#define MAX 110

int num;
int map[MAX][MAX];
long long dp[MAX][MAX];
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(int i=1; i<= num; i++){
		for(int j=1; j<= num; j++){
			scanf("%d", &map[i][j]);
		}
	}
	dp[1][1] = 1;
	for( int i=1; i<= num ; i++ ){
		for( int j=1; j<= num; j++ ){
			if( i==1 && j==1 )	continue;
			for( int k=1; k< j; k++ ){
				if( k + map[i][k] == j ){
					dp[i][j] += dp[i][k];
				}
			}
			for( int k=1; k< i; k++ ){
				if( k + map[k][j] == i ){
					dp[i][j] += dp[k][j];
				}
			}
		}
	}
	printf("%lld", dp[num][num]);
	return 0;
}
