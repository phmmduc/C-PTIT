#include <bits/stdc++.h>
using namespace std;

int n, start, cycle_cnt;
int a[105][105];
vector<int> adj[105];
int path[105];
bool visited[105];

void dfs(int curr, int step)
{
    path[step] = curr;
    if (step == n)
    {
        if (a[curr][start] == 1)
        {
            for (int i = 1; i <= n; i++)
                cout << path[i] << " ";
            cout << start << endl;
            cycle_cnt++;
        }
        return;
    }

    for (int v = 1; v <= n; v++)
    {
        if (a[curr][v] == 1 && !visited[v])
        {
            visited[v] = true;
            dfs(v, step + 1);
            visited[v] = false;
        }
    }
}

int main()
{
    // freopen("CT.INP","r",stdin);
    // freopen("CT.OUT","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> start;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    visited[start] = true;
    dfs(start, 1);
    if (cycle_cnt == 0)
        cout << 0 << endl;
    else
        cout << cycle_cnt << endl;
}