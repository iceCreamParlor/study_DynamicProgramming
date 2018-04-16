#include <cstdio>
#include <algorithm>
#define MAX 501

using namespace std;

int map[MAX][MAX];
int dp[MAX][MAX][4];

int main(){
	freopen("input.txt", "r", stdin);
	int x, y;
	scanf("%d %d", &y, &x);
	for(int j=0 ; j< y ; ++j){
		for(int i=0 ; i< x ; ++i){
			scanf("%d", &map[i][j]);
		}
	}
	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	dp[0][0][2] = 0;
	dp[0][0][3] = 0;
	for( int i=0 ; i < y ; ++i )
	{
		for(int j=0 ; j< x ; ++j){
			if(i==0 && j ==0){
					
			}
			else if(i==0 && j >0 && j<x-1){
				if( map[i][j-1] > map[i][j] ){ // left -> right
					dp[i][j][3] = dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][3] +1;
				}
				if( map[i][j+1] > map[i][j] ){ // right -> left
					dp[i][j][2] = dp[i][j+1][0]+dp[i][j+1][1]+dp[i][j+1][2]+dp[i][j+1][3] +1;
				}
				if(map[i+1][j] > map[i][j]){ // down -> up
					dp[i][j][0] = dp[i+1][j][0]+dp[i+1][j][1]+dp[i+1][j][2]+dp[i+1][j][3]+1;
				}
			}
			else if(i==0 && j == x-1){
				if( map[i][j-1] > map[i][j] ){ // left -> right
					dp[i][j][3] = dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][3]+1;
				}
				if(map[i+1][j] > map[i][j]){ //down -> up
					dp[i][j][0] = dp[i+1][j][0]+dp[i+1][j][1]+dp[i+1][j][2]+dp[i+1][j][3]+1;
				}
			}
			else if(i>0 && i<y-1 && j==0){
				if( map[i][j+1] > map[i][j] ){ // right -> left
					dp[i][j][2] = dp[i][j+1][0]+dp[i][j+1][1]+dp[i][j+1][2]+dp[i][j+1][3]+1;
				}
				if(map[i+1][j] > map[i][j]){ // down -> up
					dp[i][j][0] = dp[i+1][j][0]+dp[i+1][j][1]+dp[i+1][j][2]+dp[i+1][j][3]+1;
				}
				if(map[i-1][j] > map[i][j]){ // up -> down
					dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3]+1;
				}
			}
			else if(i>0 && i<y-1 && j>0 && j <x-1){
				if( map[i][j+1] > map[i][j] ){ // right -> left
					dp[i][j][2] = dp[i][j+1][0]+dp[i][j+1][1]+dp[i][j+1][2]+dp[i][j+1][3]+1;
				}
				if(map[i+1][j] > map[i][j]){ // down -> up
					dp[i][j][0] = dp[i+1][j][0]+dp[i+1][j][1]+dp[i+1][j][2]+dp[i+1][j][3]+1;
				}
				if(map[i-1][j] > map[i][j]){ // up -> down
					dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3]+1;
				}
				if( map[i][j-1] > map[i][j] ){ // left -> right
					dp[i][j][3] = dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][3]+1;
				}
			}
			else if(i>0 && i<y-1 && j==x-1){
				if(map[i+1][j] > map[i][j]){ // down -> up
					dp[i][j][0] = dp[i+1][j][0]+dp[i+1][j][1]+dp[i+1][j][2]+dp[i+1][j][3]+1;
				}
				if(map[i-1][j] > map[i][j]){ // up -> down
					dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3]+1;
				}
				if( map[i][j-1] > map[i][j] ){ // left -> right
					dp[i][j][3] = dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][3]+1;
				}
			}
			else if(i==y-1 && j==0){
				if(map[i-1][j] > map[i][j]){ // up -> down
					dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3]+1;
				}
				if( map[i][j+1] > map[i][j] ){ // right -> left
					dp[i][j][2] = dp[i][j+1][0]+dp[i][j+1][1]+dp[i][j+1][2]+dp[i][j+1][3]+1;
				}
			}
			else if(i==y-1 && j>0 && j<x-1){
				if( map[i][j+1] > map[i][j] ){ // right -> left
					dp[i][j][2] = dp[i][j+1][0]+dp[i][j+1][1]+dp[i][j+1][2]+dp[i][j+1][3]+1;
				}
				if(map[i-1][j] > map[i][j]){ // up -> down
					dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3]+1;
				}
				if( map[i][j-1] > map[i][j] ){ // left -> right
					dp[i][j][3] = dp[i][j-1][0]+dp[i][j-1][1]+dp[i][j-1][2]+dp[i][j-1][3]+1;
				}
			}
			else if(i==y-1 && j==x-1){
				if(map[i-1][j] > map[i][j]){ // up -> down
					dp[i][j][1] = dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2]+dp[i-1][j][3]+1;
				}
				if( map[i][j+1] > map[i][j] ){ // right -> left
					dp[i][j][2] = dp[i][j+1][0]+dp[i][j+1][1]+dp[i][j+1][2]+dp[i][j+1][3]+1;
				}
			}
			else{
				printf("Exception Occured at map[%d][%d]\n", i, j);
			}
		}
	}
	int result = dp[y-1][x-1][1] + dp[y-1][x-1][3];
	printf("%d\n", result);
	printf("%d %d %d %d\n", dp[0][2][0], dp[0][2][1],dp[0][2][2],dp[0][2][3]);
	return 0;
}

