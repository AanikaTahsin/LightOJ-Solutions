#include<bits/stdc++.h>
using namespace std;
int dp[101][101];
int main()
{
    int t,cas =1 ,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        string s , p ;
        s= " ";
        cin >> p;
        s += p;
        int n = s.length();
        for(i=n-1; i>=1; i--)
        {
            for(j=i+1; j<n; j++)
            {
                if(s[i]==s[j])
                    dp[i][j] = dp[i+1][j-1];
                else
                    dp[i][j] = min (dp[i+1][j],dp[i][j-1])+1;

            }
        }
        printf("Case %d: %d\n",cas++,dp[1][n-1]);
    }
}
