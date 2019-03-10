#include <cstdio>
#define MAX 12

int main(){
  // freopen("input.txt", "r", stdin);
  int num;  scanf("%d", &num);

  while(num--){
    int target; scanf("%d", &target);
    int dp[MAX] = {0};
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3 ; i <= target ; i++){
      dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    printf("%d\n", dp[target]);
  }
  
  return 0;
}