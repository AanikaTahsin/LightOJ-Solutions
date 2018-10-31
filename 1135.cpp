#include<bits/stdc++.h>

using namespace std;

const int sz = 4*100005;

int tree[10][sz],lazy[sz];

void gach(int root, int left, int right)
{
    tree[0][root] = (right-left+1);
    tree[1][root] = 0 ;
    tree[2][root] = 0 ;
    lazy[root] = 0 ;

    if(left==right)
    {
        tree[0][root]= 1 ;
        return;
    }

    int mid = (left+right) >> 1 ;
    gach(root << 1 , left , mid );
    gach((root << 1)+1, mid+1, right);
}


void propagate(int root, int left, int right)
{
    if(left != right)  /// do check otherwise it might take extra memory
    {

        lazy[root<<1] += lazy[root];
        lazy[root<<1] %= 3 ;
        lazy[(root<<1)+1] += lazy[root];
        lazy[(root<<1)+1] %= 3 ;
    }

    if(lazy[root]==1)
    {
        tree[2][root] = tree[1][root];
        tree[1][root] = tree[0][root];
        tree[0][root] = (right-left+1)-(tree[1][root]+tree[2][root]);
    }
    if(lazy[root]==2)
    {
        tree[1][root] = tree[2][root];
        tree[2][root] = tree[0][root];
        tree[0][root] = (right-left+1)-(tree[1][root]+tree[2][root]);
    }

    lazy[root] = 0 ;
}


void upd(int root, int left , int right, int b, int e)
{
    if(lazy[root])
        propagate(root, left , right);
    if(b > right or left > e)
        return ;

    if(b <= left and right <= e)
    {
        if(left != right)  /// do check otherwise it might take extra memory
        {
            lazy[root<<1] += lazy[root]+1;
            lazy[root<<1] %= 3 ;
            lazy[(root<<1)+1] += lazy[root]+1;
            lazy[(root<<1)+1] %= 3 ;
        }
        tree[2][root] = tree[1][root];
        tree[1][root] = tree[0][root];
        tree[0][root] = (right-left+1)-(tree[1][root]+tree[2][root]);
        return ;
    }

    int mid = (left+right) >> 1 ;
    upd(root<<1, left, mid, b,  e);
    upd((root<<1)+1, mid+1, right, b, e);

    for(int i=0; i<3; i++)
        tree[i][root] = tree[i][root << 1] + tree[i][(root<<1)+1];
}



int que(int root, int left , int right, int b, int e)
{
    if(lazy[root])
        propagate(root, left , right);
    if(b > right or left > e)
        return 0;

    if(b <= left and right <= e)
        return tree[0][root];

    int mid = (left+right) >> 1 ;
    int r1 = que(root<<1, left, mid, b, e);
    int r2 = que((root<<1)+1, mid+1, right, b, e);

    for(int i=0; i<3; i++)
        tree[i][root] = tree[i][root << 1] + tree[i][(root<<1)+1];
    return r1+r2 ;
}



int main()
{
    int t, cas = 1 ;
    int n , i , j , q ;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&q);
        printf("Case %d:\n",cas++);
        gach(1,0,n-1);

        while(q--)
        {
            int type,l,r ;
            scanf("%d %d %d",&type, &l, &r);
            if(type==0)
                upd(1,0,n-1,l,r);
            else
                printf("%d\n",que(1,0,n-1,l,r));
        }
    }
}
