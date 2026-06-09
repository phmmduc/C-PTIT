#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int deg[105];
int a[105][105];

int main()
{
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        deg[u]++;
        deg[v]++;
        a[u][v] = w;
        a[v][u] = w;
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << deg[i] << " ";
        }
    }
    else
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 0 && i == j)
                    cout << 0 << " ";
                else if (a[i][j] == 0)
                    cout << 10000 << " ";
                else
                    cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}