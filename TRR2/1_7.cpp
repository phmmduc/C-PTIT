#include <bits/stdc++.h>
using namespace std;

int t, n;
int deg[105];
int a[105][105];

int main()
{
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n;

    for (int i = 1; i <= n; i++)
    {
        int k, x;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            cin >> x;
            a[i][x] = 1;
            deg[i]++;
        }
    }

    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << deg[i] << " ";
        cout << endl;
    }
    else
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}