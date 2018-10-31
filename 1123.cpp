#include<bits/stdc++.h>
#define MAXN 4*100000
using namespace std;
int pr[MAXN];
int ran[MAXN];
struct edge
{
    int u, v, w;
} ;
vector<edge>e,e1;
bool comp(edge q,edge p)
{
    return q.w < p.w;
}

int fin(int r)
{
    if(pr[r]==r)return r;
    return pr[r]=fin(pr[r]);
}
int mst(int n)
{
    sort(e.begin(), e.end(), comp);
    for (int i = 1; i <= n; i++)
        pr[i] = i,ran[i]=0;

    int cnt = 0, s = 0;
    e1.clear();
    for (int i = 0; i < e.size(); i++)
    {
        int u = fin(e[i].u);
        int v = fin(e[i].v);
        if (u != v)
        {
           pr[v]=u;
            cnt++;
            s += e[i].w;
            e1.push_back(e[i]);
            if(cnt==n-1)
                break;
        }

    }
    e.clear();
    e = e1 ;
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
        e.clear();
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d",&u,&v,&w);
            edge get;
            get.u = u;
            get.v = v;
            get.w = w;
            e.push_back(get);
            printf("%d\n",mst(n));
        }
    }
    return 0;
}
