#include<bits/stdc++.h>
using namespace std;
#define maxi 300
int cost[maxi][maxi],color[maxi][maxi];
int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};
char grid[maxi][maxi];
int xcell,ycell,dis=0;
void bfs(int i,int j,int m, int l)
{
    memset(cost,0,sizeof(cost));
    memset(color,0,sizeof(color));
 
    queue<int>q;
    int ui,uj,xi,yj,k;
 
    q.push(m);
    q.push(l);
 
    cost[m][l] = 0;
    color[m][l] = 1;
 
    while(!q.empty())
    {
 
        ui = q.front();
        q.pop();
 
        uj = q.front();
        q.pop();
        for(k=0; k<4; k++)
        {
            xi = ui+fx[k];
            yj = uj+fy[k];
 
            if((xi>=1&&xi<=xcell) && (yj>=1&&yj<=ycell) && (grid[xi][yj]!='m')&&(grid[xi][yj]!='#'))
            {
                if(!color[xi][yj])
                {
                    q.push(xi);
                    q.push(yj);
                    cost[xi][yj] = cost[ui][uj]+1;
                    color[xi][yj]=1;
                }
 
            }
        }
    }
}
 
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,k,m,n,flag,x,y,l,no;
        scanf("%d%d",&xcell,&ycell);
        flag=0,x=0,y=0,k=0,l=0,no=1;
        for(i=1; i<=xcell; i++)
        {
            for(j=1; j<=ycell; j++)
            {
                scanf(" %c",&grid[i][j]);
                if(grid[i][j]=='h')
                    k=i,l=j;
            }
        }
        bfs(x,y,k,l);
        int mi=0;
        for(i=1; i<=xcell; i++)
        {
            for(j=1; j<=ycell; j++)
            {
                if(grid[i][j]=='a')mi=max(mi,cost[i][j]);
                else if(grid[i][j]=='b')mi=max(mi,cost[i][j]);
                else if(grid[i][j]=='c')mi=max(mi,cost[i][j]);
            }
        }
 
        printf("Case %d: %d\n",cas,mi);
        cas++;
    }
}
 