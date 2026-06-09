#include <bits/stdc++.h>
using namespace std;

int t, n;
int deg[105];
vector<pair<int, int>> edgeList;

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
            if (i < x)
                edgeList.push_back({i, x});
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
        cout << n << " " << edgeList.size() << endl;
        for (auto x : edgeList)
        {
            cout << x.first << " " << x.second << endl;
        }
    }

    return 0;
}