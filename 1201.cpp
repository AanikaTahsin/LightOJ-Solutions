/////      :)       ////
#include<bits/stdc++.h>

using namespace std;



vector<int>graph[1002];
pair<int,int>p[1001];


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

    for(int i=1; i<=n; i++)
    {
        memset(vis,0,sizeof vis);
        if(kuhn(i))
            cnt++;

    }

    return cnt;

}

int main()
{
    int t , i , j , cas =1,v ;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);

        for(i=1; i<=1001; i++)
            graph[i].clear();

        for(i=0; i<m; i++)
        {
            int u , v ;
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        printf("Case %d: %d\n",cas++,n-(bpm()/2));
    }

}

/*
1
1 2 5
m1 f1
m1 f1
m1 f2
f3 m1
f1 m1
*/