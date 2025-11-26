#include <bits/stdc++.h>
#define ll unsigned long long
#define fi first
#define se second
using namespace std;
string s1, s2;
int q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> q;
    while (q--)
    {
        cin >> s1 >> s2;
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= s1.size(); i++)
            for (int j = 1; j <= s2.size(); j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        cout << dp[m][n] << endl;
    }
}
