#define MAX 10001
#include <cstdio>
#include <vector>
using namespace std;

inline int max(int a, int b, int c){
  return a > b ? a > c ? a : c : b > c ? b : c;
}

int main(){
  // freopen("input.txt", "r", stdin);
  int dp[MAX] = {0};
  int num;  scanf("%d", &num);
  vector<int> v;
  for(int i=0 ; i < num ; i++){
    int temp; scanf("%d", &temp);
    v.push_back(temp);
  }
  dp[1] = v[0];
  for(int i = 2 ; i <= num ; i++){
    dp[i] = max(dp[i-3] + v[i-2] + v[i-1], dp[i-1], dp[i-2] + v[i-1]);
  }
  printf("%d\n", dp[num]);

  return 0;
}