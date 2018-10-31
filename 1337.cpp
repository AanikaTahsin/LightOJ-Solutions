#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t , cas = 1 , i ,  j  , k ;

    cin >> t ;
    while(t--)
    {
        string s ;
        cin >> s ;

        stack<char>st;
        st.push(s[0]);

        int a[30] = {0};

        for(i=1; i<s.length(); i++)
        {
            if(s[i]==st.top())
                st.pop();
            else
            {

                a[s[i]-'A']++;
                a[st.top()-'A']++;
                st.push(s[i]);
            }
        }

        cerr << "anika" << endl;

        printf("Case %d\n",cas++);

        for(i=0; i<26; i++)
            if(a[i])
                cout << char(i+'A') << " = " << a[i] << '\n';
    }
}

///AEFFGGEBDDCCBA
