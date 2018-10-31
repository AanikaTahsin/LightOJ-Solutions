#include<bits/stdc++.h>

using namespace std;

int main()
{
    double  v1, v2, v3 ,a1 ,a2 ,dis,d;

    int t , cas = 1 ;

    cin >> t ;
    while(t--)
    {
        cin >>  v1 >> v2 >> v3 >> a1 >> a2 ;
        double t1 = (v1/a1);
        double t2 = v2/a2;
        double t3 = max(t1,t2);

        dis = v3*t3 ;
        d = v1*t1 - 0.5*a1*t1*t1;

        d += v2*t2 - 0.5 *a2*t2*t2 ;


        printf("Case %d: %f %f\n",cas++,d,dis);
    }
}
