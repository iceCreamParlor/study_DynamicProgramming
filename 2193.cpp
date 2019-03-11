#include <cstdio>
#define MAX 92

using namespace std;

int main(){
  freopen("input.txt", "r", stdin);
  int num;  scanf("%d", &num);
  long long lastone[MAX], lastzero[MAX];
  lastone[1] = 1; lastzero[1] = 0;
  lastone[2] = 0; lastzero[2] = 1;

  for(int i = 3 ; i <= num ; i++){
    lastone[i] = lastzero[i-1];
    lastzero[i] = lastzero[i-1] + lastone[i-1];
  }
  printf("%lld\n", lastone[num] + lastzero[num]);

  return 0;
}