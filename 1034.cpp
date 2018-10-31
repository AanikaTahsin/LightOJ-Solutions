#include<bits/stdc++.h>
using namespace std;
vector<int>order,graph[123456];
bool vis[123456],vis1[123456];
void dfs(int x)
{
    vis[x] = true;
    for(int i=0; i<graph[x].size(); i++)
    {
        int u =graph[x][i];
        if(!vis[u])
        {
            dfs(u);
        }
    }
    order.push_back(x);
}
void check(int x)
{
    vis[x] = true;
    for(int i=0; i<graph[x].size(); i++)
    {
        int u =graph[x][i];
        if(!vis[u])
        {
            check(u);
        }
    }
}
int main()
{
    int i,j,k,m,u,v,n,t,cas=1;
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(vis,false,sizeof vis);
        for(i=1; i<=n; i++)graph[i].clear();
        for(i=0; i<m; i++)
        {
            scanf("%d%d",&u,&v);
            graph[u].push_back(v);
        }
        for(i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        int cnt=0;
        memset(vis,false,sizeof vis);
        reverse(order.begin(),order.end());
        for(i=0; i<order.size(); i++)
        {
            if(!vis[order[i]])
            {
                cnt++;
                check(order[i]);
            }
        }
        printf("Case %d: %d\n",cas++,cnt);
        order.clear();
    }
}
