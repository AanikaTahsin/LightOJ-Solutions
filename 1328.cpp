#include<bits/stdc++.h>
#define ll long long
#define mod 1000007
using namespace std;
int main()
{
    ll t,i,j,n,k,c,a[123456],cas=1,x;
    cin >> t;
    while(t--)
    {
        cin >> k >> c >> n >> x;
        a[0]=x;
        for(i=1; i<n; i++)
        {
            a[i]=(a[i-1]*k+c)%mod;
        }
        sort(a,a+n);
        ll ans =0,sum=0;
        for(i=1; i<n; i++)
        {
            sum += a[i-1];
            ans += (a[i]*i)- sum ;
        }
        printf("Case %lld: %lld\n",cas++,ans);
    }
}
