#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> edges;
vector<int> parent;
bool visited[1005];
bool dfs(int x, int target)
{
    // cout << x << " ";
    visited[x] = true;
    if (x == target)
        return true;
    for (auto u : edges[x])
        if (!visited[u])
        {
            parent[u] = x;
            if (dfs(u, target))
                return true;
        }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;

        edges.assign(n + 1, {});
        parent.assign(n + 1, -1);
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        if (dfs(s, t))
        {
            vector<int> path;
            for (int v = t; v != -1; v = parent[v])
            {
                path.push_back(v);
            }
            reverse(path.begin(), path.end());
            for (auto v : path)
                cout << v << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}