#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 100000007;

ll n, k;

ll a[100005];
ll c[100005];
ll dp[100][1000];

int ans_me(ll i , ll sum)
{
    if(sum==k)
        return 1 ;
    if(i==n)
        return 0;

    if(dp[i][sum]!=-1)
        return dp[i][sum];

    ll ans = 0;
    for(ll j = 0 ; j<=c[i] && (j*a[i]+sum<=k); j++)
    {
        ans += ans_me(i+1,sum+j*a[i]);
        ans %= mod;
    }

    return dp[i][sum]=ans;
}


int main()
{
    int t, cas = 0 ;
    scanf("%d",&t);

    while(t--)
    {
        ll i , j ;

        memset(dp,-1,sizeof dp);

        scanf("%lld%lld",&n,&k);

        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        for(i=0; i<n; i++)
            scanf("%lld",&c[i]);

        printf("Case %d: %lld\n",++cas, ans_me(0,0));
    }
}
