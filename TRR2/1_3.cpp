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
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
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
    else if (t == 2)
    {
        int m = edgeList.size();
        cout << n << " " << m << "\n";

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (edgeList[j].first == i || edgeList[j].second == i)
                {
                    cout << 1 << " ";
                }
                else
                {
                    cout << 0 << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}