#include<bits/stdc++.h>
 
#define  ll long long
 
 
using namespace std;
 
double  a[1000001];
 
void fac()
{
    for( ll i = 1 ; i<= 1000000 ;i++)
        a[i] = log(i) + a[i-1];
}
int main()
{
    fac();
    ll  cas = 1 , t , i , j , n , b ;
 
    scanf("%lld",&t);
    while( t-- )
    {
        scanf("%lld%lld",&n,&b);
        ll  x = a[n]/log(b);
 
        printf("Case %lld: %lld\n",cas++, x+1);
    }
}
 