#include <bits/stdc++.h>
using namespace std;

int t, n;
int degIn[105], degOut[105];
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
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            degIn[x]++;
            degOut[i]++;
            edgeList.push_back({i, x});
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