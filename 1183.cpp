#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tree[4*200000],lazy[4*200000];
void update(ll b , ll e, ll val , ll low, ll high, ll root)
{
    if(lazy[root]!=-1)
    {
        tree[root] = lazy[root]*(high-low+1);
        if(low!=high)
        {
            lazy[2*root]=lazy[root];
            lazy[2*root +1]= lazy[root];
        }
        lazy[root]=-1;
    }
    if(b>high||e<low)return;
    if(b<=low&&e>=high)
    {
        tree[root]=(high-low+1)*val;
        if(low!=high)
        {
            lazy[2*root]=val;
            lazy[2*root+1]=val;
        }
        return;
    }
    ll mid = (low+high)/2;
    update(b,e,val,low,mid,2*root);
    update(b,e,val,mid+1,high,2*root +1);
    tree[root]=tree[2*root]+tree[2*root+1];

}


ll que(ll qlow,ll qhigh,ll low,ll high , ll root)
{
    if(low>high)return 0;
    if(lazy[root]!=-1)
    {
        tree[root]=(high-low+1)*lazy[root];
        if(low!=high)
        {
            lazy[2*root]=lazy[root];
            lazy[2*root+1]=lazy[root];
        }
        lazy[root]=-1;
    }
    if(qlow>high||qhigh<low)return 0;
    if(qlow<=low&&qhigh>=high)
        return tree[root];

    ll mid = (high+low)/2;
    ll p1 = que(qlow,qhigh,low,mid,2*root);
    ll p2 = que(qlow,qhigh,mid+1,high,2*root+1);
    return p1+p2;
}



int main()
{
    ll n,i,j,k,l,x,y,t,q;
    ll cas=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
      //  memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);
        memset(lazy,-1,sizeof lazy);
        printf("Case %lld:\n",cas++);
        ll type;
        while(q--)
        {
            ll l,r ,val;
            scanf("%lld",&type);
            if(type==2)
            {
                scanf("%lld%lld",&l,&r);
                l++,r++;
                ll ans = que(l,r,1,n,1);
                if(ans%(r-l+1))
                {
                    ll x = __gcd(ans,r-l+1);
                    ans /=x;
                    printf("%lld/%lld\n",ans,(r-l+1)/x);
                }
                else
                    printf("%lld\n",ans/(r-l+1));
            }
            else
            {
                scanf("%lld%lld%lld",&l,&r,&val);
                l++,r++;
                update(l,r,val,1,n,1);
            }
        }
    }
}
