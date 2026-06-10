#include <bits/stdc++.h>
using namespace std;

int t, n, start;
vector<int> adj[105];
bool visited[105];
vector<pair<int, int>> tree_edges;

void dfs(int u)
{
    visited[u] = true;
    for (auto v : adj[u])
        if (!visited[v])
        {
            tree_edges.push_back({min(u, v), max(u, v)});
            dfs(v);
        }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (auto v : adj[curr])
            if (!visited[v])
            {
                visited[v] = true;
                tree_edges.push_back({min(curr, v), max(curr, v)});
                q.push(v);
            }
    }
}

int main()
{
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(visited, false, sizeof(visited));

    cin >> t >> n >> start;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
                adj[i].push_back(j);
        }
    }

    if (t == 1)
        dfs(start);
    else if (t == 2)
        bfs(start);

    if (tree_edges.size() == n - 1)
    {
        cout << tree_edges.size() << '\n';
        for (auto x : tree_edges)
            cout << x.first << " " << x.second << '\n';
    }
    else
        cout << 0 << '\n';
}