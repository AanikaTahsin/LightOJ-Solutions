#include<bits/stdc++.h>
using namespace std;

const long long inf = 60;

string a, b;
int n, m, length;
long long total;

int dpone[35][35];
long long dptwo[35][35][70];

int one(int i, int j)
{
    if( i == n and j == m ) return 0;
    if( dpone[i][j] != -1 ) return dpone[i][j];

    int ret =0;
    if( i == n ) ret = 1 + one(i,j+1);
    else if( j == m ) ret =  1 + one(i+1,j);
    else if( a[i] == b[j] ) ret = 1 + one(i+1,j+1);
    else ret =  1 + min( one(i+1,j), one(i,j+1) );

    return dpone[i][j] = ret;
}

long long two(int i, int j, int now)
{
    if( i == n and j == m ) return (now == length) ;
    if( dptwo[i][j][now] != -1 ) return dptwo[i][j][now];

    long long ret = 0;
    if( j != m and i != n and a[i] == b[j] ) ret += two(i+1,j+1,now+1);
    else
    {
        if( j != m ) ret += two(i,j+1,now+1);
        if( i != n ) ret += two(i+1,j,now+1);
    }
    return dptwo[i][j][now] = ret;
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; t++)
    {
        cin >> a >> b;
        memset(dpone,-1,sizeof dpone);
        memset(dptwo,-1,sizeof dptwo);

        n = a.size(), m = b.size();

        length = one(0,0), total = two(0,0,0);
        cout << "Case " << t << ": " << length << ' ' << total << endl;
    }
}
