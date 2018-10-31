#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
char s[61] ;
ll n,dp[61][61];
ll ans_me(ll i, ll j)
{
    if(i>j)
        return 0;
    if( i == j)
        return 1 ;
    if(dp[i][j]!=-1)
        return dp[i][j];

    dp[i][j] = ans_me(i+1,j)+ans_me(i,j-1) - ans_me(i+1,j-1);
    if(s[i]==s[j])
       dp[i][j] += ans_me(i+1,j-1)+1;
    return dp[i][j];

}

int main()
{
    ll t , i , j , cas = 1 ;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%s",s);
        n = strlen(s)-1;
        memset(dp,-1,sizeof dp);
        printf("Case %lld: %lld\n",cas++,ans_me(0,n));
    }
}
