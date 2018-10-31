#include<bits/stdc++.h>
using namespace std;
int dp[100][100][100];
string s , p , q ;
int ans_me( int i , int j , int k)
{
    if( i==0 || j==0 || k==0 )
        return 0 ;
    if(dp[i][j][k] != -1 )
        return dp[i][j][k];
    if(s[i-1]==p[j-1]&&p[j-1]==q[k-1])
    {
        return dp[i][j][k]  = ans_me(i-1,j-1,k-1)+1;
    }
    else
    {
        return dp[i][j][k] = max(ans_me(i,j,k-1),max(ans_me(i,j-1,k),ans_me(i-1,j,k)));
    }
 
}
int main()
{
    int t ;
    cin >> t ;
    int cas = 1 ;
    while(t--)
    {
 
        cin >> s >> p >> q ;
        memset(dp,-1,sizeof dp);
        printf("Case %d: %d\n",cas++, ans_me(s.length(),p.length(),q.length()) );
    }
}
 