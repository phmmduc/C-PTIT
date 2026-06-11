#include <bits/stdc++.h>
using namespace std;

int n, s, ans;
int a[105][105];
int dist[105];
int par[105];
bool inMST[105];
vector<tuple<int, int, int>> tree;

void prim(int x)
{
    inMST[x] = true;
    while (tree.size() != n - 1)
    {
        int u, v, w = 1e9;
        for (int i = 1; i <= n; i++)
            if (inMST[i])
                for (int j = 1; j <= n; j++)
                    if (a[i][j] != 0 && a[i][j] != 10000 && !inMST[j])
                        if (w > a[i][j])
                        {
                            u = i;
                            v = j;
                            w = a[i][j];
                        }
        ans += w;
        inMST[v] = true;
        tree.push_back({min(u, v), max(u, v), w});
    }
}

int main()
{
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    prim(s);
    cout << ans << endl;
    for (auto [u, v, w] : tree)
        cout << u << " " << v << " " << w << endl;
}