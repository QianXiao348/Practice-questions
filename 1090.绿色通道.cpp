#include <bits/stdc++.h> //单调队列优化dp+二分 
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
const int N = 5e4 + 10;
int n, m;
int a[N];
int f[N];
int q[N], hh, tt;
bool check(int x)
{
    hh = 0, tt = -1;
    q[++tt] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (hh <= tt && i - q[hh] - 1 > x)
            hh++;
        f[i] = f[q[hh]] + a[i];
        while (hh <= tt && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }
    int res = INT_MAX;
    for (int i = n - x; i <= n; i++)
        res = min(res, f[i]);
    return res <= m;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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
