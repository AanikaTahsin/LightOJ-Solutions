#include<bits/stdc++.h>
 
using namespace std;
 
 
vector<pair<int,pair<int,int> > > graph;
 
int par[1001];
 
int fin( int n)
{
    if(par[n] == n ) return n  ;
    else return par[n] = fin(par[n]);
}
 
int main()
{
    int t , n , i ,cas=1, w,  j , tot , ans ;
    scanf("%d",&t);
    while( t-- )
    {
        graph.clear();
        scanf("%d",&n);
        tot = 0 ;
        for( i = 0; i< n ; i++)
        {
            par[i] = i ;
            for( j = 0; j < n ; j++)
            {
                scanf("%d",&w);
                if(w)
                {
                    tot += w ;
                    if(i != j )
                    {
                        graph.push_back((make_pair(w,make_pair(i,j))));
                    }
                }
            }
        }
        sort(graph.begin(),graph.end());
        int cnt =0 ,cable=0;
        for( i = 0 ; i < graph.size() ; i++)
        {
            int u = graph[i].second.first;
            int v = graph[i].second.second;
            u = fin(u);
            v = fin(v);
            if( u != v)
            {

                par[u] = par[v];
                cnt++;
                cable += graph[i].first;
            }
        }
        if(cnt == n-1 )
            ans = tot - cable ;
        else ans = -1 ;
        printf("Case %d: %d\n",cas++,ans);
    }
}