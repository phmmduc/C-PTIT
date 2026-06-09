#include <bits/stdc++.h>
using namespace std;

int t, n;
int a[105][105];
int deg[105];
vector<pair<int, int>> edgeList;

int main()
{
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0 && a[i][j] != 10000)
            {
                deg[i]++;
                if (i < j)
                {
                    edgeList.push_back({i, j});
                }
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << deg[i] << " ";
        }
    }
    else
    {
        cout << n << " " << edgeList.size() << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] != 0 && a[i][j] != 10000 && i < j)
                {
                    cout << i << " " << j << " " << a[i][j] << endl;
                }
            }
        }
    }
}