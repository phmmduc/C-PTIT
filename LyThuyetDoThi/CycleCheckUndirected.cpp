#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1005];
vector<int> a[1005];

bool dfs(int u, int par)
{
    visited[u] = true;
    for (auto v : a[u])
        if (!visited[v])
        {
            if (dfs(v, u))
                return true;
        }
        else if (v != par)
            return true;
    return false;
}

bool bfs(int start)
{
    queue<pair<int, int>> q;
    visited[start] = true;
    q.push({start, -1});

    while (!q.empty())
    {
        int u = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int v : a[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push({v, u});
            }
            else if (v != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            //if (bfs(i, -1))
            if (dfs(i, -1))
                return true;
        }
    }
    return false;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            a[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        memset(visited, 0, sizeof(visited));
        if (hasCycle())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}