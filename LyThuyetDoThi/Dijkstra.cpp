#include <bits/stdc++.h>
#define ll long long
#define MAX 10005
#define INF 1e15
using namespace std;

int n, m, s;
vector<pair<int, int>> a[MAX];
int parent[MAX];

void dijkstra(int s)
{
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    parent[s] = s;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q; // {khảng cách, đỉnh}
    q.push({0, s});
    while (!q.empty())
    {
        pair<ll, int> top = q.top();
        q.pop();
        int u = top.second;
        ll k = top.first;
        if (k > d[u]) // đỉnh đã được thăm
            continue;
        for (auto x : a[u]) // cập nhật khoảng cách từ s cho mọi đỉnh kề với u
        {
            int v = x.first;  // đỉnh
            int w = x.second; // trọng số
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
                parent[v] = u; // cập nhật đường đi
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        cin >> n >> m >> s;
        for (int i = 1; i <= n; i++)
            a[i].clear();

        for (int i = 1; i <= m; i++)
        {
            int x, y, w;
            cin >> x >> y >> w; // {đỉnh, trọng số}
            a[x].push_back({y, w});
            a[y].push_back({x, w});
        }

        dijkstra(s);
    }
}