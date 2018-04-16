#include <stdio.h>

#define MAX 510
int r[4] = {0,0,+1,-1};
int c[4] = {1,-1,0,0};
int map[MAX][MAX], dp[MAX][MAX];
int row, col;		

int go(int i, int j){
	if( i== row-1 && j== col-1 )	return 1;
	if( dp[i][j] )	return dp[i][j];
	for(int k=0; k<4; k++){
		if( i + r[k] >= 0 && i+ r[k] < row && j + c[k] >= 0 && j+ c[k] <col ){
			if( map[i][j] > map[ i + r[k] ][ j + c[k] ]  ){ 
				dp[i][j] += go(i + r[k], j + c[k]  );
			}
		}
	}
	return dp[i][j];
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &row, &col);
	for(int i=0; i< row; i++){
		for(int j=0; j< col; j++){
			scanf("%d", &map[i][j]);
		}
	}
	printf("%d", go(0, 0));
	return 0;
}
