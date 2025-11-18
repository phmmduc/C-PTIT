#include <bits/stdc++.h>
using namespace std;

int n, m, d[105][105];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            d[i][j] = 1e9;
        d[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
    //    for(int i=1;i<=n;i++)
    //    {
    //        for(int j=1;j<=n;j++)
    //            cout<<d[i][j]<<" ";
    //        cout<<endl;
    //    }
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << d[u][v] << endl;
    }
}
