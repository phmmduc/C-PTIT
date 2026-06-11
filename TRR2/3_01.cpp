#include <bits/stdc++.h>
using namespace std;

int t, n, start;
int a[105][105];
vector<int> adj[105];
int deg[105];
bool visited[105];
vector<int> dinh;

void dfs(int u)
{
    visited[u] = 1;
    dinh.push_back(u);
    for (auto v : adj[u])
    {
        if (!visited[v])
            dfs(v);
    }
}

int check_euler()
{
    dfs(1);
    if (dinh.size() != n)
        return 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] % 2 == 1)
            cnt++;
    if (cnt == 2)
        return 2;
    if (cnt == 0)
        return 1;
    else
        return 0;
}

void euler_cycle()
{
    stack<int> st, ce;
    st.push(start);
    while (!st.empty())
    {
        int check = 0;
        int x = st.top();
        for (int i = 1; i <= n; i++)
        {
            if (a[x][i])
            {
                check = 1;
                st.push(i);
                a[x][i] = 0;
                a[i][x] = 0;
                break;
            }
        }
        if (!check)
        {
            st.pop();
            ce.push(x);
        }
    }
    while (!ce.empty())
    {
        cout << ce.top() << " ";
        ce.pop();
    }
}

int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;
    if (t == 1)
        cin >> n;
    else
        cin >> n >> start;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                adj[i].push_back(j);
                deg[i]++;
            }
        }
    if (t == 1)
        cout << check_euler();
    else
        euler_cycle();
}