#include<bits/stdc++.h>

using namespace std;

int  main()
{
    int t , i , cas=1;

    cin >> t ;
    while(t--)
    {
        double ab, bc,  ca , rat;

        cin >> ab >> bc >> ca >> rat;

        double ans = rat/(rat+1);/// ADE/BDEC = (m/(m+n)) = (m/n)/((m+n)/n) = (m/n)/(1+(m/n))

        ans = ab * sqrt(ans); /// as ADE and ABC Hierarchical triangle so AD/AB = DE/BC

        printf("Case %d: %.10f\n",cas++, ans);
    }
}
