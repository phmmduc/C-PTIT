#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1005];
vector<int> a[1005];

void dfs(int u)
{
    visited[u] = true;
    for (auto v : a[u])
        if (!visited[v])
            dfs(v);
}

int connected()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
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
        cout << connected() << endl;
    }
}