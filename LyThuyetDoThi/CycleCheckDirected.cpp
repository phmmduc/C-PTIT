#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int n, m;
vector<int> adj[MAX];

// int inDegree[MAX];
//  bool hasCycleKahn() {
//      queue<int> q;
//      for (int i = 1; i <= n; i++)
//      if (inDegree[i] == 0)
//      q.push(i);

//     int count = 0;
//     while (!q.empty()) {
//         int u = q.front(); q.pop();
//         count++;
//         for (int v : adj[u]) {
//             inDegree[v]--;
//             if (inDegree[v] == 0)
//             q.push(v);
//         }
//     }
//     return (count != n); // nếu không duyệt hết đỉnh -> có chu trình
// }

vector<int> state(MAX, 0);
bool dfs(int u)
{
    state[u] = 1; // đang duyệt
    for (int v : adj[u])
    {
        if (state[v] == 0)
        {
            if (dfs(v))
                return true;
        }
        else if (state[v] == 1)
        {
            return true; // quay lại đỉnh đang duyệt -> chu trình
        }
    }
    state[u] = 2; // duyệt xong
    return false;
}

bool hasCycle()
{
    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0)
        {
            if (dfs(i))
                return true;
        }
    }
    return false;
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
            adj[i].clear();
            state[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
        }
        if (hasCycle())
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}
