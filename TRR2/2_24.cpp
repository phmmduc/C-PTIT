#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[105];
bool visited[105];

int cntComponentsBFS(int skip)
{
    memset(visited, 0, sizeof(visited));
    visited[skip] = true;
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
                for (int v : adj[u])
                {
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
                adj[j].push_back(i);
            }
        }

    int base = cntComponentsBFS(0);

    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (cntComponentsBFS(i) > base)
            ans.push_back(i);

    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
}