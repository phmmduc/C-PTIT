#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<pair<int, int>> edgeList;
int degIn[105], degOut[105];

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
            int x;
            cin >> x;
            if (x == 1)
            {
                degOut[i]++;
                degIn[j]++;
                edgeList.push_back({i, j});
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << "\n";
        }
    }
    else
    {
        cout << n << " " << edgeList.size() << "\n";
        for (auto x : edgeList)
        {
            cout << x.first << " " << x.second << "\n";
        }
    }
}