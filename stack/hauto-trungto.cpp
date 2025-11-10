#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        stack<string> st;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            if (!isalnum(s[i]))
            {
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                string tmp = "(" + s2 + s[i] + s1 + ")"; // AB+ -> (A+B)
                st.push(tmp);
            }
            else
                st.push(string(1, s[i]));
        }
        cout << st.top() << endl;
    }
}