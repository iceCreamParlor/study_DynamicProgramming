#include <cstdio>
#define MAX 100001

int main(){
  int dp[MAX];int num;
  scanf("%d", &num);
  for(int i=0; i<=MAX; i++)
    dp[i] = 1234567;
  dp[0] = 0;
  for(int i=1; i<=num ; i++){
    if(i>=5){
      if(dp[i-2]==1234567 && dp[i-5]==1234567){
        ;
      }else{
        dp[i] = dp[i-2] > dp[i-5] ? dp[i-5]+1 : dp[i-2]+1;
      }
    }else if(i>=2){
      if(dp[i-2]==1234567){
        ;
      }else{
        dp[i] = dp[i-2]+1;
      }
    }
  }
  if(dp[num]==1234567)
    printf("-1");
  else
    printf("%d", dp[num]);
  return 0;
}
