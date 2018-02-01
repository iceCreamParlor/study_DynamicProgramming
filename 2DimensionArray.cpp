#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#define MAX 301

using namespace std;
int A[MAX][MAX];
int dp[MAX][MAX];

int main() {
	int x, y;
	scanf("%d %d", &y, &x);
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	dp[0][0] = A[0][0];
	for (int i = 1; i < y; i++) {
		dp[i][0] = dp[i - 1][0] + A[i][0];
	}
	for (int j = 1; j < x; ++j) {
		dp[0][j] = dp[0][j - 1] + A[0][j];
	}
	for (int i = 1; i < y; i++) {
		for (int j = 1; j < x; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + A[i][j];
		}
	}

	int num, x1, x2, y1, y2, total=0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		
		if ( y1 < 2 && x1 >=2) {
			total = dp[y2 - 1][x2 - 1] - dp[y2 - 1][x1 - 2] ;
		}
		else if (y1 >= 2 && x1 < 2) {
			total = dp[y2 - 1][x2 - 1] - dp[y1 - 2][x2 - 1];
		}
		else if (y1 < 2 && x1 < 2) {
			total = dp[y2 - 1][x2 - 1];
		}
		else
			total = dp[y2-1][x2-1] - dp[y2-1][x1-2] - dp[y1-2][x2-1] + dp[y1-2][x1-2];
		printf("%d\n", total);
	}
	return 0;
}