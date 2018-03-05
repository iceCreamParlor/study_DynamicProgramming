#include <stdio.h>
#include <queue>
#define MAX 110
using namespace std;

struct space
{
	short row, col;
	space(short row, short col){
		this->row = row; this->col = col;
	}
};

queue<space> q;
int result, num;
short map[MAX][MAX];

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(short i=1; i<= num; i++){
		for(short j=1; j<= num; j++){
			scanf("%d", &map[i][j]);
		}
	}
	q.push(space(1,1));
	
	while(!q.empty()){
		space now = q.front();	q.pop();
		if( map[now.row][now.col] ==0 ){
			result++;
			continue;
		}
		if( now.row + map[now.row][now.col] <= num  ){
			space inp = space( now.row + map[now.row][now.col], now.col );
			q.push(inp);
		}
		if( now.col + map[now.row][now.col] <= num ){
			space inp = space( now.row, now.col + map[now.row][now.col] );
			q.push(inp);
		}
	}
	printf("%d", result);
	return 0;
}
