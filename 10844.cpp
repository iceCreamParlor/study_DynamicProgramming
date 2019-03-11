#include <cstdio>
#define MAX 101
#define divide 1000000000

using namespace std;

int main(){
  // freopen("input.txt", "r", stdin);
  int num;  scanf("%d", &num);
  int dp[MAX][10];

  dp[1][0] = 0;
  for(int i = 1 ; i < 10 ; i++){
    dp[1][i] = 1;
  }
  for(int i = 2 ; i <= num ; i++){
    for(int j = 0 ; j < 10 ; j++){
      if(j == 0){
        dp[i][j] = dp[i-1][j+1] % divide;
      } else if (j == 9){
        dp[i][j] = dp[i-1][j-1] % divide;
      }else {
        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % divide;
      }
    }
  }
  int result = 0;
  for(int i = 0 ; i < 10 ; i++){
    result = (result + dp[num][i]) % divide;
  }
  printf("%d\n", result);
  return 0; 
}