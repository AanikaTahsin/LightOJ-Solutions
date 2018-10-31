#include<bits/stdc++.h>

using namespace std;

#define ll long long
const int mod = 1e9+7;

ll fac[2000001];
ll ifac[1000001];

ll pow(ll a, ll b, ll MOD)
{
    if(b==0)
        return 1;
    ll x = pow(a,b/2,mod);
    x = (x*x)%mod;
    return (b%2==0)?x:(a*x)%mod;
}

ll modInverse(ll a, ll m)
{
    return pow(a,m-2,m);
}

void pre()
{
    fac[0]=1;
    for(ll i = 1 ; i<=2000000; i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
    }
    ifac[0]=1;
    for(ll i=1; i<=1000000; i++)
    {
        ifac[i] = (ifac[i-1]*modInverse(i,mod))%mod;
    }
}

int main()
{
//    freopen("in2.txt","r",stdin);
//    freopen("out2.txt","w",stdout);
    pre();
    ll t ;
    scanf("%lld",&t);
    int cas = 1 ;
    //assert( 1 <= t <= 100000 );
    while(t--)
    {
        ll n, r;
        scanf("%lld%lld",&n,&r);
        ll x = (n+r-1);
        ll ans ;
        ans = ((fac[x]*ifac[n])%mod *(ifac[r-1]))%mod;
        printf("Case %d: %lld\n",cas++,ans);
    }
}

