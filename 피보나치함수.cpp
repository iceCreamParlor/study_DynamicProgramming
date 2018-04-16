#include <cstdio>

int main(){
  freopen("input.txt", "r", stdin);

  int num;  scanf("%d", &num);
  for(int i=0; i<num; i++){
    int dest; scanf("%d", &dest);
    int zero[41]={0,};
    int one[41]={0,};
    zero[0] = 1;
    one[0] = 0;
    zero[1]=0;
    one[1]=1;
    for(int k=2; k<=dest ; k++){
      zero[k] = zero[k-1] + zero[k-2];
      one[k] = one[k-1] + one[k-2];
    }
    printf("%d %d\n", zero[dest], one[dest]);
  }

  return 0;
}
