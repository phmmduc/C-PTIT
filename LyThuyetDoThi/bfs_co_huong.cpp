#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> a[1005];
int parent[1005];
bool visited[1005];
bool found;

void input()
{
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        a[i].clear();
        visited[i] = false;
        parent[i] = -1;
    }
    found = false;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

bool bfs(int s, int t) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto v : a[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);

                if (v == t)
                    return true; // gặp t thì dừng
            }
        }
    }
    return false; // không tìm thấy
}

void find()
{
    if (!bfs(s,t))
    {
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    for (int i = t; i != -1; i = parent[i])
        path.push_back(i);
    reverse(path.begin(), path.end());
    for (auto x : path)
        cout << x << " ";
    cout << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        input();
        find();
        // for (int i = 1; i < n; i++)
        // {
        //     cout << i << ": ";
        //     for (auto x : a[i])
        //         cout << x << " ";
        //     cout << endl;
        // }
    }
}