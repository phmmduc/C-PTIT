#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, s, t;
vector<tuple<int, int, int>> adj;
vector<int> par(105, -1);

void printPath(int v)
{
    if (par[v] == -1)
    {
        cout << v << " ";
        return;
    }
    printPath(par[v]);
    cout << v << " ";
}

void bellman_ford(int start)
{
    vector<int> dist(n + 1, INF);
    fill(par.begin(), par.end(), -1);
    dist[start] = 0;
    for (int i = 1; i < n; i++)
    {
        bool update = false;
        for (auto [u, v, w] : adj)
        {
            if (dist[u] != INF && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                update = true;
            }
        }
        if (!update)
            break;
    }
    for (auto [u, v, w] : adj)
    {
        if (dist[u] != INF && dist[v] > dist[u] + w)
        {
            cout << -1;
            return;
        }
    }
    if (dist[t] != INF)
    {
        cout << dist[t] << "\n";
        printPath(t);
    }
    else
        cout << 0;
}

int main()
{
    // freopen("BN.INP", "r", stdin);
    // freopen("BN.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int w;
            cin >> w;
            if (i != j && w != 10000)
                adj.push_back({i, j, w});
        }
    bellman_ford(s);
}