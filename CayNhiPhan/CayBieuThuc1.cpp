#include <bits/stdc++.h>
using namespace std;

string s;

bool checkNum(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 0;
    return 1;
}
void solve()
{
    string ans = "";
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (checkNum(s[i]))
            st.push(string(1, s[i]));
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            string temp = b + string(1, s[i]) + a;
            st.push(temp);
        }
    }
    cout << st.top() << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        cin >> s;
        solve();
    }
}