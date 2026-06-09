#include <bits/stdc++.h>
using namespace std;

int n, lt;
vector<int> adj[105];
bool visited[105];
vector<int> ans[105];

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int curr = q.front();
        ans[lt].push_back(curr);
        q.pop();

        for (auto v : adj[curr])
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
    }
}

int main()
{
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);

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
            bfs(i);
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