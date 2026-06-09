#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<pair<int, int>> edgeList;
int degIn[105], degOut[105];

int main()
{
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        degOut[u]++;
        degIn[v]++;
        edgeList.push_back({u, v});
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
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < edgeList.size(); j++)
            {
                if (edgeList[j].first == i)
                    cout << 1 << " ";
                else if (edgeList[j].second == i)
                    cout << -1 << " ";
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
    }
}