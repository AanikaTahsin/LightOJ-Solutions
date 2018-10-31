#include<bits/stdc++.h>
using namespace std;
map<int,int>parent;
struct st
{
    int x,y,z;
};
vector<st>vc,vc1;
bool com(st a,st b)
{
    return a.z<b.z;
}
void init(int n)
{
    for(int i=0; i<n; i++)parent[i]=i;
    vc.clear();
    vc1.clear();
}
int fin(int a)
{
    if(parent[a]==a)return a;
    return fin(parent[a]);
}
int mst(int n)
{
    for(int i=0; i<=n; i++)parent[i]=i;
    int cnt =0;
    for(int i=0; i<vc.size(); i++)
    {
        int p=fin(vc[i].x);
        int q=fin(vc[i].y);
        if(p!=q)
        {
            //parent[p] = q;
            if(p<q)parent[q]=p;
            else parent[p]=q;
            cnt+=vc[i].z;
        }
    }
    return cnt;
}
int main()
{
    int t,i,j,k=1,u,v,w,n,m,p,sum;
    st a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        init(n);
        sum=0;
        while(scanf("%d %d %d",&u,&v,&w)==3)
        {
            if(u==0&&v==0&&w==0)break;
            a.x=u;
            a.y=v;
            a.z=w;
            vc.push_back(a);
        }
        sort(vc.begin(),vc.end(),com);
        sum+=mst(n);
        reverse(vc.begin(),vc.end());
        sum+=mst(n);
        printf("Case %d: ",k++);
        if(sum%2==0)printf("%d\n",sum/2);
        else printf("%d/2\n",sum);
    }
}
