#include<bits/stdc++.h>

using namespace std;



vector<int>graph[1001];
pair<int,int>p[1001];


int par[1001];
int vis[1001];

int n , m ;

struct st
{
    int h,age,div;
} a[100],b[100];
bool kuhn(int u)
{
    for(int i = 0; i <graph[u].size(); i++)
    {
        int v = graph[u][i];

        if(vis[v])
            continue;
        vis[v]=1;

        if(par[v]==-1||kuhn(par[v]))
        {
            //cout << u << " " << v << " " << par[v] << endl;
            par[v]=u;
            return 1;
        }
    }
    return 0;
}

int bpm()
{

    memset(par,-1,sizeof par);

    int cnt = 0;

    for(int i=1; i<=m; i++)
    {
        memset(vis,0,sizeof vis);
        if(kuhn(p[i].second))
        {
            cnt++;
        }

    }

    return cnt;

}

int main()
{
    int t , i , j , cas =1 ;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d",&n,&m);



        for(i=1; i<=max(m,n); i++)
            p[i].second=i,p[i].first=0;

        for(i=1; i<=n; i++)
            scanf("%d%d%d",&a[i].h,&a[i].age,&a[i].div);


        for(i=1; i<=max(m,n); i++)
            graph[i].clear();

        for(i=1; i<=m; i++)
            scanf("%d%d%d",&b[i].h,&b[i].age,&b[i].div);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(abs(b[j].h-a[i].h)<=12 && abs(a[i].age-b[j].age)<=5&&(a[i].div==b[j].div))
                {
                    //cout << "anika\n";
                    graph[j].push_back(i),p[j].first++;
                }
            }
        }

        sort(p+1,p+m+1);

        printf("Case %d: %d\n",cas++,bpm());
    }

}

/*
2
2 2
70 30 0
60 20 0
71 25 0
71 35 0
*/