#include <bits/stdc++.h>
#define ll long long
#define MAX 20000
using namespace std;

void solve(int s, int t)
{
    if (s >= t)
    {
        cout << s - t << endl;
        return;
    }

    vector<int> dist(MAX + 1, -1);
    // vector<int> parent(MAX + 1, -1);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (x == t)
            break;
        int y = x - 1;
        if (y >= 0 && dist[y] == -1)
        {
            dist[y] = dist[x] + 1;
            q.push(y);
        }

        y = x * 2;
        if (y <= MAX && dist[y] == -1)
        {
            dist[y] = dist[x] + 1;
            q.push(y);
        }
    }
    cout << dist[t] << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        solve(s, t);
    }
}