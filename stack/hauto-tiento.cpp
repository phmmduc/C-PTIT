#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<string> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!isalnum(s[i]))
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string tmp = s[i] + s2 + s1; // AB+ -> +AB
                st.push(tmp);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}