#include<bits/stdc++.h>


using namespace std;


const int sz = 100005;

int trie[sz][53], idx ;

int check(char c)
{
    if(c>='A' and c<='Z')
        return (c - 'A') + 26;
    return (c - 'a') ;
}

void push(string s )
{
    int cur = 0 , i , j ;

    for(i=0; i<s.length(); i++)
    {
        int x = check(s[i]);
        if(trie[cur][x]==-1)
        {
            idx++;
            trie[cur][x] = idx;
            memset(trie[idx], -1 , sizeof trie[idx]);
            trie[idx][52] = 0 ;
        }
        cur = trie[cur][x];
    }

    trie[cur][52]++;
}

int get_ans(string s )
{
    int cur = 0 , i , j ;

    for(i=0; i<s.length(); i++)
    {
        int x = check(s[i]);

        if(trie[cur][x]==-1)
            return 0 ;

        cur = trie[cur][x];
    }

    return trie[cur][52];

}


int main()
{
    int t , cas = 1 , i , j ;

    scanf("%d",&t);

    while(t--)
    {

        memset(trie, -1 , sizeof trie);
        trie[0][52] = 0 ;
        idx = 0 ;
        int n, m ;
        scanf("%d",&n);

        string s ;
        getline(cin,s);

        for(i=0; i<n; i++)
        {
            char x[10001];
            scanf("%s",&x);
            int len = strlen(x);
            s = "";
            for(int j = 0 ; j < len; j++)
                s += x[j];
            if(s.length()>3)
                sort(s.begin()+1,s.end()-1);
            push(s);
        }
        printf("Case %d:\n",cas++);
        scanf("%d",&m);
        getline(cin,s);


        while(m--)
        {
            char x[100005];
            scanf(" %[^\t\n]s", &x);
            int len = strlen(x);
            s = "";
            for(int j = 0 ; j < len; j++)
                s += x[j];
            //cout << s << endl;
            stringstream ss(s);
            //  cout << s << endl;

            long long ans = 1 ;
            while(ss>>s)
            {
                if(s.size()>3)
                    sort(s.begin()+1,s.end()-1);
                ans *= ((long long)get_ans(s));
            }
            printf("%lld\n",ans);
        }
    }
}

