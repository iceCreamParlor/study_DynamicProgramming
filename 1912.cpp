#define MAX 100001
#include <cstdio>
#include <vector>
using namespace std;

inline int max(int a, int b){
  return a > b ? a : b;
}

int main(){
  // freopen("input.txt", "r", stdin);
  int num;  scanf("%d", &num);
  vector<int> v;
  int dp[MAX] = {0};
  for(int i = 0 ; i < num ; i++){
    int temp; scanf("%d", &temp);
    v.push_back(temp);
  }
  dp[1] = v[0];
  for(int i = 2 ; i <= num ; i++){
    if(dp[i-1] + v[i-1] < v[i-1]){
      dp[i] = v[i-1];
    } else {
      dp[i] = dp[i-1] + v[i-1];
    }
  }
  int sum = -1000000000;
  for(int i = 1 ; i <= num ; i++){
    sum = max(sum, dp[i]);
  }
  printf("%d\n", sum);
  return 0;
}