#include<bits/stdc++.h>

using namespace std;
typedef long long ll ;
int main()
{
    int t , i , j, cas = 1 ;
    scanf("%d",&t);
    while( t -- )
    {
        ll n , k ;
        scanf("%llu%llu",&n,&k);
        ll ans = 1 ;
        for( i = 1 ; i <= k ; i++)
        {
            ans = (ans * n*n)/i;
            n--;
        }
        printf("Case %d: %llu\n",cas++,ans);
    }
}
