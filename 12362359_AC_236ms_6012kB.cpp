#include<bits/stdc++.h>

using namespace std;
vector<int>graph[100005];
int vis[20001];
int mp[20001];


int bfs(int n)
{
    queue<int>q;
    q.push(n);
    int lycan = 0 , vampire = 0 ;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0 ; i < graph[u].size(); i++ )
        {
            int x = graph[u][i];
            if(vis[x]==0)
            {
                if(vis[u]==1)
                {
                    vampire++;
                    vis[x]=2;
                }
                else
                {
                    lycan++;
                    vis[x]=1;
                }
                q.push(x);
            }
        }
    }
    return max(lycan,vampire);
}


int main()
{
    int t , n , u , v , i , j , ans;
    scanf("%d",&t);
    for( i = 1; i <= t ; i++ )
    {
        scanf("%d",&n);
        for( j = 1; j <=20001 ; j++)
            graph[j].clear();


        memset(vis,0,sizeof vis);
        memset(mp,0,sizeof mp);
        int cnt = 0;

        for(j=1; j<=n; j++)
        {
            scanf("%d%d",&u,&v);
            if(mp[u]==0)mp[u]=++cnt;
            if(mp[v]==0)mp[v]=++cnt;
            graph[mp[u]].push_back(mp[v]);
            graph[mp[v]].push_back(mp[u]);

        }
        ans = 0 ;
        for( j =1 ; j <=cnt ; j++)
        {
            if(vis[j]==0)
            {
                ans += bfs(j);
            }
        }
        printf("Case %d: %d\n",i,ans);
    }
}


