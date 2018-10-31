#include<bits/stdc++.h>
 
using namespace std;
 
#define maxi 505
 
 
int cost[maxi][maxi],color[maxi][maxi];
int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};
char grid[maxi][maxi];
int xcell,ycell,dis=0;
 
 
int bfs(int i,int j)
{
    queue<int>q;
    int ui,uj,xi,yj,k;
 
    q.push(i);
    q.push(j);
 
    color[i][j] = 1;
    int tot = 0 ;
 
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
 
            if((xi>=1&&xi<=xcell) && (yj>=1&&yj<=ycell) && (grid[xi][yj]!='#'))
            {
                if(!color[xi][yj])
                {
                    color[xi][yj] = 1 ;
                    if(grid[xi][yj]=='C')
                        tot++;
                    q.push(xi);
                    q.push(yj);
                    color[xi][yj]=1;
                }
 
            }
        }
    }
    return tot ;
}
 
 
void fillbfs(int i,int j,int tot)
{
    queue<int>q;
    int ui,uj,xi,yj,k;
 
    q.push(i);
    q.push(j);
 
    cost[i][j] = tot;
 
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
 
            if((xi>=1&&xi<=xcell) && (yj>=1&&yj<=ycell) && (grid[xi][yj]!='#'))
            {
                if(cost[xi][yj]==-1)
                {
 
                    cost[xi][yj]=tot;
                    q.push(xi);
                    q.push(yj);
                }
            }
        }
    }
}
 
 
int main()
{
    int t,cas=1,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&xcell, &ycell, &q);
 
        int i , j , k ;
        for(i=1; i<=xcell; i++)
        {
            for(j=1; j<=ycell; j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }
 
        memset(color,0,sizeof color);
        memset(cost,-1,sizeof cost);
 
 
        printf("Case %d:\n",cas++);
        while(q--)
        {
            int x, y ;
            scanf("%d%d",&x,&y);
            if(cost[x][y]==-1)
            {
                int tot = bfs(x,y);
                fillbfs(x,y,tot);
            }
            printf("%d\n",cost[x][y]);
        }
    }
}
 
 