#define divide 10007
#define MAX 1001
#include <cstdio>

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int dp[MAX][10];
  int num;  scanf("%d", &num);

  for(int i = 0 ; i < 10 ; i++){
    dp[1][i] = 1;
  }
  for(int i = 2 ; i <= num ; i++){
    for(int j = 0 ; j < 10 ; j++){
      dp[i][j] = 0;
      for(int k = 0 ; k <= j ; k++){
        dp[i][j] += dp[i-1][k];
      }
      dp[i][j] %= divide;
    }
  }
  long long result = 0;
  for(int i = 0 ; i < 10 ; i++){
    result = (result + dp[num][i]) % divide;
  }
  printf("%lld\n", result);
  return 0;
}