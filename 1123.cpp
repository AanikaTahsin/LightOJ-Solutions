#include<bits/stdc++.h>
#define MAXN 4*100000
using namespace std;
int pr[MAXN];
struct edge
{
    int u, v, w;
}e[100005];
bool comp(edge q,edge p)
{
    return q.w < p.w;
}
int tot ;
int fin(int r)
{
    if(pr[r]==r)return r;
    return pr[r]=fin(pr[r]);
}
int mst(int n)
{
    sort(e,e+tot, comp);
    for (int i = 1; i <= n; i++)
        pr[i] = i;

    int cnt = 0, s = 0,ind=-1;
    for (int i = 0; i < tot; i++)
    {
        int u = fin(e[i].u);
        int v = fin(e[i].v);
        if (u != v)
        {
            pr[u] = v;
            cnt++;
            s += e[i].w;
        }
        else
            ind = i ;
    }
    if(ind != -1)
        e[ind] = e[--tot];
    if(cnt==n-1)
        return s ;
    else
        return -1;
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n, m,x;
        scanf("%d%d",&n,&m);
        printf("Case %d:\n",cas++);
        tot = 0 ;
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e[tot++]=get;
            printf("%d\n",mst(n));
        }
    }
    return 0;
}
