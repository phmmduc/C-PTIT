#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
vector<int> parent;
bool visited[1005];

bool bfs(int u, int target)
{
    queue<int> q;
    visited[u] = 1;
    q.push(u);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == target)
            return true;
        for (auto v : edges[x])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
                parent[v] = x;
            }
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--)
    {
        int n, m, s, t;
        cin >> n >> m >> s >> t;

        memset(visited, 0, sizeof(visited));
        edges.assign(n + 1, {});
        parent.assign(n + 1, -1);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        if (bfs(s, t))
        {
            vector<int> path;
            for (int v = t; v != -1; v = parent[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            for (auto v : path)
                cout << v << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
}