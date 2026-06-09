#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> a[105];
int deg[1005];
int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                deg[j]++;
                a[i].push_back(j);
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << deg[i] << " ";
        }
    }
    else if (t == 2)
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].size() << " ";
            for (auto x : a[i])
            {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}
