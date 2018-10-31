#include<bits/stdc++.h>
#define MAX 50005

#define ll long long

using namespace std;

int sum[MAX+1];
bool vis[MAX+1];
int graph[MAX+1];

int dfs(int src)
{
    int tot=0;
    vis[src]=true;
    if(graph[src]!=-1&&vis[graph[src]]==0)
        tot=1+dfs(graph[src]);

    vis[src]=false;
    sum[src]=tot;
    vis[src]=0;
    return tot;
}


int main()
{
    int t,n,u,v,i,j,cas=0;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(graph,-1,sizeof graph);
        for(i=0; i<n; i++)
        {
            scanf("%d%d",&u,&v);
            graph[u]=v;
        }
        memset(sum,-1,sizeof sum);
        int ans =0,maxi=-1;
        for(i=1; i<=n; i++)
        {
            if(sum[i]==-1)dfs(i);
            if(sum[i]>maxi)ans=i,maxi=sum[i];
        }
        
        printf("Case %d: %d\n",++cas,ans);
    }
}
