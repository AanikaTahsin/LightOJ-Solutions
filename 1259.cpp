#include<bits/stdc++.h>
#define ll long long
#define n 10000007
using namespace std;
bool arr[n];
vector<int>prime;
void sieve()
{
    int sq = sqrt(n);
    for (int i = 4; i <= n; i += 2)
        arr[i] = 1;
    for (int i = 3; i <= sq; i += 2)
    {
        if (arr[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
                arr[j] = 1;
        }
    }
    prime.push_back(2);
    for(int  i=3; i<=n; i+=2)
    {
        if(!arr[i])prime.push_back(i);
    }
}
 
int main()
{
    int i, j,t, p,c;
    sieve();
    int x, y, z;
    scanf("%d", &t);
    for(int cas =1; cas<=t; cas++)
    {
        scanf("%d",&x);
        c=0;
        int sq =x/2;
        for (i = 0;sq<=x-prime[i];i++)
        {
            p=x-prime[i];
            if (arr[p] == 0)
                c++;
        }
        printf("Case %d: %d\n",cas,c);
    }
}
 