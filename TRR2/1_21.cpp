#include <bits/stdc++.h>
using namespace std;

int t, n;
int degIn[105], degOut[105];
vector<pair<int, int>> edgeList;
vector<int> W;

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
            if (x != 0 && x != 10000)
            {
                degIn[j]++;
                degOut[i]++;
                edgeList.push_back({i, j});
                W.push_back(x);
            }
        }
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
        cout << n << " " << edgeList.size() << endl;
        for (int i = 0; i < edgeList.size(); i++)
        {
            cout << edgeList[i].first << " " << edgeList[i].second << " " << W[i] << endl;
        }
    }
}