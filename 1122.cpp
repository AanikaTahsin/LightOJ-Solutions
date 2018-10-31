#include<bits/stdc++.h>

using namespace std;

int dp[20][20];

int a[14],n,m;

int DP(int j, int cnt)
{
    if(cnt+1==m)
        return 1 ;


    if(dp[j][cnt]!=-1)
        return dp[j][cnt];
    int ans = 0 ;
    for(int i=1; i<=n; i++)
    {
        int x = abs(a[j]-a[i]);
        if(x<=2)
            ans += DP(i,cnt+1);
    }
    return dp[j][cnt] = ans ;
}


int main()
{
    int i , j , ans ;

    int t , cas = 1 ;

    cin >> t ;

    while(t--)
    {
        cin >> n >> m ;
        memset(a,0,sizeof a);
        for(i=1; i<=n; i++)
            cin >> a[i];
        memset(dp,-1,sizeof dp);
        ans = 0;
        for(i=1; i<=n; i++)
        {
            ans += DP(i,0);
        }

        printf("Case %d: %d\n",cas++,ans);
    }
}
