#include<bits/stdc++.h>

using namespace std;
#define mx 100005
typedef long long ll;

ll L[mx];
ll dis[mx];
ll mxx[mx][17];
ll mxm[mx][17];
ll P[mx][17];
ll T[mx];

vector<pair<ll,ll> > g[100005];


ll maxi,mini;

void dfs(ll from,ll u,ll dep)
{
    T[u]=from;
    L[u]=dep;
    for(ll i=0; i<g[u].size(); i++)
    {
        ll v=g[u][i].first;
        if(v==from)
            continue;
        dis[v] = g[u][i].second;
       // cout << u << " " << v << " " << g[u][i].second << endl;
        dfs(u,v,dep+1);
    }
}

void lca_init(ll N)
{
    memset (P,-1,sizeof(P));
    ll i, j;
    P[1][0] = T[1];
    mxx[1][0] = 0;
    mxm[1][0] = 1e9;
    for (i = 2; i <= N; i++)
    {
        P[i][0] = T[i];
        mxx[i][0]=dis[i];
        mxm[i][0]=dis[i];
    }

    for(j = 1; 1 << j <= N; j++)
        for(i = 1; i <= N; i++)
            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                mxx[i][j]=max(mxx[i][j-1],mxx[P[i][j-1]][j-1]);
                mxm[i][j]=min(mxm[i][j-1],mxm[P[i][j-1]][j-1]);
            }
}



void lca_query(ll N, ll p, ll q)
{
    ll tmp, log, i;

    if (L[p] < L[q])
        swap(p,q);

    log = log2(L[p]);
    maxi = 0, mini = 1e9;

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
        {
            maxi = max(maxi,mxx[p][i]);
            mini = min(mini,mxm[p][i]);
            p = P[p][i];
        }

    if (p == q)
        return ;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {
            maxi = max(maxi,max(mxx[p][i],mxx[q][i]));
            mini = min(mini,min(mxm[p][i],mxm[q][i]));
            p = P[p][i], q = P[q][i];
        }
    maxi = max(maxi,dis[p]);
    maxi = max(maxi,dis[q]);
    mini = min(mini,dis[p]);
    mini = min(mini,dis[q]);
}



int main()
{

    ll t , n , q , u , v , w, i , j ;

    scanf("%lld",&t);

    int cas = 1 ;


    while(t--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
            g[i].clear();

        for(i=1; i<n; i++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        dfs(1,1,0);
        lca_init(n);

        scanf("%lld",&q);
        printf("Case %d:\n",cas++);
        while(q--)
        {
            scanf("%lld%lld",&u,&v);
            lca_query(n,u,v);
            printf("%lld %lld\n",mini,maxi);
        }
    }
}


