#include<cstdio>
 
using namespace std;
 
int a[2001];
bool dp[5001][5001];
 
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    
    for(int i=1; i<=n; i++)
    {
        dp[i][i]= true;	// ���� 1�ΰ�
        if(i+1<=n)
        {
            if(a[i+1] == a[i])
                dp[i][i+1] = true;	// ���� 2�ΰ�
        }
    }
 
    for(int k=3; k<=n; k++)	// ���� 3 �̻�
    {
        for(int i=1; i<=n-k+1; i++)
        {
            int j = i+k-1;
            if(a[i] == a[j] && dp[i+1][j-1])
                dp[i][j] = true;    
        }
    }
 
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        printf("%d\n",dp[t1][t2]);
    }
    return 0;
}


