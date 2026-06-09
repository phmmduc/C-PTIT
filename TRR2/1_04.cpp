#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int deg[105];
int a[105][105];

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;

        a[u][v] = 1;
        a[v][u] = 1;

        deg[u]++;
        deg[v]++;
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
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}