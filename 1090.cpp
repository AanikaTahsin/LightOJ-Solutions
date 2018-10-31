#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll trail(ll n,ll fact)
{
    ll sum=0;
    while (n)
    {
        sum+=n/fact;
        n/=fact;
    }
    return sum;
}
ll Divisor(ll n, ll r,ll p,ll q,ll x)
{
    ll ans = trail(n,x)-trail(r,x)-trail(n-r,x),s=0;
    while(p%x == 0)
    {
        s++;
        p/=x;
    }
    return ans+=s*q;
}
int main()
{
    ll i,j,n,t,r,p,q;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n>>r>>p>>q;
        ll k= min (Divisor(n, r, p,q,5),Divisor(n, r, p,q,2));
        printf("Case %lld: %lld\n",i,k);
    }
}
