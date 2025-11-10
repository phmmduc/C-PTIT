#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005], rev[1005];
vector<int> indeg, outdeg;
vector<bool> visited;

void dfs(int u, vector<int> g[1005])
{
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v])
            dfs(v, g);
}

bool isWeaklyConnected()
{
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
        for (int v : adj[i])
        {
            g[i].push_back(v);
            g[v].push_back(i);
        }

    int start = -1;
    for (int i = 1; i <= n; i++)
        if (!g[i].empty())
        {
            start = i;
            break;
        }

    if (start == -1)
        return true;

    visited.assign(n + 1, false);
    dfs(start, g.data());
    for (int i = 1; i <= n; i++)
        if (!visited[i] && !g[i].empty())
            return false;

    return true;
}

void checkEulerDirected()
{
    indeg.assign(n + 1, 0);
    outdeg.assign(n + 1, 0);

    for (int u = 1; u <= n; u++)
        for (int v : adj[u])
        {
            outdeg[u]++;
            indeg[v]++;
        }

    if (!isWeaklyConnected())
    {
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
        if (indeg[i] != outdeg[i])
        {
            cout << 0 << endl;
            return;
        }

    cout << 1 << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            rev[i].clear();
        }

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            rev[v].push_back(u);
        }

        checkEulerDirected();
    }
}
