#include <cstdio>
#include <algorithm>
#define MAX 301


using namespace std;
int A[MAX];
int dp[MAX];

int main(){
	freopen("input.txt", "r", stdin);
	int num, total=0;
	scanf("%d", &num);
	for(int i=0 ; i< num ; ++i){
		scanf("%d", &A[i]);
		total+=A[i];
	}
	//initialize
	dp[0] = 0;
	dp[1] = 0;
	
	if(num >1){
	for( int i=2 ; i< num ; ++i ){
			dp[i] = min( dp[i-2] ,dp[i-1] ) + min(A[i-2], min(A[i-1], A[i]));
			printf("%d ", dp[i]);
		}
	}
	
	return 0;
}
