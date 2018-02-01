//11048

#include <cstdio>
#include <algorithm>
#define MAX 1001


using namespace std;

int map[MAX][MAX];
int dp[MAX][MAX];

int main(){

	freopen("input.txt","r", stdin);
	int x, y;
	scanf("%d %d", &y, &x);

	for(int i=0 ; i< y ; ++i){
		for(int j=0 ; j < x; ++j){
			scanf("%d", &map[i][j]);
		}
	}
	int xsum=0, ysum=0;
	for(int i=0 ; i< x; i++){
		xsum += map[0][i];
		dp[0][i] = xsum;
	}	
	for(int j=0 ; j< y ; j++){
		ysum += map[j][0];
		dp[j][0] = ysum;
	}
	for( int i= 1 ; i< y ; i++ ){
		for( int j= 1; j< x ; j++ ){
			dp[i][j] = max( dp[i-1][j] + map[i][j], dp[i][j-1] + map[i][j] );
		}
	}
	printf("%d", dp[y-1][x-1]);
	return 0;
}	
