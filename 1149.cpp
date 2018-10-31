#include<bits/stdc++.h>

using namespace std;



vector<int>graph[1001];


int a[1001];
int b[1001];
int par[1001];
int vis[1001];

int n , m ;

bool kuhn(int u)
{
    for(int i = 0; i <graph[u].size(); i++)
    {
        int v = graph[u][i];

        if(vis[v])
            continue;
        vis[v]=1;

        if(par[v]==-1||kuhn(par[v]))
        {
            //cout << u << " " << v << " " << par[v] << endl;
            par[v]=u;
            return 1;
        }
    }
    return 0;
}

int bpm()
{

    memset(par,-1,sizeof par);

    int cnt = 0;

    for(int i=1; i<=m; i++)
    {
        memset(vis,0,sizeof vis);
        if(kuhn(i))
        {
            //cout << i << endl;
            cnt++;
            //break;
        }

    }

    return cnt;

}

int main()
{
    int t , i , j , cas =1 ;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=1; i<=n; i++)
            scanf("%d",&a[i]);

        scanf("%d",&m);

        for(i=1; i<=max(m,n); i++)
            graph[i].clear();

        for(i=1; i<=m; i++)
            scanf("%d",&b[i]);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(b[j]%a[i]==0)
                    graph[j].push_back(i);
            }
        }
        printf("Case %d: %d\n",cas++,bpm());
    }

}