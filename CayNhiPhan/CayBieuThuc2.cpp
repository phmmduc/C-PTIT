#include <bits/stdc++.h>
using namespace std;

vector<string> s;

bool checkNum(string c)
{
    if (c == "+" || c == "-" || c == "*" || c == "/")
        return 0;
    return 1;
}

int calc(int a, int b, string s)
{
    if (s == "+")
        return a + b;
    if (s == "-")
        return a - b;
    if (s == "*")
        return a * b;
    if (s == "/")
        return a / b;
}

int node(int idx)
{
    if (idx >= s.size())
        return 0;
    if (checkNum(s[idx]))
        return stoi(s[idx]);

    int l = node(2 * idx + 1);
    int r = node(2 * idx + 2);
    return calc(l, r, s[idx]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        s.resize(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        cout << node(0) << endl;
    }
}