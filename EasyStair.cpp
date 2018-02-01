#include <cstdio>
#include <algorithm>
#define MAX 103 
#define mod 1000000000

using namespace std;
int dp[MAX][11];
int main(){
	int num, sum=0;
	scanf("%d", &num);
	
	//Initialize
	for(int i=1 ; i< 10 ; i++){
		dp[1][i]=1;
	}
	
	
	if(num > 1){
		for(int i=2 ; i< num+1 ; i++){
			for(int j=0 ; j<= 9 ; j++){
				if(j==0){
					dp[i][j] = dp[i-1][1] % mod;
				}
				else if(j==9){
					dp[i][j] = dp[i-1][8] % mod;
				}
				else{
					dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%mod;
				}
			}
		}
		
		for( int j = 0 ; j<= 9 ; j++  ){
			sum += dp[num][j] % mod;
		}
	printf("%d", sum%mod);
	
	}	
	return 0;
}	
