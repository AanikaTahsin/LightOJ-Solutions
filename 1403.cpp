#include<bits/stdc++.h>

using namespace std;



vector<int>graph[1002];

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
            //graph[v].push_back(u);
        }

        int x = bpm();
        //x/=2;

        printf("Case %d: %d\n",cas++,n-x);
    }

}

/*
3

4 3
3 4
1 3
2 3


3 3
1 2
2 3
1 3

5 4
1 2
1 3
2 4
2 5

*/