#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<pair<int, int>> a;
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
                if (i < j)
                {
                    a.push_back({i, j});
                }
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
        cout << n << " " << a.size() << endl;
        for (auto x : a)
        {
            cout << x.first << " " << x.second << endl;
        }
    }

    return 0;
}