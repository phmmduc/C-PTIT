#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m, start, target;
int dist[105], par[105];
int a[105][105];
vector<pair<int, int>> adj[105];
bool visited[105];

void dijkstra(int start)
{
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

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

int main()
{
    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(dist, dist + 105, INF);
    fill(par, par + 105, -1);
    cin >> n >> start >> target;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 10000)
                adj[i].push_back({j, a[i][j]});
        }

    dijkstra(start);
    if (dist[target] == INF)
        cout << 0 << endl;
    else
    {
        cout << dist[target] << endl;
        printPath(target);
    }
}