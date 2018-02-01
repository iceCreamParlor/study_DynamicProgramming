/*
틀렸음
dp[i][j][k]
i : 시점 j : 움직임 k : 현재 어디?
점화식 : dp[i][j][k] = max( dp[i-1][j][k] (전 기에 움직이지 않음), dp[i-1][j-1][k] (전 기에 움직임) )
*/
#include <cstdio>
#include <algorithm>
#define MAX 1001

using namespace std;
int A[MAX];
int dp[MAX][31][2];

int main(){
	freopen("input.txt", "r", stdin);
	int num; int cnt;
	scanf("%d %d", &num, &cnt);
	for( int i=0 ; i< num ; ++i ){
		scanf("%d", &A[i]);
		A[i] -= 1;
	}
	//시점 움직임 전 기에 어디?

	for( int i = 0 ; i< num ; ++i ){
		for(int j = 1 ; j<= cnt ; ++j){
			if( A[i] == 1 ){
				dp[i][j][1] = max( dp[i][j][1], dp[i-1][j][1] + 1);
				dp[i][j][1] = max( dp[i][j][1], dp[i-1][j-1][0] + 1);   
				dp[i][j][0] = max( dp[i][j][0], dp[i-1][j-1][1]);  
				dp[i][j][0] = max( dp[i][j][0], dp[i-1][j][0]);
			}
			else{
				dp[i][j][0] = max( dp[i][j][0], dp[i-1][j][0] + 1); 
				dp[i][j][0] = max( dp[i][j][0], dp[i-1][j-1][1] + 1);
				dp[i][j][1] = max( dp[i][j][0], dp[i-1][j-1][0] );
				dp[i][j][1] = max( dp[i][j][0], dp[i-1][j][1] );
			}
		}
	}
	int max_num = 0 ;
	for(int i=1 ; i<= cnt; ++i){
		for(int j=0 ; j < 2 ; ++j){
			if( max_num < dp[num-1][i][j] )
				max_num = dp[num-1][i][j];
		}
	}
	printf("%d", max_num);
	return 0;
}