#include<bits/stdc++.h>
#define ll long long
#define maxi 1234567
using namespace std;
ll arr[200000],tree[4*200000];
void init(ll root,ll b,ll e )
{
    if(b==e)
    {
        tree[root]=arr[b];
        return;
    }
    ll left = root*2;
    ll right = root*2+1;
    ll mid = (b+e)/2;
    init (left,b,mid);
    init(right,mid +1, e);
    tree[root]= min(tree[left],tree[right]);
}
ll que(ll root , ll b, ll e, ll x , ll y)
{
    if(x>e||y<b)return maxi;
    if(b>=x&&e<=y)return tree[root];
    ll right = root*2 +1;
    ll left = root*2;
    ll mid = (b+e)/2;
    ll p1= que(left,b,mid,x,y);
    ll p2 = que(right,mid+1,e,x,y);
    return min(p1,p2);
}
int main()
{
    ll t,n,i,j,k,cas=1,q,a,b;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&q);
        memset(arr,0,sizeof arr);
        for(i=1; i<=n; i++)
        {
            scanf("%lld",&arr[i]);
        }
        init(1,1,n);
        printf("Case %d:\n",cas++);
        for(i=1; i<=q; i++)
        {
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",que(1,1,n,a,b));
        }

    }
}
