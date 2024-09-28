#include <bits/stdc++.h>
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 1e6 + 7;
const double eps = 1e-8;
const int N = 110;
int n, m;
int f[N][N]; // 前i个里面选取j个的最小不齐值 

void solve()
{
    cin >> n >> m;
    m = n - m; // 从前n中选n-m本 
    vector<PII> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a.begin() + 1, a.end());
    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= n; i++)
        f[i][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(i, m); j++)
        {
            for (int k = j - 1; k < i; k++)
            {
                f[i][j] = min(f[i][j], f[k][j - 1] + abs(a[k].se - a[i].se));
            }
        }
    }
    int res = INT_MAX;
    for (int i = m; i <= n; i++)
        res = min(res, f[i][m]);
    cout << res << endl;
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
