#include<bits/stdc++.h>
using namespace std;
int v[100009];
int main()
{
    long long i,j,k,t,n,q,A,B,s,cas,a;
    scanf("%lld",&t);
    for(cas=1; cas<=t; cas++)
    {
        scanf("%lld%lld",&n,&q);
        for(i=0; i<n; i++)
        {
            scanf("%lld",&v[i]);
                    }
        printf("Case %lld:\n",cas);
        for(j=1; j<=q; j++)
        {
            scanf("%lld%lld",&A,&B);
            long long lw=lower_bound (v, v+n, A)-v;
            long long hi=upper_bound (v, v+n, B)-v;
            printf("%lld\n",(hi-lw));
        }
    }
}
