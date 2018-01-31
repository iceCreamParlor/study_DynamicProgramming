#include <cstdio>
#include <algorithm>
#define MAX 1001

using namespace std;

int A[MAX] ;
int dp[MAX] ;

int main(){
	freopen("input.txt", "r", stdin);
	fill_n(dp, 1001, 1);
	int num;
	scanf("%d", &num);
	for( int i=0 ; i< num ; i++ ){
		scanf("%d", &A[i]);
	}

	for( int i= num-1 ; i>=0 ; --i ){
		for( int j= i-1 ; j>= 0 ; --j ){
			if( A[j] > A[i] ){
				dp[j] = max( dp[j], dp[i]+1 );
			}
		}
	}	
	
	int result = 0;
	for( int i=0 ; i< num ; ++i ){
		if( result < dp[i] )
			result = dp[i];
	}
	printf("%d", result);
	
	return 0;
}
