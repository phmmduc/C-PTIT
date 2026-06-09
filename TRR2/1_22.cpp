#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int degIn[105], degOut[105];
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
        degIn[v]++;
        degOut[u]++;
        a[u][v] = w;
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }
    else
    {
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 0 && i != j)
                    a[i][j] = 10000;
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}