#include <stdio.h>
 
int max(int a, int b)
{
    return a > b ? a : b;
}
 
int main(void){
    
    int N;
    int stair[305] = {};
    int Dp[305] = {};
    scanf("%d", &N);
 
    for (int i = 1; i <= N; i++)
        scanf("%d", &stair[i]);
 
    for (int i = 1; i <= 3 && i <= N; i++)
        if (i!=3)
            Dp[i] = Dp[i - 1] + stair[i];
        else
            Dp[i] = max(stair[i] + Dp[i - 2], stair[i] + stair[i - 1]);
 
    for (int i = 4; i <= N; i++)
        Dp[i]=max(stair[i] + Dp[i - 2], stair[i] + stair[i - 1] + Dp[i - 3]);
 
    printf("%d\n", Dp[N]);
 
}
