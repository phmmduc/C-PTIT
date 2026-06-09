#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int deg[105];
vector<int> adj[105];
vector<pair<int, int>> edgeList;
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

        adj[u].push_back(v);
        adj[v].push_back(u);

        a[u][v] = 1;
        a[v][u] = 1;

        deg[u]++;
        deg[v]++;

        edgeList.push_back({u, v});
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
        cout << n << " " << m << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (edgeList[j].first == i || edgeList[j].second == i)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }

        return 0;
    }
}