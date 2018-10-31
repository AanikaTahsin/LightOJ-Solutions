#include<bits/stdc++.h>

using namespace std;

queue<pair<int,int> >q;

vector<int>graph[10001];

int vis[1001][10001];

int cnt[1001];

void bfs()
{
    while(!q.empty())
    {
        pair<int,int>u;
        u = q.front();
        q.pop();

        cnt[u.second]++;

        for(int i=0; i<graph[u.second].size(); i++)
        {
            int v = graph[u.second][i];

            if(!vis[u.first][v])
            {
                vis[u.first][v] = 1 ;

                q.push({u.first,v});
            }
        }
    }


}

int main()
{
    int t , k ,n, m, i , j,u , v;

    scanf("%d",&t);

    int cas = 1 ;
    while(t--)
    {
        scanf("%d%d%d",&k,&n,&m);
        memset(vis,0,sizeof vis);
        memset(cnt,0,sizeof cnt);

        for(i=1; i<=n; i++)
            graph[i].clear();

        for(i=1; i<=k; i++)
        {
            scanf("%d",&j);
            q.push({i,j});
            vis[i][j] = 1;
        }

        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }

        bfs();

        int tot = 0 ;
        for(i=1; i<=n; i++)
        {
            tot += cnt[i]==k;
        }

        printf("Case %d: %d\n",cas++,tot);
    }
}
