#include<bits/stdc++.h>

using namespace std;

vector<int>graph[101];

int vis[101];
int cost[3][101];


void bfs(int s , int f)
{
    queue<int>q;

    q.push(s);
    vis[s] = 1;
    while(!q.empty())
    {

        int u = q.front();
        q.pop();

        for(int i=0; i<graph[u].size(); i++)
        {
            int v = graph[u][i];
            if(!vis[v])
            {
                q.push(v);
                cost[f][v]=cost[f][u]+1;
                vis[v] = 1 ;
            }
        }
    }
}


int main()
{
    int t ,i , j , k , cas = 0 ,n, m, s, d;

    cin >> t ;
    while(t--)
    {
        cin >> n >> m ;

        for(i=0; i<=n; i++)
            graph[i].clear();
        for(i=0; i<m; i++)
        {
            int u , v ;
            cin >> u >> v ;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        memset(vis,0,sizeof vis);
        memset(cost,0,sizeof cost);

        cin >> s >> d ;
        bfs(s,0);

        memset(vis,0,sizeof vis);

        bfs(d,1);

       // cout << cost[1][d] << endl;

        int sum = 0 ;
        for(i=0; i<n; i++)
        {
          //  cout << cost[0][i] << " " << cost[1][i] << endl;
            sum = max(sum,cost[0][i] + cost[1][i]);
        }
        printf("Case %d: %d\n",++cas, sum);
    }
}
