#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int i = 0;
    if (s[i] == '-')
    {
        if (s.size() == 1)
            return false;
        i++;
    }
    for (; i < s.size(); i++)
        if (s[i] < '0' || s[i] > '9')
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        stack<long long> st;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            if (check(s))
            {
                st.push(stoll(s));
            }
            else
            {
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();
                long long tmp = 0;
                
                if (s == "+")
                    tmp = a + b;
                else if (s == "-")
                    tmp = a - b;
                else if (s == "*")
                    tmp = a * b;
                else if (s == "/")
                    tmp = a / b;
                
                st.push(tmp);
            }
        }
        cout << st.top() << endl;
    }
}