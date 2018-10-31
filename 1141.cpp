#include<bits/stdc++.h>
using namespace std;
vector<int> g[1001];
/*
2
1 2
2 366
*/
bool a[1001];
 
void sieve()
{
    int n = 1001,m = sqrt(1001);
    for(int i =4; i<=n; i+=2)a[i]=1;
    for(int i=3; i<=m; i+=2)
    {
        for(int j =i*i; j<=n; j+=i)
            a[j]=1;
    }
}
void prime_fact()
{
    for(int i=2; i<=1000; i++)
    {
        int p = i ,d = 2,now =-1;
        if(a[i]==0)continue;
        while(p>1)
        {
            now = -1;
            while(p%d==0)
            {
                now = d;
                p/=d;
            }
            if(now>0)
                g[i].push_back(d);
            d++;
        }
    }
}
 
int cost[1005],vis[1001];
void bfs(int s, int d)
{
    memset(vis,0,sizeof vis);
    queue<int>q;
    q.push(s);
    cost[s]=0;
    vis[s]=1;
 
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int x = g[u][i]+u ;
            if(vis[x]||x>d)continue;
            vis[x]=1;
            cost[x]=cost[u]+1;
            if(x==d)return;
            q.push(x);
        }
    }
}
int main()
{
    sieve();
    prime_fact();
    int t ,s,d,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        memset(cost,-1,sizeof cost);
        scanf("%d%d",&s,&d);
        bfs(s,d);
        printf("Case %d: %d\n",cas++,cost[d]);
    }
}
 