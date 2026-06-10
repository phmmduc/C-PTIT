#include <bits/stdc++.h>
using namespace std;

int t, n, u;
int a[105][105];
bool visited[105];
set<int> adj[105];
vector<int> EC;

void DFS(int u)
{
    visited[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if ((a[u][v] == 1 || a[v][u] == 1) && !visited[v])
        {
            DFS(v);
        }
    }
}

bool KiemTraLienThong()
{
    memset(visited, 0, sizeof(visited));
    int start = 0;

    // Tìm đỉnh đầu tiên có chứa cạnh
    for (int i = 1; i <= n && !start; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] || a[j][i])
                start = i;

    // Đồ thị rỗng không có cạnh nào -> Vẫn hợp lệ
    if (!start)
        return true;

    DFS(start);

    // Quét lại: Nếu có đỉnh nào CHƯA THĂM mà lại CÓ CẠNH -> Lỗi liên thông
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            for (int j = 1; j <= n; j++)
                if (a[i][j] || a[j][i])
                    return false;

    return true;
}

void solve1()
{
    if (!KiemTraLienThong())
    {
        cout << 0 << "\n";
        return;
    }
    int start_nodes = 0, end_nodes = 0;
    bool isValid = true;

    for (int i = 1; i <= n; i++)
    {
        int out_deg = adj[i].size(); // Bán bậc ra
        int in_deg = 0;              // Bán bậc vào

        for (int j = 1; j <= n; j++)
            if (a[j][i] == 1)
                in_deg++;

        if (out_deg == in_deg)
            continue;
        else if (out_deg - in_deg == 1)
            start_nodes++;
        else if (in_deg - out_deg == 1)
            end_nodes++;
        else
        {
            isValid = false;
            break;
        }
    }
    if (!isValid)
        cout << 0 << "\n";
    else if (start_nodes == 0 && end_nodes == 0)
        cout << 1 << "\n"; // Chu trình Euler
    else if (start_nodes == 1 && end_nodes == 1)
        cout << 2 << "\n"; // Đường đi Euler
    else
        cout << 0 << "\n";
}

void euler(int v)
{
    while (!adj[v].empty())
    {
        int next_v = *adj[v].begin();

        adj[v].erase(next_v);

        euler(next_v);
    }
    EC.push_back(v);
}

void solve2()
{
    EC.clear();
    euler(u);

    for (int i = EC.size() - 1; i >= 0; i--)
    {
        cout << EC[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> t))
        return 0;

    if (t == 1)
        cin >> n;
    else
        cin >> n >> u;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                adj[i].insert(j);
            }
        }
    }

    if (t == 1)
        solve1();
    else if (t == 2)
        solve2();
}