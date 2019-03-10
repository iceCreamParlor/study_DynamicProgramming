#define MAX 1001
#include <cstdio>

int main(){
  int dp[MAX];

  freopen("input.txt", "r", stdin);
  int num; scanf("%d", &num);
  
  dp[1] = 1;
  dp[2] = 3;
  for(int i = 3 ; i <= num ; i++){
    dp[i] = (dp[i-1] + dp[i-2]*2) % 10007;
  }
  printf("%d\n", dp[num]);
}