#include<bits/stdc++.h>

using namespace std;
#define mx 100005
int L[mx];
int S[mx];
int P[mx][22];
int T[mx];

void lca_init(int N)
{
    memset (P,-1,sizeof(P));
    int i, j;
    for (i = 0; i < N; i++)
        P[i][0] = T[i];

    for (j = 1; 1 << j < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}

int lca_query(int node, int k)
{
    int log = log2(L[node]);

    for(int i = log; i>= 0; i--)
    {
        if(P[node][i]!=-1 and S[P[node][i]]>=k)
            node = P[node][i];
    }

    return node;
}

int main()
{
    int t , i , j , k , cas =1, val ;

    scanf("%d",&t);

    while(t--)
    {
        int n, q ;
        scanf("%d%d",&n,&q);
        S[0] = 1 ;
        L[0] = 0;
        for(i=1; i<n; i++)
        {
            scanf("%d%d",&T[i],&S[i]);
            L[i] = L[T[i]]+1;
        }
        lca_init(n);

        printf("Case %d:\n",cas++);

        while(q--)
        {
            int node;
            scanf("%d%d",&node,&k);
            printf("%d\n",lca_query(node,k));
        }
    }
}
