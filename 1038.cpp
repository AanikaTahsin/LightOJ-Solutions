#include<bits/stdc++.h>

using namespace std;



typedef double ld;

const int sz = 200005;

ld dp[sz+5];

vector<int>v[sz+5];

void pre()
{
    for(int i = 2 ; i<sz; i++)
    {
        int sq = sqrt(i);
        for(int j = 1; j<= sq ; j++)
        {
            if(i%j==0)
            {
                v[i].push_back(j);
                if(i != j*j)
                    v[i].push_back(i/j);
            }
        }
    }
    dp[0]=0.0;

    for(int i=2; i<sz; i++)
    {
        dp[i] = v[i].size();
        for(int j=0; j<v[i].size(); j++)
        {
            if(v[i][j]==i)
                continue;
            dp[i] += (dp[v[i][j]]);
        }
        dp[i] /= (double) (v[i].size()-1);
    }
}

int main()
{
    pre();
    int t ,n, cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %.10f\n",cas++,dp[n]);
    }
}

/* E[n] = (1+E[a[1]] )/number of div + .... ((1+E[num of div])/no of div)
E[n]* (1+E[no of div]/no of div) = ... ( to avoid infinite calculation)
E[n] = ..... / (no of div -1 )
*/


