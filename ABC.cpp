#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int abc[3];  scanf("%d %d %d", abc, abc+1, abc+2);
  char trash; scanf("%c", &trash);
  char order[3];  scanf("%c%c%c", order, order+1, order+2);

  sort(abc, abc+3);
  for(int i=0; i<3; i++){
    if(order[i]=='A'){
      printf("%d ", abc[0]);
    }else if(order[i]=='B'){
      printf("%d ", abc[1]);
    }else if(order[i]=='C'){
      printf("%d ", abc[2]);
    }
  }
}
