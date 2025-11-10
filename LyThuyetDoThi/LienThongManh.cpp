#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> a[1005], r[1005];
bool visited[1005];
stack<int> st;

void dfs1(int u)
{
    visited[u] = true;
    for (auto v : a[u])
        if (!visited[v])
            dfs1(v);
    st.push(u);
}

void dfs2(int u)
{
    visited[u] = true;
    for (auto v : r[u])
        if (!visited[v])
            dfs2(v);
}

void KosarajuSCC()
{
    cnt = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs1(i);

    memset(visited, 0, sizeof(visited));
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            cnt++;
            dfs2(u);
        }
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            a[i].clear();
            r[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x].push_back(y);
            r[y].push_back(x);
        }
        KosarajuSCC();
        if (cnt == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}