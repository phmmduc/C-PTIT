#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1005];
vector<bool> visited;

void dfs(int u)
{
    visited[u] = true;
    for (int v : adj[u])
        if (!visited[v])
            dfs(v);
}

bool isConnected()
{
    visited.assign(n + 1, false);
    int start = -1;
    for (int i = 1; i <= n; i++)
        if (!adj[i].empty())
        {
            start = i;
            break;
        }
    if (start == -1) // đồ thị không có cạnh nào
        return true;

    dfs(start);

    for (int i = 1; i <= n; i++)
        if (!visited[i] && !adj[i].empty())
            return false;
    return true;
}

void checkEulerUndirected()
{
    if (!isConnected())
    {
        cout << 0 << endl;
        return;
    }

    int odd = 0;
    for (int i = 1; i <= n; i++)
        if (adj[i].size() % 2 == 1)
            odd++;

    if (odd == 0)
        cout << 2 << endl;  // có chu trình Euler
    else if (odd == 2)
        cout << 1 << endl;  // có đường đi Euler
    else
        cout << 0 << endl;  // không có Euler
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;

        // Xóa dữ liệu cũ trước mỗi test
        for (int i = 1; i <= n; i++)
            adj[i].clear();

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        checkEulerUndirected();
    }

    return 0;
}
