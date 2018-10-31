#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll bigmod(ll b,ll p,ll m)
{
    if(p==0) return 1;
    else if(p%2==0) return bigmod(((b%m * b%m)%m),p/2,m);
    else return (b*(bigmod(b,p-1,m)%m));
}

int main()
{
    int t, cas =1 ;
    ll n , i , j , k, m ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld %lld",&n, &k, &m);

        ll sum = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&j);
            j %= m ;
            sum += j ;
            sum %= m ;
        }
        ll x = bigmod(n,k-1,m);
        sum *= x;
        sum %= m;
        k %= m;
        sum *= k ;
        sum %= m ;
        printf("Case %d: %lld\n",cas++, sum);
    }
}
