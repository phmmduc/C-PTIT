#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> a[1005];
int parent[1005];
bool visited[1005];
bool found;

void input()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        a[i].clear();
        visited[i] = false;
        parent[i] = -1;
    }
    found = false;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

void dfs(int u)
{
    visited[u] = true;
    if (u == t)
    {
        found = true;
        return;
    }
    for (auto v : a[u])
        if (!visited[v] && !found)
        {
            parent[v] = u;
            dfs(v);
            if (found)
                return;
        }
}

void find()
{
    if (!found)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    for (int i = t; i != -1; i = parent[i])
        path.push_back(i);
    reverse(path.begin(), path.end());
    for (auto x : path)
        cout << x << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        input();
        dfs(s);
        find();
    }
}