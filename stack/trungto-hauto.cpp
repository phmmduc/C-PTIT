#include <bits/stdc++.h>
using namespace std;

int check(char c)
{
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        getline(cin >> ws, s);
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (isalnum(s[i])) 
                cout << s[i];
            else if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    cout << st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
            {
                while (!st.empty() && check(st.top()) >= check(s[i])) //kiểm tra độ ưu tiên
                {
                    if (st.top() == '(')
                        break;
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while (!st.empty())
        {
            if (st.top() != '(')
                cout << st.top();
            st.pop();
        }
        cout << endl;
    }
}
