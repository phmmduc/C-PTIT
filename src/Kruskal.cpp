#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
const int MAX = 100005;
int parent[MAX], sz[MAX];

struct Edges
{
    int a, b, w;
};

bool cmp(Edges a, Edges b)
{
    return a.w < b.w;
}

int findSet(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = findSet(parent[u]);
}

bool unionSet(int u, int v)
{
    u = findSet(u);
    v = findSet(v);
    if (u == v)
        return 0;
    if (sz[u] < sz[v])
        swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return 1;
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
int main()
{
    // freopen("input.txt","r",stdin);
    int q;
    cin >> q;
    while (q--)
    {
        ans = 0;
        cin >> n >> m;
        init(n);
        vector<Edges> edge(m);
        for (int i = 0; i < m; i++)
            cin >> edge[i].a >> edge[i].b >> edge[i].w;
        sort(edge.begin(), edge.end(), cmp);
        int ans = 0, cnt = 0;
        for (int i = 0; i < edge.size(); i++)
            if (unionSet(edge[i].a, edge[i].b))
            {
                ans += edge[i].w;
                cnt++;
            }
        cout << ans << endl;
    }
}
