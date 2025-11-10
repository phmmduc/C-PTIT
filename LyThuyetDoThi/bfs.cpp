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

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (auto x : a[v])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
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
        bfs(u);
        for (int i = 1; i <= n; i++)
            a[i].clear();
        cout << endl;
    }
}