#include<bits/stdc++.h>

using namespace std;

typedef long long ll ;

ll a[200+10];
ll dp[201][201][11];

ll n , M , d ;


ll ans_me(ll i, ll sum , ll m)
{
    if(m==M)
        return sum == 0;
    if(i==n)
        return 0;
    if(dp[i][sum][m]!=-1)
        return dp[i][sum][m];
    return dp[i][sum][m] = ans_me(i+1, sum%d, m) + ans_me(i+1 , (sum + a[i]) %d ,  m+1);
}

int main()
{

    int t , cas = 1 ;

    scanf("%d",&t);

    while(t--)
    {
        ll i, q ;
        scanf("%lld %lld",&n,&q);


        for(i=0; i<n; i++)
            scanf("%lld",a+i);

        printf("Case %d:\n",cas++);

        while(q--)
        {
            scanf("%lld %lld",&d,&M);
            memset(dp,-1,sizeof dp);

            printf("%lld\n",ans_me(0,0,0));
        }

    }
}
