#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll tree[4*200001],lazy[4*200001];
void update(ll b , ll e, ll val , ll low, ll high, ll root)
{
    if(lazy[root]!=-1)
    {
        tree[root] = lazy[root];
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
        tree[root]=val;
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
}


ll que(ll qlow,ll qhigh,ll low,ll high , ll root)
{
    if(low>high)return 0;
    if(lazy[root]!=-1)
    {
        tree[root]=lazy[root];
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
    return max(p1,p2);
}



int main()
{
    ll n,i,j,k,l,x,y,t,q;
    ll cas=1;
    scanf("%lld",&t);
    while(t--)
    {
        memset(lazy,-1,sizeof lazy);
        memset(tree,0,sizeof tree);
        scanf("%lld",&n);
        for(i=1; i<=n; i++)
        {
            scanf("%lld%lld",&x,&y);
            update(x,y,i,1,2*n,1);
        }
        set<int>st;
        for(i=1; i<=n*2; i++)
        {
            x = que(i,i,1,n*2,1);
            //   cout << x << endl;
            if(x)
                st.insert(x);
        }
        printf("Case %lld: %lld\n",cas++,(ll)st.size());
    }
}
