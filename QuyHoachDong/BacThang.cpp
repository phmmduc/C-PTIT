#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int q;
ll n, k;
ll dp[100005];
int main()
{
    cin >> q;
    while (q--)
    {
        cin >> n >> k;
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = 0;
            for (int j = 1; j <= k && j <= i; j++)
            {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
        cout << dp[n] << endl;
    }
}