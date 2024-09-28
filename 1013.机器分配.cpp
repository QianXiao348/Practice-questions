#include <bits/stdc++.h> //分组背包+路径记录 
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double eps = 1e-8;
const int N = 1010;
int n, m;
int f[N][N], w[N][N], path[N][N];
void out(int i, int j)
{
    if (i == 0)
        return;
    int k = path[i][j];
    out(i - 1, j - k);
    cout << i << " " << k << endl;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                int val = f[i - 1][j - k] + w[i][k];
                if (f[i][j] <= val)
                {
                    f[i][j] = val;
                    path[i][j] = k;
                }
            }
        }

    cout << f[n][m] << endl;
    out(n, m);
}

int main()
{
//    freopen("in.txt", "rt", stdin);
//    freopen("out.txt", "wt", stdout);
    PASE;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
