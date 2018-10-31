#include<bits/stdc++.h>
using namespace std;
#define N 200005
 
int tree[N],a[N],n;
void update(int id,int x)
{
    while(id<=n)
    {
        tree[id] += x;
        id += id & -id;
    }
}
 
int que(int id)
{
    int ans = 0;
    while(id>0)
    {
        ans += tree[id];
        id -= id & -id;
    }
    return ans ;
}
 
 
int main()
{
    int t ,cas=1;
    scanf("%d",&t);
    while(t--)
    {
 
        memset(tree,0,sizeof tree);
        string s,p;
        cin >> s;
        n = s.length();
        int q;
        printf("Case %d:\n",cas++);
        scanf("%d",&q);
        while(q--)
        {
            char c;
            scanf(" %c",&c);
            if(c=='I')
            {
                int id ,id1;
                scanf("%d%d",&id,&id1);
                update(id,1);
                update(id1+1,-1);
            }
 
            else
            {
                int id;
                scanf("%d",&id);
            //    cout << s[id-1] << endl;
                int ans = (que(id)+(s[id-1]-'0'))%2;
                printf("%d\n",ans);
            }
        }
    }
}
 