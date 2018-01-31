#include <stdio.h>
#include <algorithm>
#include <iostream>
#define MAX 1001
using namespace std;

int A[MAX];
int dp[MAX] = {1, };
int dp2[MAX] = {1, };
int main(int argc, char *argv[])
{
	freopen("input.txt", "r", stdin);
	int num;
	scanf("%d", &num);
	for(int i=0; i< num ; i++){
		scanf("%d", &A[i]);
	}

	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				dp[i] = max( dp[i], dp[j]+1 );
			}
		}
	}
	int index, max1=0, max2=0;
	for(int i=0 ; i< num ; i++){
		if( max1 < dp[i] )
			max1 = dp[i];
	}
	for(int i=0 ; i< num ; i++){
		if( max1==dp[i] ){
			index = i;
			break;
		}
	}
	for (int i = num-1 ; i >= index; i--) {
		for (int j = num-2; j >= index; j--) {
			if (A[i] < A[j]) {
				dp2[j] = max( dp2[i]+1, dp2[j] );
			}
		}
	}
	for(int i=0 ; i< num ; i++){
		if( max2 < dp2[i] )
			max2 = dp2[i];
	}
	int result;

	printf("%d %d \n", max1, max2);
	cout << index << endl;
	result = max1+max2 -1;
	printf("%d", result);
	
	return 0;
}