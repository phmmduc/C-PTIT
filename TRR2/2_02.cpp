#include <bits/stdc++.h>
using namespace std;

int t, n, u, v;
int a[105][105];
vector<int> adj[105];
bool visited[105];
vector<int> parent;

bool bfs(int start, int target)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == target)
            return true;
        for (auto nxt : adj[curr])
        {
            if (!visited[nxt])
            {
                visited[nxt] = true;
                q.push(nxt);
                parent[nxt] = curr;
            }
        }
    }
    return false;
}

int main()
{
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n >> u >> v;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }

    if (t == 1)
    {
        int cnt = 0;
        for (int w = 1; w <= n; w++)
        {
            if (a[u][w] == 1 && a[w][v] == 1)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    else if (t == 2)
    {
        memset(visited, false, sizeof(visited));
        parent.assign(n + 1, -1);

        if (bfs(u, v))
        {
            vector<int> path;
            for (int node = v; node != -1; node = parent[node])
            {
                path.push_back(node);
            }
            reverse(path.begin(), path.end());

            for (auto node : path)
            {
                cout << node << " ";
            }
            cout << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }

    return 0;
}