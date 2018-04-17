#include <cstdio>
#include <vector>
using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int num;  scanf("%d", &num);
  while(num--){
    vector<int> myvec;
    int dp[10010] = {0,};
    int many; scanf("%d", &many);
    for(int i=0; i<many; i++){
      int temp; scanf("%d", &temp);
      myvec.push_back(temp);
    }
    int total;  scanf("%d", &total);
    dp[0]=1;
    for(int j=0; j<myvec.size(); j++){
      for(int i=0; i<=total; i++){
        if(i>= myvec[j] )
          dp[i] += dp[i-myvec[j]];
      }
    }
    printf("%d\n", dp[total]);
  }
  return 0;
}
