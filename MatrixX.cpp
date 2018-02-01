/*
	최후에는 항상 두 개의 항만 남아 있다. dp : dp[i][j] i행렬부터 j행렬까지 곱하는 데 생기는 최소 비용
	dp[i][i] = 0
	dp[i][j] =  min( dp[i][k-1] + dp[k][j] + row[i] * row[k] * col[j] ) -> k = i+1 에서 j까지
	row[i] : i 번째 행렬의 row값
*/
#include <cstdio>
#include <algorithm>
#define MAX 501

using namespace std;

int dp[MAX][MAX];
int row[MAX], col[MAX];

int main(){
	freopen("input.txt","r" , stdin);
	int num;
	scanf("%d", &num);
	
	for( int i=0 ; i< num ; ++i ){
		scanf( "%d %d", &row[i], &col[i] );
	}
	
	for( int i=0 ; i< num ; i++ ){
		for( int j=i ; j< num; ++j){
			if(i == j)
				dp[i][j] = 0;
			else if( col[i] == row[j] ){
				dp[i][j] = row[i] * col[i] * col[j];
			}
		}
	}
	
	for(int i=0 ; i< num ; ++i){
		for(int j=i ; j < num ; ++j){
			for( int k = i+1 ; k<j+1 ; ++k  ){
				dp[i][j] =  min( dp[i][k-1] + dp[k][j], row[i] * row[k] * col[j] );
			}
		}
	}

	

	return 0;
}