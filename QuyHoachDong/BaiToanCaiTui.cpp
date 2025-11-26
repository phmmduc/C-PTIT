#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--)
    {
        int n, v;
        cin >> n >> v;
        vector<int> a(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        vector<int> dp(v + 1, 0);
        for (int i = 0; i < n; i++)
            for (int w = v; w >= a[i]; w--)
                dp[w] = max(dp[w], dp[w - a[i]] + c[i]);
        cout << dp[v] << endl;
    }
}
