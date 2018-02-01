#include <cstdio>
#include <algorithm>
#define MAX 501

using namespace std;

int map[MAX][MAX];
int check[MAX][MAX];
int result = 0;

void dfs( int j, int i, int y, int x ){
	if( j > x || i > y || j< 0 || i< 0)
		return;

	if(j==x && i==y){
		result++;
		return;
	}
	if(map[j][i+1] < map[i][j])
		dfs(j,i+1,y,x);
	if(map[j][i-1] < map[i][j] && i>2)
		dfs(j,i-1,y,x);
	if(map[j+1][i] < map[i][j])
		dfs(j+1,i,y,x);
	if(map[j-1][i] < map[i][j] && j > 2)
		dfs(j-1,i,y,x);
}

int main(){
	freopen("input.txt", "r", stdin);
	int x, y;
	scanf("%d %d", &y, &x);
	for(int j=0 ; j< y ; ++j){
		for(int i=0 ; i< x ; ++i){
			scanf("%d", &map[i][j]);
		}
	}
	dfs(0, 0, y, x);
	printf("%d", result);
	return 0;
}