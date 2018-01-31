#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100001
using namespace std;

int sticker[2][MAX];
int dp[MAX][3]; // dp: sticker [i] 행에서 선택하지 않거나, 위에 선택, 아래 선택

int main() {
 //freopen("input.txt", "r", stdin);
 int testcase; int n;
 scanf("%d", &testcase);

 for (int cnt = 0; cnt < testcase; ++cnt) {
	 scanf("%d", &n);
  for (int i = 0; i < 2; i++) {
   for (int j = 0; j < n; ++j) {
    scanf("%d", &sticker[i][j]);
   }
  }

  //초기화
  dp[0][0] = 0;
  dp[0][1] = sticker[0][0];
	dp[0][2] = sticker[1][0];
  //
  for (int j = 1; j < n; j++) {
   dp[j][0] = max(dp[j-1][1], dp[j-1][2]);  // 안뜯기
   dp[j][1] = max(dp[j-1][0] + sticker[0][j], dp[j-1][2] + sticker[0][j] );  // 위에 뜯기
   dp[j][2] = max(dp[j-1][0] + sticker[1][j] , dp[j-1][1] + sticker[1][j] );  // 아래 뜯기
  }

	int max = 0;
	for(int i=0 ; i<= 2 ; i++){
		for(int j=0; j< n; j++){
			if( max < dp[j][i] )
				max = dp[j][i];
		}
	}
	printf("%d\n", max);
 }
 return 0;
}