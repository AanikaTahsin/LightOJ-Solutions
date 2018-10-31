#include<bits/stdc++.h>

using namespace std;

vector<int>v[1001];

inline int getmin(int b, int e)
{
    int mn = 1001,prev=-1;

    for(int i = 1; i<=1000; i++)
    {
        int lo = lower_bound(v[i].begin(),v[i].end(),b)-v[i].begin();
        int hi = upper_bound(v[i].begin(),v[i].end(),e)-v[i].begin();
       // cout << hi <<  " " << lo << endl;
        if(hi-lo>1)
            return 0;
        if(hi-lo>0 && prev>-1)
            mn = min(mn,i-prev);
        if(hi-lo>0)
            prev = i ;
    }
    return mn ;
}

int main()
{
    int t, i , n , j , x , q, cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);


        for(i=1; i<=1001; i++)
            v[i].clear();

        for(i=0; i<n; i++)
        {
            scanf("%d",&x);
            v[x].push_back(i);
        }

        printf("Case %d:\n",cas++);

        while(q--)
        {
            int l,r ;
            scanf("%d%d",&l,&r);
            int ans = getmin(l,r);
            printf("%d\n",ans);

        }

    }
}
