#include <bits/stdc++.h> //单调队列优化dp
using namespace std;
#define PASE cin.tie(0), ios::sync_with_stdio(false);
#define fi first
#define se second
typedef long long LL;
typedef pair<int, int> PII;
const int dx[] = {-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int INF = 0x3f3f3f3f;
const int MOD = 10000007;
const double eps = 1e-8;
const int N = 210;
int f[N], a[N][N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            cin >> a[i][j];
            f[i] = 1e9;
        }
    for (int i = n - 1; i; i--)
        for (int j = i + 1; j <= n; j++)
            f[i] = min(f[i], f[j] + a[i][j]);
    cout << f[1];
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
