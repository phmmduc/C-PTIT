#include <bits/stdc++.h>
using namespace std;

int n, lt;
vector<int> adj[105];
bool visited[105];
vector<int> ans[105];

void dfs(int u)
{
    ans[lt].push_back(u);
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
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

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            lt++;
            dfs(i);
        }
    }

    cout << lt << "\n";
    for (int i = 1; i <= lt; i++)
    {
        sort(ans[i].begin(), ans[i].end());

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}