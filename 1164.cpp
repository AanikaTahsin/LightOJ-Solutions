#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100001],tree[4*100001],lazy[4*100001];
void update(ll b , ll e, ll val , ll low, ll high, ll root)
{
    if(low>high)return;
    if(lazy[root]!=0)
    {
        tree[root]+=lazy[root]*(high-low+1);
        if(low!=high)
        {
            lazy[(root<<1)]+=lazy[root];
            lazy[(root<<1) +1]+=lazy[root];
        }
        lazy[root]=0;
    }
    if(b>high||e<low)return;
    if(b<=low&&e>=high)
    {
        tree[root]+=val*(high-low+1);
        if(low!=high)
        {
            lazy[(root<<1)]+=val;
            lazy[(root<<1)+1]+=val;
        }
        return;
    }
    ll mid = (low+high)/2;
    update(b,e,val,low,mid,(root<<1));
    update(b,e,val,mid+1,high,(root<<1) +1);
    tree[root]=tree[(root<<1)]+tree[(root<<1)+1];
}
ll que(ll qlow,ll qhigh,ll low,ll high , ll root)
{
    if(low>high)return 0;
    if(lazy[root]!=0)
    {
        tree[root]+=lazy[root]*(high-low+1);
        if(low!=high)
        {
            lazy[(root<<1)]+=lazy[root];
            lazy[(root<<1)+1]+=lazy[root];
        }
        lazy[root]=0;
    }
    if(qlow>high||qhigh<low)return 0;
    if(qlow<=low&&qhigh>=high)return tree[root];
 
    ll mid = (high+low)/2;
    ll p1 = que(qlow,qhigh,low,mid,(root<<1));
    ll p2 = que(qlow,qhigh,mid+1,high,(root<<1)+1);
    return p1+p2;
}
int main()
{
    ll t,n,q,q1,i,j,p,val,cm,cas=1;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q1);
        memset(arr,0,sizeof arr);
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        //init(1,1,n);
        printf("Case %lld:\n",cas++);
        for(i=1; i<=q1; i++)
        {
            scanf("%lld%lld%lld",&cm,&p,&q);
            p++,q++;
            if(cm==0)
            {
                scanf("%lld",&val);
                update(p , q , val , 1, n,1);
            }
            else printf("%lld\n",que(p,q,1,n,1));
        }
    }
}
 