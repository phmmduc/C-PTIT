#include <bits/stdc++.h>
using namespace std;
int q;
string s;
stack<string> st;

int main()
{
    cin >> q;
    while (q--)
    {
        cin>>s;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                string s1=st.top(); st.pop();
                string s2=st.top(); st.pop();
                string tmp = s1 + s2 + s[i]; // +AB -> AB+
                st.push(tmp);
            }
            else st.push(string(1,s[i]));
        }
        cout<<st.top()<<endl;
    }
}
