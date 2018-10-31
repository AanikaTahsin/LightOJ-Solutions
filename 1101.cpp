#include<bits/stdc++.h>

using namespace std;
#define mx 100005

int L[mx];
int dis[mx];
int cost[mx][20];
int P[mx][20];
int T[mx];

typedef pair<int,int> pii;

typedef pair<int,pii> pii1 ;

vector<pii>g[100005];

priority_queue<pii1,vector<pii1>, greater<pii1> > q;


int maxi,mini;

int fin(int u)
{
    if(T[u]==u)
        return u;
    return T[u]=fin(T[u]);
}

void gettree_bymst(int n)
{
    for(int i=1; i<=n; i++)
        T[i] = i ;
    while(!q.empty())
    {
        int u = q.top().second.first;
        int v = q.top().second.second;
        int w = q.top().first;
        int p = fin(u);
        int q1 = fin(v);
        q.pop();

        if(p!=q1)
        {
            //cout << u << " " << v << endl;
            T[p] = q1 ;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }

    }
}

void dfs(int from,int u,int dep)
{
    T[u]=from;
    L[u]=dep;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i].first;
        if(v==from)
            continue;
        dis[v] = g[u][i].second;
        dfs(u,v,dep+1);
    }
}

void lca_init(int N)
{
    memset (P,-1,sizeof(P));
    int i, j;
    for (i = 1; i <= N; i++)
    {
        P[i][0] = T[i];
        cost[i][0] = dis[i];
      //  cout << i << " "  << cost[i][0] << endl;
    }

    for(j = 1; 1 << j <= N; j++)
        for(i = 1; i <= N; i++)
            if (P[i][j - 1] != -1)
            {
                P[i][j] = P[P[i][j - 1]][j - 1];
                cost[i][j] = max(cost[i][j-1],cost[P[i][j-1]][j-1]);
            }
}



void lca_query(int N, int p, int q)
{
    int tmp, log, i;

    if (L[p] < L[q])
        swap(p,q);

    log = log2(L[p]);
    maxi = 0;
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
        {
            maxi = max(maxi,cost[p][i]);
            p = P[p][i];
        }

    if (p == q)
        return ;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
        {
            maxi = max(maxi,max(cost[p][i],cost[q][i]));
            p = P[p][i], q = P[q][i];
        }
    maxi = max(maxi,dis[p]);
    maxi = max(maxi,dis[q]);
}



int main()
{

    int t , n , que, u , m, v , w, i , j ;

    scanf("%d",&t);

    int cas = 1 ;


    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1; i<=n; i++)
            g[i].clear();

        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            q.push({w,{u,v}});
        }
        gettree_bymst(n);
        dfs(1,1,0);
        lca_init(n);

        scanf("%d",&que);
        printf("Case %d:\n",cas++);
        while(que--)
        {
            scanf("%d%d",&u,&v);
            lca_query(n,u,v);
            printf("%d\n",maxi);
        }
    }
}


