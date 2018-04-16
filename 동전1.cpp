#include <stdio.h>
#include <vector>
#define MAX 10010

int num, target;
int dp[MAX];
using namespace std;
vector<int> myvec;

int main()
{
	scanf("%d %d", &num, &target);
	for(int i=1; i<= num; i++){
		int temp; scanf("%d", &temp);
		myvec.push_back(temp);
	}
	dp[0]= 1;
	for(int i=0; i< num; i++){
		for(int j=0; j<= target; j++){
			if(myvec[i] <= j){
				dp[j] += dp[ j-myvec[i] ];
			}
		}
	}
	printf("%d", dp[target]);
	return 0;
}