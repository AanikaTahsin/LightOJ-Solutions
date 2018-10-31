#include<bits/stdc++.h>

using namespace std;

typedef long long ll ;

ll a[100005];
ll cnt[100005];


int main()
{
    int t , cas = 1 , n ;

     scanf("%d",&t);

     while(t--)
     {

         ll k ;
         scanf("%d %lld",&n,&k);
         memset(cnt,0,sizeof cnt);


         ll sum = 0 ;
         for(int i = 0 ; i < n ; i++)
         {
             scanf("%lld",a+i);
             sum += a[i] ;
             sum %= k ;
             cnt[sum]++;
         }

         ll ans = 0;
         cnt[0]++;
         for(ll i = 0 ; i < k ; i++)
         {
             //cout << cnt[i] << endl;
             ans += (cnt[i]* (cnt[i] -1) /2);
         }

         printf("Case %d: %lld\n",cas++,ans);
     }
}
