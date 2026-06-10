#include <bits/stdc++.h>
using namespace std;

int t, n, u;
int a[105][105];
bool visited[105];
set<int> adj[105];
vector<int> EC;

void DFS(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

bool KiemTraLienThong()
{
    memset(visited, 0, sizeof(visited));
    int start = 0;

    for (int i = 1; i <= n && !start; i++)
        if (!adj[i].empty())
            start = i;

    if (!start)
        return true;

    DFS(start);

    for (int i = 1; i <= n; i++)
        if (!adj[i].empty() && !visited[i])
            return false;

    return true;
}

void solve1()
{
    if (!KiemTraLienThong())
    {
        cout << 0 << "\n";
        return;
    }

    int odd_deg = 0;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() % 2 != 0)
        {
            odd_deg++;
        }
    }

    if (odd_deg == 0)
    {
        cout << 1 << "\n";
    }
    else if (odd_deg == 2)
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }
}

void euler(int v)
{
    while (!adj[v].empty())
    {
        int next_v = *adj[v].begin();

        adj[v].erase(next_v);
        adj[next_v].erase(v);

        euler(next_v);
    }
    EC.push_back(v);
}

void solve2()
{
    EC.clear();
    euler(u);

    for (int i = EC.size() - 1; i >= 0; i--)
    {
        cout << EC[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    if (t == 1)
        cin >> n;
    else
        cin >> n >> u;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                adj[i].insert(j);
            }
        }
    }

    if (t == 1)
        solve1();
    else if (t == 2)
        solve2();
}