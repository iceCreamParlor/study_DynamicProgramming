#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAX 1000001

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int num; cin >> num;
  
  int dp[MAX];

  dp[1] = 0;
  dp[2] = 1; // divide by 2
  dp[3] = 1; // divide by 3

  for(int i = 4 ; i <= num ; i++){
    if(i%2 && i%3){
      // 모두 나누어지지 않으면, 1을 뺀다.
      dp[i] = dp[i-1] + 1;
    } else {

      if(i%2 == 0 && i%3 == 0){
        int min1 = dp[i-1] + 1;
        int min2 = dp[i/2] + 1;
        int min3 = dp[i/3] + 1;

        dp[i] = min(min(min2, min3), min1);

      } else if(i%2 == 0) {

        dp[i] = min(dp[i/2] + 1, dp[i-1]+1);

      } else if(i%3 == 0) {

        dp[i] = min(dp[i/3] + 1, dp[i-1]+1);

      }

    }
  }
  printf("%d\n", dp[num]);

  return 0;
}