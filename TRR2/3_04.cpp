#include <bits/stdc++.h>
using namespace std;

int t, n, u;
int a[105][105];
int deg_vao[105], deg_ra[105];
vector<int> ke[105];
int visited[105];
vector<int> dinh;

void dfs(int x)
{
    visited[x] = 1;
    dinh.push_back(x);
    for (auto y : ke[x])
    {
        if (!visited[y])
        {
            dfs(y);
        }
    }
}

int check_euler()
{
    dfs(1);
    if (dinh.size() != n)
        return 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (abs(deg_vao[i] - deg_ra[i]) == 1)
            cnt++;
    }
    if (cnt == 2)
        return 2;
    if (cnt == 0)
        return 1;
    else
        return 0;
}

void Euler_cycle()
{
    stack<int> st, ce;
    st.push(u);
    while (!st.empty())
    {
        int check = 0;
        int x = st.top();
        for (int i = 1; i <= n; i++)
        {
            if (a[x][i])
            {
                check = 1;
                st.push(i);
                a[x][i] = 0;
                break;
            }
        }
        if (!check)
        {
            st.pop();
            ce.push(x);
        }
    }
    while (!ce.empty())
    {
        cout << ce.top() << " ";
        ce.pop();
    }
}

void nhap()
{
    cin >> t;
    if (t == 1)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (a[i][j])
                {
                    ke[i].push_back(j);
                    ke[j].push_back(i);
                    deg_ra[i]++;
                    deg_vao[j]++;
                }
            }
        }
        cout << check_euler();
    }
    else
    {
        cin >> n >> u;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
            }
        }
        Euler_cycle();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    nhap();
}