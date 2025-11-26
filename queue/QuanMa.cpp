#include <bits/stdc++.h>
#define ll long long
using namespace std;

int rX(string s)
{
    return ((int)s[0] - 'a' + 1);
}
int rY(string s)
{
    return ((int)s[1] - '0');
}

bool check(int a, int b)
{
    if (a < 1 || b < 1 || a > 8 || b > 8)
        return false;
    return true;
}

vector<pair<int, int>> temp = {
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void bfs(int a, int b, int x, int y)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(9, vector<int>(9, -1));
    vector<vector<int>> visited(9, vector<int>(9, 0));

    q.push({a, b});
    dist[a][b] = 0;

    while (!q.empty())
    {
        auto [dx, dy] = q.front();
        q.pop();
        if (dx == x && dy == y)
            break;
        for (auto [u, v] : temp)
        {
            int nx = dx + u;
            int ny = dy + v;
            if (check(nx, ny) && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[dx][dy] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[x][y] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int a = rX(s1), b = rY(s1), x = rX(s2), y = rY(s2);
        // cout << a << b << " " << x << y << endl;
        bfs(a, b, x, y);
    }
}