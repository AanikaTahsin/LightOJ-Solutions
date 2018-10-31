#include<bits/stdc++.h>

using namespace std;

int a[55];
int b[55];

int dp[55][1001];

typedef long long ll ;

const ll mod = 1e8 + 7 ;

int n, k ;

ll ans_me(int i , ll sum)
{
    if(i > n)
        return 0 ;
    if(sum == k)
        return 1 ;
    if(dp[i][sum] != -1)
        return dp[i][sum];

    ll ret = 0;
    for(ll j = 0 ; j<=b[i] and j*a[i] + sum <= k ; j++)
        ret += ans_me(i+1,sum + a[i]*j), ret %= mod ;

    return dp[i][sum] = ret ;

}

int main()
{
    int t , cas = 1 , i , j ;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&k);

        for(i=0; i<n; i++)
            scanf("%d",&a[i]);

        for(i=0; i<n; i++)
            scanf("%d",&b[i]);

        memset(dp, -1 , sizeof dp);

        printf("Case %d: %lld\n",cas++, ans_me(0,0));
    }
}
