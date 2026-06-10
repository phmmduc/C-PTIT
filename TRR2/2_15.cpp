#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[105];       // Đồ thị có hướng gốc
vector<int> adj_rev[105];   // Đồ thị đảo chiều
vector<int> adj_undir[105]; // Đồ thị vô hướng
bool visited[105];

void dfs(int u, vector<int> graph[])
{
    visited[u] = true;
    for (int v : graph[u])
    {
        if (!visited[v])
        {
            dfs(v, graph);
        }
    }
}

bool check_all_visited()
{
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

bool isStronglyConnected()
{
    memset(visited, false, sizeof(visited));
    dfs(1, adj);

    if (!check_all_visited())
        return false;

    memset(visited, false, sizeof(visited));
    dfs(1, adj_rev);

    return check_all_visited();
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
                adj[i].push_back(j);     // Chiều đi
                adj_rev[j].push_back(i); // Chiều về

                adj_undir[i].push_back(j); // Vô hướng hóa
                adj_undir[j].push_back(i); // Vô hướng hóa
            }
        }
    }

    if (isStronglyConnected())
        cout << 1 << "\n";
    else
    {
        memset(visited, false, sizeof(visited));
        dfs(1, adj_undir);

        if (check_all_visited())
        {
            cout << 2 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    return 0;
}