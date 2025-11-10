#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    if (s.empty())
        return false;
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
        int n;
        cin >> n;
        vector<string> t(n);
        for (int i = 0; i < n; i++)
            cin >> t[i];

        stack<long long> st;

        for (int i = n - 1; i >= 0; i--)
        {
            string s = t[i];

            if (check(s))
            {
                st.push(stoll(s));
            }
            else
            {
                long long a = st.top();
                st.pop();
                long long b = st.top();
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

    return 0;
}