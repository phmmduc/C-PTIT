#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n;
int c[105][105];
int dist_mat[105][105];
int nxt[105][105];

void floyd_warshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist_mat[i][k] != INF && dist_mat[k][j] != INF)
                {
                    if (dist_mat[i][j] > dist_mat[i][k] + dist_mat[k][j])
                    {
                        dist_mat[i][j] = dist_mat[i][k] + dist_mat[k][j];
                        nxt[i][j] = nxt[i][k];
                    }
                }
            }
        }
    }
}

int main()
{
    // freopen("DN.INP", "r", stdin);
    // freopen("DN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if (i == j)
            {
                dist_mat[i][j] = 0;
                nxt[i][j] = -1;
            }
            else if (c[i][j] == 10000)
            {
                dist_mat[i][j] = INF;
                nxt[i][j] = -1;
            }
            else
            {
                dist_mat[i][j] = c[i][j];
                nxt[i][j] = j;
            }
        }
    }

    floyd_warshall();

    int max_d = -1;
    int best_u = -1, best_v = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && dist_mat[i][j] != INF)
            {
                if (dist_mat[i][j] > max_d)
                {
                    max_d = dist_mat[i][j];
                    best_u = i;
                    best_v = j;
                }
            }
        }
    }

    if (max_d == -1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << best_u << " " << best_v << " " << max_d << endl;

        int curr = best_u;
        cout << curr;
        while (curr != best_v)
        {
            curr = nxt[curr][best_v];
            cout << " " << curr;
        }
        cout << endl;
    }

    return 0;
}