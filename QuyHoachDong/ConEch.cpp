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
        cin >> n;
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }
        cout << dp[n] << endl;
    }
}