#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<tuple<int, int, int>> adj;
int parent[105], sz[105];

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

bool Union(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return false;
    if (u > v)
        swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

void Kruskal()
{
    vector<tuple<int, int, int>> MST;
    int ans = 0;
    for (auto [w, x, y] : adj)
    {
        if (MST.size() == n - 1)
            break;
        if (Union(x, y))
        {
            ans += w;
            MST.push_back({w, x, y});
        }
    }
    if (MST.size() < n - 1)
        cout << 0 << endl;
    else
    {
        cout << ans << endl;
        for (auto [w, x, y] : MST)
            cout << x << " " << y << " " << w << endl;
    }
}

int main()
{
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj.push_back({w, u, v});
    }
    sort(adj.begin(), adj.end());
    for (int i = 1; i <= n; i++)
    {
        sz[i] = 1;
        parent[i] = i;
    }

    Kruskal();
}