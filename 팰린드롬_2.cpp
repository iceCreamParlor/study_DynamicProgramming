#include <stdio.h>
#include <vector>
#define MAX 2010

using namespace std;

int num;
short dp[MAX][MAX];
vector<int> myvec;

int go(int i, int j){
	if(i==j)	return 1;
	else if(i+1 == j){
		if(myvec[i] == myvec[j])	 return 1;
		else return 0;
	}

	if(dp[i][j] >= 0)	return dp[i][j]; // -> Memoization

	if (myvec[i] != myvec[j])	{
		return dp[i][j] = 0;
	}
	else return dp[i][j] = go(i+1, j-1);
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(int i=0; i<= num; i++){
		for(int j=0; j<= num; j++){
			dp[i][j] = -1;	
		}
	}
	for(int i=0; i< num; i++){
		int temp;	scanf("%d", &temp);
		myvec.push_back(temp);
	}
	int cnt;	scanf("%d", &cnt);
	for(int i=0; i< cnt; i++){
		int s, e;	scanf("%d %d", &s, &e);
		
		printf("%d\n", go(s-1, e-1));
	}
	return 0;
}
