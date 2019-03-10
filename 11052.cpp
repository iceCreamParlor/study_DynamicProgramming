#define MAX 1001
#include <cstdio>
#include <algorithm>

int main(){
  freopen("input.txt", "r", stdin);
  int num;  scanf("%d", &num);
  int a[MAX], dp[MAX] = {0};
  
  for(int i = 1 ; i <= num ; i++){
    int temp; scanf("%d", &temp);
    dp[i] = temp;
    a[i] = temp;
  }
  
  for(int i = 1 ; i <= num ; i++){
    for(int j = 1 ; j <= i ; j++){
      dp[i] = std::max(dp[i], dp[i-j] + a[j]);
    }
  }
  printf("%d\n", dp[num]);
  return 0;
}