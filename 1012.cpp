#include<bits/stdc++.h>
using namespace std;
#define maxi 50
int cost[maxi][maxi],color[maxi][maxi];
int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};
char grid[maxi][maxi];
int xcell,ycell,dis=0;
void bfs(int i,int j)
{
    memset(cost,0,sizeof(cost));
    memset(color,0,sizeof(color));

    queue<int>q;
    int ui,uj,xi,yj,k;

    q.push(i);
    q.push(j);

    cost[i][j] = 0;
    color[i][j] = 1;

    while(!q.empty())
    {

        ui = q.front();
        q.pop();

        uj = q.front();
        q.pop();

        dis++;


        for(k=0; k<4; k++)
        {
            xi = ui+fx[k];
            yj = uj+fy[k];

            if((xi>=1&&xi<=ycell) && (yj>=1&&yj<=xcell) && (grid[xi][yj]!='#'))
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
    q.pop();

}

int main()
{
    int i,j,k,m,n,flag,cas;
    scanf("%d",&cas);
    for(k=1; k<=cas; k++)
    {
        scanf("%d%d",&xcell,&ycell);
        for(i=1; i<=ycell; i++)
        {
            for(j=1; j<=xcell; j++)
            {
                scanf(" %c",&grid[i][j]);
            }
        }
        dis=0, flag=0;
        for(i=1; i<=ycell; i++)
        {
            for(j=1; j<=xcell; j++)
            {
                if(grid[i][j]=='@')
                {
                    bfs(i,j);
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        printf("Case %d: %d\n",k,dis);
    }
}
