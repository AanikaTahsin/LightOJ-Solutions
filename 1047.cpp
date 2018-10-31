#include<bits/stdc++.h>
using namespace std;
int grid[100][100],a[100][100];
int main()
{
    int t ,n,i,j,k,mn,cas=1;
    cin >> t ;
    while(t--)
    {
        cin  >> n ;
        memset(grid,0,sizeof grid);
        for(i=0; i<n; i++)
            for(j=0; j<3; j++)
                cin >> a[i][j];
        for(i=n-1; i>=0; i--)
        {
            for(int nw = 0 ; nw < 3; nw++)
            {
                mn = 1000000;
                for(j=0; j<3; j++)
                {
                    if(nw==j)
                        continue;
                    mn = min(mn,a[i][j]+grid[i+1][j]);
                }
                grid[i][nw]=mn ;
            }
        }
        int ans = min(grid[0][0],min(grid[0][1],grid[0][2]));
        printf("Case %d: %d\n",cas++,ans);
    }
}
