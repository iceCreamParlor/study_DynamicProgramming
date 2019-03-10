#define MAX 1001
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int num; scanf("%d", &num);

  int dp[MAX];
  dp[1] = 1;
  dp[2] = 2;

  for(int i = 3 ; i <= num ; i++){
    dp[i] = (dp[i-1] + dp[i-2]) % 10007;
  }
  printf("%d\n", dp[num]);
  return 0; 
}