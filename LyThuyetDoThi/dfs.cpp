#include <bits/stdc++.h>
using namespace std;

int t, n, m, u;
vector<int> a[1005];
bool visited[1005];

void input()
{
    cin >> n >> m >> u;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (auto v : a[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        input();
        dfs(u);
        for (int i = 1; i <= n; i++)
            a[i].clear();
        cout << endl;
    }
}