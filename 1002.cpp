#include<bits/stdc++.h>
using namespace std;
map< int , vector< pair<int,int> > > rel;
map<int,int>parent;
int d[123456];
struct st
{
    int x,y,z;
};
vector<st>vc;
bool com(st a,st b)
{
    return a.z<b.z;
}
void init(int n)
{
    for(int i=0; i<n; i++)parent[i]=i;
    for(int i=0; i<n; i++)rel[i].clear();
    vc.clear();
}
int fin(int a)
{
    if(parent[a]==a)return a;
    return fin(parent[a]);
}
void bfs(int src)
{
    queue<int>Q;
    Q.push(src);
    d[src]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<rel[u].size(); i++)
        {
            int p=rel[u][i].first;
            int q = rel[u][i].second;
            if(d[p]== -1)
            {
                d[p]=max(d[u],q);
                Q.push(p);
            }
        }
    }
}
void mst()
{
    sort(vc.begin(),vc.end(),com);
    for(int i=0; i<vc.size(); i++)
    {
        int p=fin(vc[i].x);
        int q=fin(vc[i].y);
        if(p!=q)
        {
            //parent[p] = q;
            if(p<q)parent[q]=p;
            else parent[p]=q;
            rel[vc[i].x].push_back(make_pair(vc[i].y,vc[i].z));
            rel[vc[i].y].push_back(make_pair(vc[i].x,vc[i].z));
        }
    }
}
int main()
{
    int t,i,j,k=1,u,v,w,n,m,p;
    st a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        init(n);
        while(m--)
        {
            scanf("%d %d %d",&u,&v,&w);
            a.x=u;
            a.y=v;
            a.z=w;
            vc.push_back(a);
        }
        mst();
        cin >> p;
        memset(d,-1,sizeof d);
        bfs(p);
        printf("Case %d:\n",k++);
        for(i=0; i<n; i++)
        {
            if(d[i]!=-1)printf("%d\n",d[i]);
            else printf("Impossible\n");
        }
    }
}
