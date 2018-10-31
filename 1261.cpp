#include<bits/stdc++.h>
using namespace std;

int a[35];
int x[35][35];

int main()
{
    int t , cas = 1 , i  , j ;

    scanf("%d",&t);
    while(t--)
    {
        int n , m , k ;
        scanf("%d%d%d",&n,&m,&k);

        for(i=0; i<n; i++)
        {
            for(j=0; j<k ; j++)
            {

                scanf("%d",&x[i][j]);

            }
        }



        int p ;
        scanf("%d",&p);
        for(i=0; i<p; i++)
            scanf("%d",&a[i]);


        for(i=0; i<n; i++)
        {
            for(j=0; j<k; j++)
            {
                int l ;

                if(x[i][j]<0)
                {

                    for(l = 0 ; l<p; l++)
                        if(a[l]==-x[i][j])
                            break;

                    if(l==p)
                        break;
                }
                else
                {
                    for(l=0; l<p; l++)
                        if(a[l]==x[i][j])
                            break;

                    if(l<p)
                        break;
                }
            }
           // cout << j << " " << endl;
            if(j==k)
                break;
        }

        printf("Case %d: ",cas++);
        if(i==n)
            puts("Yes");
        else
            puts("No");

    }
}


