#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;



vector<int>graph[505];


int par[1001];
int vis[1001];

int n , m ,v,f;
struct st
{
    string x , y ;
} a[1001],b[1001];

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

    for(int i=1; i<=f; i++)
    {
        memset(vis,0,sizeof vis);
        if(kuhn(i))
            cnt++;

    }

    return cnt;

}

int main()
{
    int t , i , j , cas =1 ;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d",&n,&m,&v);
        string s , p;

        f=0, m = 0;

        for(i=1; i<=v; i++)
        {
            cin >> s >> p ;
            if(s[0]=='F')
            {
                f++;
                a[f].x=s;
                a[f].y = p;
            }
            else
            {
                m++;
                b[m].x=s;
                b[m].y=p;
            }

        }



        for(i=1; i<=501; i++)
            graph[i].clear();



        for(i=1; i<=f; i++)
        {
            for(j=1; j<=m; j++)
            {

                if((a[i].x==b[j].y || a[i].y==b[j].x)){
                     //   cout << "anika\n";
                    graph[i].push_back(j);
                }
            }
        }


        printf("Case %d: %d\n",cas++,v-bpm());
    }

}

/*
1
1 2 4
m1 f1
m1 f1
m1 f2
f2 m1

1
2 2 10
m1 f1
m2 f2
m1 f1
m2 f2
m1 f1
f1 m1
f2 m2
f1 m1
f2 m2
f1 m1
*/