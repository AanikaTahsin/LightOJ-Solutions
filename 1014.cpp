#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n , i , j, t, k , l , p ;
    scanf("%d",&t);
    int cs = 1 ;
    while(t--)
    {
        scanf("%d%d",&p,&l);
        p -= l ;
        int sq = sqrt(p);
        vector<int>v;
        for(i=1; i<=sq; i++)
        {
            if(p%i==0)
            {
                if(i>l)
                    v.push_back(i);
                if(p/i > l and i*i !=p)
                    v.push_back(p/i);

            }
        }
        sort(v.begin(),v.end());
        printf("Case %d: ",cs++);
        if(v.size()==0)
            puts("impossible");
        else
        {
            for(i = 0 ;  i < v.size(); i++)
            {
                printf("%d",v[i]);
                if(i<v.size()-1)
                    printf(" ");
                else
                    puts("");
            }
        }
    }
}
