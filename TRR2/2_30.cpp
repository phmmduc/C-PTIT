#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[105];
vector<pair<int, int>> edges, bridges;
bool visited[105];

int cntComponentsBFS(int skip_u, int skip_v)
{
    memset(visited, 0, sizeof(visited));
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : adj[u])
                {
                    if ((u == skip_u && v == skip_v) || (v == skip_u && u == skip_v))
                        continue;

                    if (!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return cnt;
}

int main()
{
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x)
            {
                adj[i].push_back(j);
                if (i < j)
                    edges.push_back({i, j});
            }
        }
    int base = cntComponentsBFS(0, 0);

    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;
        if (cntComponentsBFS(u, v) > base)
            bridges.push_back({u, v});
    }

    sort(bridges.begin(), bridges.end());

    cout << bridges.size() << endl;
    for (auto edge : bridges)
        cout << edge.first << " " << edge.second << endl;
}