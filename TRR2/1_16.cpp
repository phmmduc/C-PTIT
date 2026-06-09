#include <bits/stdc++.h>
using namespace std;

int t, n, m;
vector<int> edgeList[105];
int degIn[105], degOut[105];
int a[105][105];

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
        edgeList[u].push_back(v);
        a[u][v] = 1;
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }
    else
    {
        cout << n << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << edgeList[i].size() << " ";
            for (int j = 0; j < edgeList[i].size(); j++)
            {
                cout << edgeList[i][j] << " ";
            }
            cout << endl;
        }
    }
}