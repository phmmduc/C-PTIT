#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[105];
bool visited[105];

void dfs(int u)
{
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            visited[v] = true;
            dfs(v);
        }
    }
}

int cntComponentsDFS(int skip)
{
    memset(visited, 0, sizeof(visited));
    visited[skip] = true;
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            visited[i] = true;
            dfs(i);
        }
    }
    return cnt;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    int base = cntComponentsDFS(0);

    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (cntComponentsDFS(i) > base)
        {
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}