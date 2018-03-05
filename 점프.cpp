// 시간 초과 발생
#include <stdio.h>
#define MAX 110

int result, num;
int map[MAX][MAX], dp[MAX][MAX];

void dfs(int row, int col){
	if( num < row  )	return;
	else if( num < col  )	return;
	else if( row < 1 )	return;
	else if( col < 1	)	return;
	else if( map[row][col] == 0){
		result++;
		return;
	}
	else{
		dfs( row + map[row][col], col );
		dfs( row, col + map[row][col] );
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(int i=1; i<= num; i++){
		for(int j=1; j<= num; j++){
			scanf("%d", &map[i][j]);
		}
	}
	dfs(1,1);
	printf("%d", result);
	return 0;
}
