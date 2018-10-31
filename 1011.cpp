#include<bits/stdc++.h>

using namespace std;

#define check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n|(1<<pos))

typedef long long ll;


ll dp[17][1<<17],n;
ll a[20][20];

ll ans_me(ll i , ll pos)
{
    if(dp[i][pos]!=-1)
        return dp[i][pos];
    if(i==n)
        return 0;
    ll sum = 0;
    for(ll j = 0 ; j <n ; j++)
    {
        if(check(pos,j))
            continue;

        sum = max(sum,a[i][j]+ans_me(i+1,Set(pos,j)));
    }
    return dp[i][pos] = sum ;
}


int main()
{
    ll i , j ,t, k ;
    scanf("%lld",&t);
    int cas = 1 ;

    while(t--)
    {
        scanf("%lld",&n);
        memset(dp,-1,sizeof dp);
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%lld",&a[i][j]);
        printf("Case %d: %lld\n",cas++,ans_me(0,0));
    }
}
